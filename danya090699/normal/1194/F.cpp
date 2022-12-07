#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e5+10, mod=1e9+7;
int fact[sz], rev[sz], st[sz];
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
int f(int k, int n)
{
    if(k==0) k=n;
    return (((fact[n]*rev[n-k])%mod)*rev[k])%mod;
}

main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin>>n>>t;
    int ar[n+1], su=0, an=0;
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    ar[n]=t*2;
    fact[0]=1, rev[0]=1, st[0]=1;
    for(int a=1; a<=n; a++)
    {
        fact[a]=(fact[a-1]*a)%mod;
        rev[a]=po(fact[a], mod-2);
        st[a]=(st[a-1]*2)%mod;
    }
    for(int a=0; a<=n; a++)
    {
        int cu=0;
        for(int i=0; i<2; i++)
        {
            int l=max(0ll, (t-su-(ar[a]+i))+1);
            int r=min(a, t-su);
            int pr=0;
            if(l<=r)
            {
                if(l==0 and r==a) pr=st[a];
                else
                {
                    for(l; l<=r; l++) pr=(pr+f(l, a))%mod;
                }
            }



            pr=(pr*po(st[a], mod-2))%mod;
            pr=(pr*po(2, mod-2))%mod;
            cu=(cu+pr)%mod;

            //if(a==1) cout<<cu<<" "<<po(4, mod-2)<<"\n";
        }
        an=(an+cu*a)%mod;
        if(a<n) su+=ar[a];
    }
    cout<<an;
}