#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10;
vector <pair <int, int> > sv[sz];
int bq[sz], dp[sz], an=0;
void dfs(int v, int pr)
{
    dp[v]=bq[v];
    an=max(an, dp[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, l=sv[v][a].second;
        if(ne!=pr)
        {
            dfs(ne, v);
            an=max(an, dp[v]-l+dp[ne]);
            dp[v]=max(dp[v], dp[ne]-l+bq[v]);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &bq[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v, w;
        scanf("%lld%lld%lld", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
        sv[v].push_back({u, w});
    }
    dfs(0, 0);
    cout<<an;
}