#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <int> sv[sz];
int an, dp[sz];
void dfs(int v, int pr)
{
    dp[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            if(dp[v]) an=max(an, dp[v]+dp[ne]+int(sv[v].size())-1);
            dp[v]=max(dp[v], dp[ne]);
        }
    }
    if(dp[v]==0) dp[v]=1;
    else
    {
        dp[v]+=sv[v].size();
        if(pr!=-1) dp[v]--;
    }
    an=max(an, dp[v]);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin>>q;
    while(q)
    {
        q--;
        int n;
        scanf("%d", &n);
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d",&u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        an=0, dfs(0, -1);
        printf("%d\n", an);
        for(int a=0; a<n; a++) sv[a].clear();
    }
}