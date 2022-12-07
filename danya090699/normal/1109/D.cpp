#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, sz=1e6+10;
int fact[sz], rfact[sz], stm[sz], stn[sz];
int c(int n, int k)
{
    int re=(fact[n]*rfact[n-k])%mod;
    re=(re*rfact[k])%mod;
    return re;
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(re*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=1, an=0;
    cin>>n>>m;

    fact[0]=1, rfact[0]=1, stm[0]=1, stn[0]=1;
    for(int a=1; a<sz; a++)
    {
        fact[a]=(fact[a-1]*a)%mod;
        rfact[a]=po(fact[a], mod-2);
        stm[a]=(stm[a-1]*m)%mod;
        stn[a]=(stn[a-1]*n)%mod;
    }

    for(int a=1; a<=min(n-1, m); a++)
    {
        int add=(c(m-1, a-1)*q)%mod;

        //cout<<add<<" ";

        int k=n-a;

        if(k>1)
        {
            add=(add*(a+1))%mod;
            add=(add*stn[k-2])%mod;
        }

        //cout<<add<<" ";

        add=(add*stm[n-1-a])%mod;

        q=(q*(n-1-a))%mod;

        an=(an+add)%mod;
    }
    cout<<an;
}