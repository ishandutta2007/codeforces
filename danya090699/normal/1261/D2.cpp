#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=2e5+10;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int fact[sz], rev[sz], st2[sz], stk[sz];
int C(int n, int k)
{
    return (1ll*((1ll*fact[n]*rev[n-k])%mod)*rev[k])%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    int x=1, q=0, su=0;
    for(int a=0; a<n; a++)
    {
        if(ar[a]==ar[(a+1)%n]) x=(1ll*x*k)%mod;
        else q++;
    }
    fact[0]=1, rev[0]=1, st2[0]=1, stk[0]=1;
    for(int a=1; a<=n; a++)
    {
        fact[a]=(1ll*fact[a-1]*a)%mod;
        rev[a]=po(fact[a], mod-2);
        st2[a]=(st2[a-1]*2)%mod;
        stk[a]=(1ll*stk[a-1]*(k-2))%mod;
    }

    for(int a=0; a<=q; a++)
    {
        int add=(1ll*C(q, q-a)*stk[q-a])%mod;

        int x=st2[a];
        if(a%2==0)
        {
            x-=C(a, a/2);
            if(x<0) x+=mod;
        }
        x=(1ll*x*po(2, mod-2))%mod;

        //cout<<a<<" "<<add<<" "<<x<<"\n";

        su=(su+1ll*x*add)%mod;
    }
    //cout<<q;
    cout<<(1ll*x*su)%mod;
}