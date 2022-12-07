#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, k;
    cin>>n>>p>>k;
    pair <int, int> sup[n];
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &sup[a].first);
        sup[a].second=a;
    }
    sort(sup, sup+n);
    reverse(sup, sup+n);
    int pl[n][p];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<p; b++) scanf("%lld", &pl[a][b]);
    }
    int dp[1<<p], dp2[1<<p];
    for(int a=0; a<(1<<p); a++) dp[a]=-inf, dp2[a]=-inf;
    dp[0]=0;
    for(int a=0; a<n; a++)
    {
        for(int mask=0; mask<(1<<p); mask++)
        {
            if(dp[mask]!=-inf)
            {
                for(int i=0; i<p; i++)
                {
                    if((mask&(1<<i))==0)
                    {
                        dp2[mask+(1<<i)]=max(dp2[mask+(1<<i)], dp[mask]+pl[sup[a].second][i]);
                    }
                }
                if(a-__builtin_popcountll(mask)<k) dp2[mask]=max(dp2[mask], dp[mask]+sup[a].first);
                else dp2[mask]=max(dp2[mask], dp[mask]);
            }
        }
        for(int mask=0; mask<(1<<p); mask++) dp[mask]=dp2[mask], dp2[mask]=-inf;
    }
    cout<<dp[(1<<p)-1];
}