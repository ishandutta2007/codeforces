#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int l, int r, int k)
{
    return (l+r)*((r-l)/k+1)/2;
}
int de(int a, int b){return a/b+(a%b>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int m, mod, b, os=0, an=0, rg=0;
    cin>>m>>mod>>b;
    while(rg<=m)
    {
        an+=de(rg-os, mod)*(m-rg+1);
        int r=rg+(os-rg%mod), l=m-(m%mod-os);
        if(r<rg) r+=mod;
        if(l>m) l-=mod;
        r=m-r+1, l=m-l+1;
        if(l<=r) an+=f(l, r, mod);
        os-=b%mod;
        if(os<0) os+=mod;
        rg=max(rg, os+b);
        if(os==0) break;
    }
    cout<<an;
}