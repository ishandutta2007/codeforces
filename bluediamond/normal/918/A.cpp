#include <iostream>
using namespace std;
const int nmax=1000;
int fib[nmax+5],y,F[nmax+5];
int main()
{
    int n;
    cin>>n;
    fib[1]=fib[2]=1;
    y=2;
    while(fib[y]+fib[y-1]<=nmax)
    {
        y++;
        fib[y]=fib[y-1]+fib[y-2];
    }
    for(int i=1;i<=y;i++)
        F[fib[i]]=1;
    for(int i=1;i<=n;i++)
    {
        if(F[i])
            cout<<"O";
        else
            cout<<"o";
    }
    return 0;
}