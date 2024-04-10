#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int sum(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
inline int dif(int a, int b)
{
    return (a-b>=0) ? a-b : a-b+mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, pr=0, an=0;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    for(int d=ar[n-1]/(k-1); d; d--)
    {
        int dp[n+1][k+1], pref[k+1], yk=0, cu=0;
        for(int a=0; a<=k; a++) dp[0][a]=0, pref[a]=0;
        dp[0][0]=1, pref[0]=1;
        for(int a=1; a<=n; a++)
        {
            while(ar[yk]+d<=ar[a-1])
            {
                for(int b=0; b<=k; b++) pref[b]=sum(pref[b], dp[yk+1][b]);
                yk++;
            }
            for(int b=0; b<=k; b++)
            {
                if(b) dp[a][b]=pref[b-1];
                else dp[a][b]=0;
            }
            cu=sum(cu, dp[a][k]);
        }
        cu=dif(cu, pr);
        pr=sum(pr, cu);
        an=(an+1ll*d*cu)%mod;
    }
    cout<<an;
}