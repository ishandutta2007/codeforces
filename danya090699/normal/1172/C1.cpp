#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int sum(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
inline int dif(int a, int b)
{
    return (a-b<0) ? a-b+mod : a-b;
}
inline int mul(int a, int b)
{
    return (1ll*a*b)%mod;
}
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
inline int del(int a, int b)
{
    return (1ll*a*po(b, mod-2))%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ar[n], w[n], good=0, bad=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<n; a++)
    {
        scanf("%d", &w[a]);
        if(ar[a]) good=sum(good, w[a]);
        else bad=sum(bad, w[a]);
    }
    for(int a=0; a<n; a++)
    {
        int dp[m+1][m+1][m+1], x=-1;
        if(ar[a]) x=1;

        for(int q=0; q<=m; q++) for(int cu=0; cu<=m; cu++) for(int g=0; g<=m; g++) dp[q][cu][g]=0;

        dp[0][0][0]=1;

        int cur=w[a], gq=good, bq=bad;

        if(ar[a]) gq=dif(gq, w[a]);
        else bq=dif(bq, w[a]);

        for(int q=0; q<m; q++)
        {
            for(int cu=0; cu<=q; cu++)
            {
                for(int g=0; g+cu<=q; g++)
                {
                    int val=dp[q][cu][g];
                    if(val)
                    {
                        int b=q-cu-g, pr, su=gq+bq+cur+g-b+x*cu;


                        pr=del(cur+x*cu, su);
                        if(pr) dp[q+1][cu+1][g]=sum(dp[q+1][cu+1][g], mul(val, pr));

                        pr=del(gq+g, su);
                        if(pr) dp[q+1][cu][g+1]=sum(dp[q+1][cu][g+1], mul(val, pr));

                        pr=del(bq-b, su);
                        if(pr) dp[q+1][cu][g]=sum(dp[q+1][cu][g], mul(val, pr));
                    }
                }
            }
        }

        int an=0;
        if(x==-1) x=mod-1;
        for(int cu=0; cu<=m; cu++)
        {
            for(int g=0; g+cu<=m; g++)
            {
                an=sum(an, mul(dp[m][cu][g], sum(cur, mul(x, cu))));
            }
        }

        printf("%d\n", an);
    }
}