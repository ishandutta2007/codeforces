#include <iostream>
using namespace std;
int main()
{
    char s1,s2;
    int n,n1,n2;
    s1=cin.get();
    cin.get();
    s2=cin.get();
    n1=3;
    if(s1=='v')
        n1=0;
    if(s1=='<')
        n1=1;
    if(s1=='^')
        n1=2;
    n2=3;
    if(s2=='v')
        n2=0;
    if(s2=='<')
        n2=1;
    if(s2=='^')
        n2=2;
    cin>>n;
    n%=4;
    int ex1,ex2,i;
    ex1=n1;
    ex2=n1;
    for(i=1;i<=n;i++)
        if(ex1==0)
        {
            ex1=3;
            continue;
        }
        else
        ex1--;
    for(i=1;i<=n;i++)
        if(ex2==3)
        {
            ex2=0;
            continue;
        }
        else
        ex2++;
    if(ex1==n2 and ex2!=n2)
        cout<<"ccw";
    else
    if(ex2==n2 and ex1!=n2)
        cout<<"cw";
    else
        cout<<"undefined";
    return 0;
}