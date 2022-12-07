#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=4e5+10;
vector <pair <int, int> > sv[sz];
int va[sz], pr[sz], prd[sz], dp[sz], dp2[sz], su[sz];
int tin[sz], up[20][sz], timer=0;
void dfs(int v)
{
    tin[v]=timer, timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, di=sv[v][a].second;
        if(ne!=pr[v])
        {
            pr[ne]=v, prd[ne]=di, dfs(ne);
            if(dp[ne]+va[ne]-2*di>0) dp[v]+=dp[ne]+va[ne]-2*di;
        }
    }
}
void dfs2(int v)
{
    su[v]+=dp[v];
    if(v!=0)
    {
        if(dp[v]+va[v]-2*prd[v]>0) su[v]-=dp[v]+va[v]-2*prd[v];
    }
    su[v]+=va[v]-prd[v];
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, di=sv[v][a].second;
        if(ne!=pr[v])
        {
            su[ne]=su[v];
            int add=dp[v]+dp2[v];
            if(dp[ne]+va[ne]-prd[ne]*2>0) add-=dp[ne]+va[ne]-prd[ne]*2;
            if(add+va[v]-2*di>0) dp2[ne]=add+va[v]-2*di;
            dfs2(ne);
        }
    }
}
int lca(int u, int v)
{
    if(u==v) return u;
    if(tin[u]>tin[v]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[i][v];
        if(tin[ne]>tin[u]) v=ne;
    }
    return pr[v];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<n; a++) scanf("%lld", &va[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v, x;
        scanf("%lld%lld%lld", &u, &v, &x);
        u--, v--;
        sv[u].push_back(make_pair(v, x));
        sv[v].push_back(make_pair(u, x));
    }
    dfs(0);
    for(int a=0; a<n; a++) up[0][a]=pr[a];
    for(int a=1; a<20; a++)
    {
        for(int b=0; b<n; b++) up[a][b]=up[a-1][up[a-1][b]];
    }
    dfs2(0);
    for(int a=0; a<q; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        int u2=lca(u, v);
        int an=(su[u]-su[u2])+(su[v]-su[u2])+va[u2]+dp[u2]+dp2[u2];
        printf("%lld\n", an);
    }
}