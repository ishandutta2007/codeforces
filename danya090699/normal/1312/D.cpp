#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=2e5+10;
int fact[sz], rev[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
int c(int n, int k)
{
    return 1ll*rev[k]*(1ll*fact[n]*rev[n-k]%mod)%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    fact[0]=1, rev[0]=1;
    for(int a=1; a<=m; a++)
    {
        fact[a]=1ll*fact[a-1]*a%mod;
        rev[a]=po(fact[a], mod-2);
    }
    int an=1ll*c(m, n-1)*(n-2)%mod;
    for(int a=0; a<n-3; a++) an=(an*2)%mod;
    cout<<an;
}