#include<bits/stdc++.h>
using namespace std;
void create(int x)
{
    if(x>=0 && x<=4 )
    {
        cout<<"O-|";
        for(int i=1;i<=5;i++)
        {
            if(i==x+1)cout<<"-";
            else cout<<"O";
        }
    }
    else
    {
        cout<<"-O|";
        for(int i=1;i<=5;i++)
        {
            if(i==x-4)cout<<"-";
            else cout<<"O";
        }
    }
}
int main()
{
    long int n;
    cin>>n;
    if(n==0)
    {
        create(0);return 0;
    }
    while(n!=0)
    {
        create(n%10);
        cout<<"\n";
        n/=10;
    }
    return 0;// case of zero is important in maany cases.....
}