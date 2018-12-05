#include<iostream>
#include<conio.h>
#include<ctype.h>
using namespace std;
int Num=0,chance=2,flag=0,num=0;
int gamechoice,numtoadd=0;
char lastchoice,p1[20],p2[20],first[20],second[20];

void AIlogic();
void Double_player();
void Single_player();
void Exit();

void cutted()
{
    for(int i=0; i<20; i++)
    {
        p1[i]= toupper(p1[i]);
        p2[i]=toupper(p2[i]);
    }
}
void add(int num)
{
    Num+=num;
    cout << "\nThe number turns to " <<Num<< endl;
    getch();
}
void End()
{
    clrscr();
    if(chance==2)
        cout<<first<<" Wins the game\n";
    else
        cout<<second<<" Wins the game\n";
    getch();
    Exit();
}
void intro()
{   clrscr();
    cout<<"\nThe game is based upon a simple logic."
        <<"\nYou have given a number with initial value zero"
        <<"\nYou can choose any number between 1 to 9 to add in it."
        <<"\nThe player who will reach 100 First will win the game!\nHope you will Enjoy! Best of luck to you!";
    getch();
}
void intro1()
{
    cout<<"\n Enter Your Name:-";
    cin>>p1;
    //p2[9]="Computer";
}
void intro2()
{
    cout<<"\nWelcome both of you\nEnter name of First player\n";
    cin>>p1;
    cout<<"\nEnter name of second player\n";
    cin>>p2;

    getch();
}
void intro10()
{
    cout<<"\nThis match is between  you and Computer. Firstly you will have toss and then match as per the rules told earlier so be ready. And Have FUN!!\n";
}

void toss()
{
    int toss;
    cutted();
    cout<<"Lets have a toss "<<p1<<" choose \n1:- Head\n2:- Tail\n";
    cin>>toss;
    //randomize();
    int toss2=random()%2;
    if(gamechoice==2)
    {
        if(toss==toss2+1)
        {
            strcpy(first,p1);
            strcpy(second,p2);
        }
        else
        {
            strcpy(first,p2);
            strcpy(second,p1);
        }
        cout<<endl<<first<<" wins the toss\n";
    }
    if(gamechoice==1)
    {
        if(toss==toss2+1)
            strcpy(first,p1);
        else
        {   strcpy(second,p1);
            strcpy(first,"Computer");
        }

        cout<<endl<<first<<" wins the toss\n";
        if(!strcmp(first,"Computer"))
            flag=123;
    }
    getch();
}
void Exit()
{
    cout<<"\nThank you for playing\nThe game is ending\n";
    getch();
}
int check()
{
    if(Num>=100)
        End();
    else
        return 1;
}


int main()
{
label1:
    clrscr();
    intro();
    cout<<"\nChoose one option\n"
        "1:-Single Player\n"
        "2:-Double Player\n"
        "3:-Exit Game\n";
    cin>>gamechoice;
    switch(gamechoice)
    {
    case 1:
        Single_player();
        break;
    case 2:
        Double_player();
        break;
    case 3:
        Exit();
        return 0;
        break;
    default:
        cout<<"\nWrong Choice you can choose again\n";
        goto label1;
    }
    clrscr();
    cout<<"Do you want to continue? (y/n)\n";
    cin>>lastchoice;
    if(lastchoice=='y'||lastchoice=='Y')
    {
        goto label1;
    }
    else
        Exit();
    return 0;
}
void Double_player()
{
    clrscr();
    intro();
    intro2();
    toss();
    do {
        cout<<endl<<first<<" This is your chance\n";
l1:
        cout<<"Enter the number you want to add to "<<Num<<" from 1 to 9"<<endl;
        cin>>num;
        if(num>9)
        {
            cout<<"You must Enter number between 0 to 9\n";
            goto l1;
        }
        add(num);
        if(Num>=100)
            goto last;

        cout<<endl<<second<<" This is your chance\n";
l2:
        cout<<"Enter the number you want to add to "<<Num<<endl;
        cin>>num;
        if(num>9)
        {
            cout<<"You must Enter number between 0 to 9\n";
            goto l2;
        }
        add(num);
        if(Num>=100)
            goto last;
    }
    while(Num<100);
last:
    check();
}

void Single_player()
{
    intro();
    intro10();
    intro1();
    toss();

    if(flag==123)
    {
        do {
            AIlogic();
            cout<<"\nThis is Computer's chance \nComputer will add "<<num<<" to "<<Num;
            add(num);
            if(Num>=100)
                goto last1;

            cout<<endl<<second<<" This is your chance\n";
l3:
            cout<<"Enter the number you want to add to "<<Num<<endl;
            cin>>num;
            if(num>9)
            {
                cout<<"You must Enter number between 0 to 9\n";
                goto l3;
            }
            add(num);
            if(Num>=100)
                goto last1;
        }
        while(Num<100);
last1 :
        check();
    }
    else
    {
        do {
            cout<<endl<<first<<" This is your chance\n";
l4:
            cout<<"Enter the number you want to add to "<<Num<<endl;
            cin>>num;
            if(num>9)
            {
                cout<<"You must Enter number between 0 to 9\n";
                goto l4;
            }
            add(num);
            if(Num>=100)
                goto last2;

            AIlogic();
            cout<<"\nThis is Computer's chance \nnComputer will add "<<num<<" to "<<Num;
            add(num);
            if(Num>=100)
                goto last2;
        } while(Num<100);
last2:
        check();
    }
}
void AIlogic()
{
    if(Num>=91)
        num=100-Num;
    else if(Num>=81)
        num=90-Num;
    else if(Num>=71)
        num=80-Num;
    else if(Num>= 61)
        num=70-Num;
    else if(Num>=51)
        num=60-Num;
    else if(Num>=41)
        num=50-Num;
    else if(Num>=31)
        num=40-Num;
    else if(Num>=21)
        num=30-Num;
    else if(Num>=11)
        num=20-Num;
    else if(Num>1)
        num=10-Num;
    else num=1;
}
