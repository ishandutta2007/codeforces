#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, ok=0;
    cin>>n>>p;
    char ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<p; a++)
    {
        int q0=0, q1=0, qt=0;
        for(int b=a; b<n; b+=p)
        {
            if(ar[b]=='0') q0++;
            if(ar[b]=='1') q1++;
            if(ar[b]=='.') qt++;
        }
        char sy='0';
        if(qt)
        {
            if(q0>0)
            {
                sy='1', ok=1;
            }
            else if(q1>0)
            {
                sy='0', ok=1;
            }
            else if(qt>1)
            {
                ar[a]='1', ar[a+p]='0', ok=1;
            }
        }
        else
        {
            if(q0!=0 and q1!=0) ok=1;
        }
        for(int b=a; b<n; b+=p) if(ar[b]=='.') ar[b]=sy;
    }
    if(ok)
    {
        for(int a=0; a<n; a++) cout<<ar[a];
    }
    else cout<<"No";
}