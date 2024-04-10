#include <bits/stdc++.h>
using namespace std;
const int nmax=100000,inf=1000000000;
int n,v[nmax+5],p[nmax+5];
int best0[nmax+5],best1[nmax+5];
int f(int a,int b,int c)
{
    return max(a,max(b,c));
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        p[i]=abs(v[i])%2;
    }
    best0[0]=best1[0]=-2*inf;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==0)
        {
            best0[i]=f(best0[i-1],best0[i-1]+v[i],v[i]);
            best1[i]=f(best1[i-1],best1[i-1]+v[i],-2*inf);
        }
        if(p[i]==1)
        {
            best0[i]=f(best0[i-1],best1[i-1]+v[i],-2*inf);
            best1[i]=f(best1[i-1],v[i],best0[i-1]+v[i]);
        }
    }
    cout<<best1[n];
    return 0;
}
/**
**/