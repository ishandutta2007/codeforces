#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10, mod=998244353;
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
int f[sz], rev[sz];
int c(int n, int k)
{
    return 1ll*(1ll*f[n]*rev[n-k]%mod)*rev[k]%mod;
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
    int n, k, an=0;
    cin>>n>>k;
    for(int a=1; a<=n; a++)
    {
        if(k-1<=n/a-1)
        {
            an=(an+c(n/a-1, k-1))%mod;
        }
    }
    cout<<an;
}