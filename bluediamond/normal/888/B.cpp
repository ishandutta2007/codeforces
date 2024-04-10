#include <iostream>
#include <algorithm>
using namespace std;
int n,L,R,U,D;
char ch;
int main()
{
    cin>>n;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        if(ch=='L')L++;
        if(ch=='D')D++;
        if(ch=='U')U++;
        if(ch=='R')R++;
    }
    cout<<n-abs(D-U)-abs(L-R);
    return 0;
}
/**
corect:
U=D
L=R
**/