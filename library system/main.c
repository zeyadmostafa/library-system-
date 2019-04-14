#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
typedef struct SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
} systime;
systime str_t;
typedef struct
{
    int day, month, year ;
} dates;
typedef struct
{
    int building;
    char street[30];
    char city[30];
} address;
typedef struct
{
    char title[50];
    char author[50];
    char publisher[50];
    char isbn[30];
    dates publication_date;
//char date_of_publication[40];
    char category[40];
    int number_of_copies;
   int availble_number ;
   int bcount;
} books;
int nbook=0;
books book[100];
typedef struct
{
    char fname[40];//first and last
    char lname[40];
    int id ;
    address date;
    char phone_number[15];
    int age;
    char email[40];
} members;
int nmember=0;
members member[100];
typedef struct
{
    char isbn[50];
    int id;
    dates borrowed_date;
    dates due_date;
    dates returned_date;
    /*char date_borrowed[20];
    char date_due_return[20];
    char date_returned[20];*/
} borrowed;
int nborrow=0;
borrowed borrow[100];
void insert_new_book()
{
    int n=0,i,j=0;
    char test[30];
    printf("please enter book ISBN to check if there is an existing copy\n");
    scanf("%[^\t\n]s",test);

    while (j!=100)
    {
        if (strcmp(book[j].isbn,test)==0)
        {
            printf("this book already exist\n");
            return;

        }
        j++;
    }


    strcpy(book[nbook].isbn,test);
    printf("Book Does Not Exist Please Enter Book Info.\n");
    printf("Enter Book Title\n");
    scanf(" %[^\t\n]s\n",book[nbook].title);
    printf("Enter Book Author\n");
    scanf(" %[^\t\n]s\n",book[nbook].author);
    printf("Enter Book Publisher\n");
    scanf(" %[^\t\n]s\n",book[nbook].publisher);
    printf("Enter Book Publication Date In Day/Month/Year\n");
    scanf("%d%d%d",&book[nbook].publication_date.day,&book[nbook].publication_date.month,&book[nbook].publication_date.year);
    printf("enter book category\n");
    scanf(" %[^\t\n]s\n",book[nbook].category);
    printf("enter number of copies\n");
    scanf("%d",&book[nbook].number_of_copies);
         book[nbook].availble_number=book[nbook].number_of_copies;
  book[nbook].bcount=0;
    nbook++;


    }

void array_file()
{
    FILE *pt2;
    pt2=fopen("E:\\New folder\\books.txt","r");

    while(!feof(pt2))
    {

        fscanf(pt2,"%[^,],%[^,],%[^,],%[^,],%d/%d/%d,%[^,],%d,%d,%d\n",book[nbook].title,book[nbook].author,book[nbook].publisher,book[nbook].isbn,&book[nbook].publication_date.day,&book[nbook].publication_date.month,&book[nbook].publication_date.year,book[nbook].category,&book[nbook].number_of_copies,&book[nbook].availble_number,&book[nbook].bcount);
        nbook++;
    }
       // printf("%s",book[nbook-1].title);


//fclose(pt2);

}


void add_new_user()
{
        printf("Enter User First Name Then Last Name\n");
    scanf(" %[^\t\n]s\t",member[nmember].fname);
    scanf(" %[^\t\n]s\n",member[nmember].lname);
    printf("Enter User Id\n");
    scanf("%d",&member[nmember].id);
    printf("Enter User Address \n");
    scanf("%d%s%s",&member[nmember].date.building,member[nmember].date.street,member[nmember].date.city);
    printf("Enter User Phone\n");
    scanf("%s",member[nmember].phone_number);
   // printf("%s\n",member[nmember].phone_number);
    printf("Enter User Age\n");
    scanf("%d",&member[nmember].age);
    printf("Enter User E-mail\n");
    scanf(" %[^\t\n]s\n",member[nmember].email);
     nmember++;
    /*    int fo ;
        printf("Press 1 To SaveSave And 0 For Not Saving\n");
        scanf("%d",&fo);
        if (fo==1)
        {
            fprintf(pt3,"%s,%s,%d,%d,%s,%s,%d,%d,%s\n",member[k].fname,member[k].lname,member[k].id,member[k].date.building,member[k].date.street,member[k].date.city,member[k].phone_number,member[k].age,member[k].email);


        }*/


    //   fclose(pt3);

}
void array_file1()
{

    FILE *pt4;
    pt4=fopen("E:\\New folder\\users.txt","r");

    while(!feof(pt4))
    {

        fscanf(pt4,"%[^,],%[^,],%d,%d,%[^,],%[^,],%[^,],%d,%s\n",member[nmember].fname,member[nmember].lname,&member[nmember].id,&member[nmember].date.building,member[nmember].date.city,member[nmember].date.street,member[nmember].phone_number,&member[nmember].age,member[nmember].email);
        nmember++;
    }
     // printf("%d\n",nmember);

}

int search_isbn()
{
    int t,coo;
    char toto[50];
    printf("enter book isbn \n");
    scanf("%s",toto);
    for(t=0; t<=nbook; t++)
    {
        if (strcmp(book[t].isbn,toto)==0)
        {
            printf("found the book %s\n",book[t].title);
            coo=t;
            return coo;
        }

    }
    printf("that book doesnot exist \n");
    return -1;
}

int search_author()
{
    char soso[50];
    int t, qoo,coo;
    printf("please enter book author\n");
    scanf("%s",soso);

    for (t=0; t<=nbook; t++)
    {

        qoo=strcmp(book[t].author,soso);
        if (qoo==0)
        {
            printf("found the book %s\n",book[t].title);
            coo=t;
            return coo;
        }
        else
        {
            printf("that book doesnot exist \n");
            return -1;
        }


    }
}
void search_category()
{
    char toto[50];
    int t;
    printf("please enter book category\n");
    scanf("%s",toto);
    t=0;
    while (t!=nbook)
    {
        if(strcmp(book[t].category,toto)==0)
        {
            printf("book name is %s and its index =%d\n",book[t].title,t);// in the borrowing function i shoud ask if the user knows the index
        }
        t++;
    }


}
void search_title()
{
    int i=0;
    char search[50];
    char yoo[50];
    printf("enter title or part of it \n");
    scanf("%s",search);
    while(i!=nbook)
    {
        if(strstr(book[i].title,search))
        {
            printf("book title is %s and its index is %d\n",book[i].title,i);
            }
i++;

    }


}

int fsearch()
{
    int lol;
    printf("please enter 0 if you want to search by book's ISBN and 1 for title and 2 for author and 3 for category \n");
    scanf("%d",&lol);
    if (lol==0)
    {
        search_isbn();

    }
    if (lol==2)
    {
        search_author();
    }

    if (lol==3)
    {
        search_category();
    }
    if (lol==1)
    {
        search_title();
    }
}
void fsave()
{
    FILE *pt00;
    int r;
    pt00=fopen("E:\\New folder\\users.txt","w");
    for(r=0; r<nmember; r++)
    {
        fprintf(pt00,"%s,%s,%d,%d,%s,%s,%d,%d,%s\n",member[r].fname,member[r].lname,member[r].id,member[r].date.building,member[r].date.street,member[r].date.city,member[r].phone_number,member[r].age,member[r].email);
    }
    fclose(pt00);


    pt00=fopen("E:\\New folder\\books.txt","w");
    for (r=0; r<nbook; r++)
    {
        fprintf(pt00,"%s,%s,%s,%s,%d/%d/%d,%s,%d,%d,%d\n",book[r].title,book[r].author,book[r].publisher,book[r].isbn,book[r].publication_date.day,book[r].publication_date.month,book[r].publication_date.year,book[r].category,book[r].number_of_copies,book[r].availble_number,book[r].bcount);
    }
    fclose(pt00);
        GetSystemTime(&str_t);

    pt00=fopen("E:\\New folder\\borrowed.txt","w");
    for (r=0; r<nborrow; r++)
    {
        fprintf(pt00,"%s,%d,%d/%d/%d,%d/%d/%d,%d/%d/%d\n",borrow[r].isbn,borrow[r].id,str_t.wDay,str_t.wMonth,str_t.wYear,borrow[r].due_date.day,borrow[r].due_date.month,borrow[r].due_date.year,borrow[r].returned_date.day,borrow[r].returned_date.month,borrow[r].returned_date.year);

    }
    fclose(pt00);
}

void fdelete()
{
    int j;
    j=search_isbn();
    nbook=nbook-1;
    for(j; j<nbook; j++)
    {
        book[j]=book[j+1];

    }

}

int add_copy()
{
    int k,v;
    v=search_isbn();
    printf("enter the new number of copies in the book\n");
    do
    {
        scanf("%d",&k);
    }
    while(k<=0);
    book[v].number_of_copies=book[v].number_of_copies+k;
book[v].availble_number=book[v].availble_number+k;
}


void borrowing()
{
GetSystemTime(&str_t);
    int f,x,i,count=0;
    x=search_isbn();
       printf("available number of copies =  %d\n",book[x].availble_number);
        // printf("%d\n",book[x].number_of_copies);

    if (x>=0)
    {
        strcpy(borrow[nborrow].isbn,book[x].isbn);
    }
    else
    {
        return ;
    }


   // printf("%d\n",book[x].availble_number);
     if(book[x].availble_number<=0){
        printf("no availble copies\n");
        return;}

    f=user_exist();
    borrow[nborrow].id=member[f].id;
     for (i=0;i<nborrow;i++){
    if (borrow[i].id==member[f].id){count++;}
    }
    printf("%d\n",count);
    //printf("%d\n",borrow[nborrow].id);
    if(count>=3){printf("you borrowed 3 books you cant borrow more \n");
    return;
    }
    printf("Enter Due Date\n");
    scanf("%d%d%d",&borrow[nborrow].due_date.day,&borrow[nborrow].due_date.month,&borrow[nborrow].due_date.year);
  borrow[nborrow].returned_date.day=0;
  borrow[nborrow].returned_date.month=0;
  borrow[nborrow].returned_date.year=0;
    book[x].availble_number=book[x].availble_number-1;//availble=0
book[x].bcount=book[x].bcount+1;
nborrow++;

}
void array_file2()
{
    FILE *pt6;
    pt6=fopen("E:\\New folder\\borrowed.txt","r");

    while(!feof(pt6))
    {

        fscanf(pt6,"%[^,],%d,%d/%d/%d,%d/%d/%d,%d/%d/%d\n",borrow[nborrow].isbn,&borrow[nborrow].id,&borrow[nborrow].borrowed_date.day,&borrow[nborrow].borrowed_date.month,&borrow[nborrow].borrowed_date.year,&borrow[nborrow].due_date.day,&borrow[nborrow].due_date.month,&borrow[nborrow].due_date.year,&borrow[nborrow].returned_date.day,&borrow[nborrow].returned_date.month,&borrow[nborrow].returned_date.year);
      //  printf("%s",borrow[nborrow].isbn);
        nborrow ++;
    }
  //  printf("%d",nborrow);
}
int user_exist()
{
    int koo,i;
    printf("enter user id\n");
    scanf("%d",&koo);
    for(i=0; i<=nmember; i++)
    {
        if(member[i].id==koo)
        {
            return i;
        }


    }
}

books temp[100];

void remove_member(){
    int h,i,j;
    printf("to remove a member  ");

h=user_exist();

for(i=0;i<nborrow;i++){
        if (member[h].id==borrow[i].id){
                printf("cant remove member until all borrowed are returned ");
            //returning();
return ;
        }

}
nmember=nmember-1;
for (h;h<nmember;h++){

    member[h]=member[h+1];

}
        printf("member removed \n");

}

void returning(){
GetSystemTime(&str_t);
int h , i , j,f;
printf("for returning a book  ");
f=user_exist();
h=search_isbn();
for(i=0;i<nborrow;i++){
    if(strcmp(book[h].isbn,borrow[i].isbn)==0&&member[f].id==borrow[i].id){
            if (borrow[i].due_date.day>=str_t.wDay&&borrow[i].due_date.month>=str_t.wMonth&&borrow[i].due_date.year>=str_t.wYear){
                printf("thanks for returning in time \n");
            }
            else{printf("you are late !!!\n");}
        book[h].availble_number=book[h].availble_number+1;

    borrow[i].returned_date.day=str_t.wDay;
    borrow[i].returned_date.month=str_t.wMonth;
    borrow[i].returned_date.year=str_t.wYear;


       /*  nborrow=nborrow-1;
            for(j=i;j<nborrow;j++){
                borrow[j]=borrow[j+1];

    }*/
}

}
}

void over_due_book(){
    int i;
    GetSystemTime(&str_t);
//  printf("flag\n");
for(i=0;i<nborrow;i++){
                if (borrow[i].due_date.day<str_t.wDay&&borrow[i].due_date.month<=str_t.wMonth&&borrow[i].due_date.year<=str_t.wYear&&borrow[i].returned_date.day==0){
                    printf("book with ISBN %s has exceeded its due date from user with id %d\n",borrow[i].isbn,borrow[i].id);
                  //  printf("flag\n");
                }

}

}


void popular_books(){
int i , j;
for(i=0;i<nbook;i++){
    strcpy(temp[i].title,book[i].title);
    strcpy(temp[i].author,book[i].author);
    strcpy(temp[i].publisher,book[i].publisher);
    temp[i].number_of_copies=book[i].number_of_copies;
    temp[i].availble_number=book[i].availble_number;
    strcpy(temp[i].category,book[i].category);
    temp[i].bcount=book[i].bcount;
}
for(i=0;i<nbook-1;i++){
    for(j=0;j<nbook-i-1;j++){
        if(book[j].bcount<book[j+1].bcount){
        temp[j]=book[j];
        book[j]=book[j+1];
        book[j+1]=temp[j];
        }

    }

}
printf("top popular books are \n");
for(i=0;i<5&&i<nbook;i++){
    printf("number %d is %s and its ISBN is %s \n",i+1,book[i].title,book[i].isbn);
}


}


void main_menu(){    //?????????????????????????????????????????????????????????????

printf("****************************Please Enter Your Choise****************************\n\n\n");
printf("****************************1:Book Management\n\n");
printf("****************************2:Member Management\n\n");
printf("****************************3:Borrow Management\n\n");
printf("****************************4:Administrative actions\n\n");
printf("****************************5:Save change\n\n");
printf("****************************6:Exit\n\n");
printf("****************************7:Show Data\n\n");
switch(getch())
{

case '1':                             system("cls");
    printf("********1:Insert new book\n\n");
    printf("********2:Search for a book\n\n");
    printf("********3:Add new copies\n\n");
    printf("********4:Delete book\n\n");
    back();
    switch(getch()){
case '1':system("cls");
    insert_new_book();
    back();
    break;
case '2':system("cls");
    fsearch();
    back();
    break;
case '3':system("cls");
    add_copy();
    back();
    break ;
case '4':system("cls");
    fdelete();
    back();
    }

     break;
case '2':                         system("cls");
    printf("********1:For registration\n");
    printf("********2:Delete member\n");
    back();
    switch(getch()){
case '1':system("cls");
    add_new_user();
    back();
    break;
case '2':system("cls");
    remove_member();
    back();

    }

    break;
case '3':                           system("cls");
    printf("********1:Borrowing book\n");
    printf("********2:Return book\n");
    back();
    switch(getch()){
case '1':system("cls");
    borrowing();
    back();
    break ;
case '2':system("cls");
    returning();
    back();
    }

    break;
case '4':                         system("cls");
    printf("********1:Overdue books\n");
    printf("********2:Most popular books\n");
    back();
    switch(getch()){
case '1':system("cls");
    over_due_book();
    back();
    break;
case '2':system("cls");
    popular_books();
back();
    }

    break;
case '5':                         system("cls");
    fsave();
    back();
    break;
case '6':                        system("cls");
    printf("********1:Exit with save\n");
    printf("********2:Exit without saving\n");
    back();
    switch(getch()){
case '1':
    fsave();
    system("cls");
    main_menu();

    break;
case '2':
    system("cls");
    main_menu();
    }
    break;
    case '7':                   system("cls");
    printf("********1:For print list of book\n");
    printf("********2:For print list of members\n");
    printf("********3:For print list of borrowed books\n");
    back();
    switch(getch()){
case '1':system("cls");

    //print book ???????????????????????????????????????????????
    back();
    break;
case '2':system("cls");
    //print members ?????????????????????????????????????????????
    back();
    break;
case '3':system("cls");
    //print borrowed books ??????????????????????????
    back();
}

}





}

void back(){    //?????????????????????????????????????????
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tClick 0 to back to main menu\n");
switch(getch()){
    case '0':
system("cls");
main_menu();
}

}




int main()
{
    int i;
  //  time_t mytime;
 //   mytime = time(NULL);
//    printf(ctime(&mytime));
    array_file();
    array_file1();
    array_file2();
    main_menu();
  //over_due_book();
 //returning();
//popular_books();
//borrowing();
//remove_member();
//add_copy();
//fsearch();
//insert_new_book();
//fdelete();
//search_title();
//add_new_user();
//fsearch();
  //  printf("flag\n");
    //fsave();



    return 0;
}

