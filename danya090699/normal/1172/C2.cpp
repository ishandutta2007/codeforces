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
    int dp[m+1][m+1];
    for(int a=0; a<=m; a++) for(int b=0; b<=m; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<=a; b++)
        {
            if(dp[a][b])
            {
                int gq=sum(good, b), bq=dif(bad, a-b), tot=sum(gq, bq);

                dp[a+1][b+1]=sum(dp[a+1][b+1], mul(dp[a][b], del(gq, tot)));

                dp[a+1][b]=sum(dp[a+1][b], mul(dp[a][b], del(bq, tot)));
            }
        }
    }
    int gadd=0, badd=0;
    for(int a=0; a<=m; a++)
    {
        gadd=sum(gadd, mul(dp[m][a], del(a, good)));

        badd=sum(badd, mul(dp[m][a], del(mod-(m-a), bad)));
    }
    for(int a=0; a<n; a++)
    {
        int add;
        if(ar[a]) add=gadd;
        else add=badd;

        printf("%d\n", sum(w[a], mul(w[a], add)));
    }
}