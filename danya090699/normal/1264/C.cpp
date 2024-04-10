#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=998244353;
int pr[sz], pref[sz];
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
int rev(int x)
{
    return po(x, mod-2);
}
int f(int l, int r)
{
    int su=pref[r];
    if(l)
    {
        su-=pref[l-1];
        if(su<0) su+=mod;
    }
    su=(1ll*su*rev(pr[l]))%mod;
    su=(1ll*su*rev((1ll*pr[r+1]*rev(pr[l]))%mod))%mod;
    return su;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    pr[0]=1, pref[0]=1;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        pr[a+1]=(1ll*x*rev(100))%mod;
        pr[a+1]=(1ll*pr[a+1]*pr[a])%mod;
        pref[a+1]=(pref[a]+pr[a+1])%mod;
    }
    set <int> se;
    se.insert(0);
    se.insert(n);
    int an=f(0, n-1);
    for(int a=0; a<q; a++)
    {
        int p;
        scanf("%d", &p);
        p--;
        auto it=se.find(p);
        if(it==se.end())
        {
            it=se.insert(p).first;
            int pr, ne;
            it--, pr=*it, it++;
            it++, ne=*it, it--;
            an-=f(pr, ne-1);
            if(an<0) an+=mod;
            an=(an+f(pr, p-1))%mod;
            an=(an+f(p, ne-1))%mod;
        }
        else
        {
            int pr, ne;
            it--, pr=*it, it++;
            it++, ne=*it, it--;
            an-=f(pr, p-1);
            if(an<0) an+=mod;
            an-=f(p, ne-1);
            if(an<0) an+=mod;
            an=(an+f(pr, ne-1))%mod;
            se.erase(it);
        }
        printf("%d\n", an);
    }
}