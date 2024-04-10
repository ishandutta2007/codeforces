#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, add=0;
    cin>>n;
    int ar[n+2], w[n+2];
    ar[0]=0, w[0]=0, ar[n+1]=n+1, w[n+1]=0;
    for(int a=1; a<=n; a++) scanf("%lld", &ar[a]);
    for(int a=1; a<=n; a++) scanf("%lld", &w[a]);
    int m;
    cin>>m;
    int ar2[m+2];
    ar2[0]=0, ar2[m+1]=n+1;
    for(int a=1; a<=m; a++) scanf("%lld", &ar2[a]);
    vector <pair <int, int> > dp[m+2], pref[m+2];
    for(int a=0; a<=m+1; a++)
    {
        dp[a].push_back({-1, inf});
        pref[a].push_back({-1, 0});
    }
    for(int a=0; a<=n+1; a++)
    {
        int p=lower_bound(ar2, ar2+m+2, ar[a])-ar2;
        if(ar[a]==ar2[p]) dp[p].push_back({a, 0});
        if(w[a]<0) add+=w[a];
        else pref[p].push_back({a, pref[p].back().second+w[a]});
    }
    for(int a=1; a<=m+1; a++)
    {
        int dpyk=0, prefyk=0;
        for(int b=1; b<dp[a].size(); b++)
        {
            while(dpyk+1<dp[a-1].size() and dp[a-1][dpyk+1].first<dp[a][b].first) dpyk++;

            while(prefyk+1<pref[a].size() and pref[a][prefyk+1].first<dp[a][b].first) prefyk++;

            if(dp[a-1][dpyk].second!=inf)
            {
                dp[a][b].second=dp[a-1][dpyk].second+pref[a][prefyk].second;
                if(w[dp[a][b].first]<0) dp[a][b].second-=w[dp[a][b].first];
            }
            else dp[a][b].second=inf;

            dp[a][b].second=min(dp[a][b].second, dp[a][b-1].second);
        }
    }
    if(dp[m+1][1].second!=inf)
    {
        cout<<"YES\n"<<dp[m+1][1].second+add;
    }
    else cout<<"NO";
}