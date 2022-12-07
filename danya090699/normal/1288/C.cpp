#include <bits/stdc++.h>
using namespace std;
const int sz=2e3, mod=1e9+7;
int f[sz], rev[sz];
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
    return 1ll*f[n]*(1ll*rev[n-k]*rev[k]%mod)%mod;
}
main()
{
    f[0]=1, rev[0]=1;
    for(int a=1; a<sz; a++)
    {
        f[a]=1ll*f[a-1]*a%mod;
        rev[a]=po(f[a], mod-2);
    }
    //freopen("input.txt", "r", stdin);
    int n, m, su=0, an=0;
    cin>>n>>m;
    for(int a=1; a<=n; a++)
    {
        su=(su+c(m-1+a-1, a-1))%mod;
        an=(an+1ll*c(m-1+n-a, n-a)*su)%mod;
    }
    cout<<an;
}