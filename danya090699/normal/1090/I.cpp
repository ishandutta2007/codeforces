#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=5e18;
main()
{
    //freopen("input.txt", "r", stdin);
    unsigned int t, mod=(1ll<<32);
    cin>>t;
    while(t)
    {
        t--;
        int n, l, r;
        unsigned int x, y, z, b1, b2;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &n, &l, &r, &x, &y, &z, &b1, &b2);
        unsigned int arb[n];
        arb[0]=b1, arb[1]=b2;
        for(int a=2; a<n; a++) arb[a]=((arb[a-2]*x)%mod+(arb[a-1]*y)%mod+z)%mod;
        int ar[n], mi=inf, an=inf, ma=-inf;
        for(int a=0; a<n; a++)
        {
            ar[a]=arb[a]%(r-l+1)+l;
            int cu=ar[a];
            if(cu>=0)
            {
                if(mi<cu) an=min(an, mi*cu);
            }
            mi=min(mi, cu);
        }
        for(int a=n-1; a>=0; a--)
        {
            int cu=ar[a];
            if(cu<0)
            {
                if(ma>cu) an=min(an, ma*cu);
            }
            ma=max(ma, cu);
        }
        if(an==inf) printf("IMPOSSIBLE\n");
        else printf("%lld\n", an);
    }
}