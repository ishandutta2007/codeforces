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
    return 1ll*(1ll*fact[n]*rev[n-k]%mod)*rev[k]%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    long long k;
    cin>>n>>k;
    if(k>=n)
    {
        cout<<0;
        return 0;
    }
    k=n-k;
    fact[0]=1, rev[0]=1;
    for(int a=1; a<=n; a++)
    {
        fact[a]=1ll*fact[a-1]*a%mod;
        rev[a]=po(fact[a], mod-2);
    }
    int an=0;
    for(int a=0; a<k; a++)
    {
        int add=1ll*c(k, k-a)*po(k-a, n)%mod;
        if(a&1)
        {
            an-=add;
            if(an<0) an+=mod;
        }
        else an=(an+add)%mod;
    }
    an=1ll*an*c(n, k)%mod;
    if(k<n) an=an*2%mod;
    cout<<an;
}