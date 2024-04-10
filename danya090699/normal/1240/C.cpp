#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=5e5+10;
vector <pair <int, int> > sv[sz];
int n, k, dp[sz][2];
void dfs(int v, int pr)
{
    vector <int> sp;
    dp[v][0]=0, dp[v][1]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        if(ne!=pr)
        {
            dfs(ne, v);
            if(dp[ne][0]<dp[ne][1]+w) sp.push_back(dp[ne][1]+w-dp[ne][0]);
            dp[v][0]+=dp[ne][0];
            dp[v][1]+=dp[ne][0];
        }
    }
    sort(sp.begin(), sp.end(), greater <int> ());
    int m=sp.size();
    for(int a=0; a<min(k-1, m); a++) dp[v][1]+=sp[a];
    for(int a=0; a<min(k, m); a++) dp[v][0]+=sp[a];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        scanf("%lld%lld", &n, &k);
        for(int a=0; a<n-1; a++)
        {
            int u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            u--, v--;
            sv[u].push_back({v, w});
            sv[v].push_back({u, w});
        }
        dfs(0, 0);
        printf("%lld\n", dp[0][0]);
        for(int a=0; a<n; a++) sv[a].clear();
    }
}