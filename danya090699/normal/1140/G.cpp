#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10, inf=1e18;
struct re
{
    int to, l1, l2;
};
int w[sz], tin[sz], timer=0, up[sz][20], be[sz][20][2][2];
vector <re> sv[sz];
void dfs(int v, int pr)
{
    tin[v]=timer++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to, l1=sv[v][a].l1, l2=sv[v][a].l2;
        if(ne!=pr)
        {
            dfs(ne, v), w[v]=min(w[v], w[ne]+l1+l2);
        }
    }
}
void dfs2(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].to, l1=sv[v][a].l1, l2=sv[v][a].l2;
        if(ne!=pr)
        {
            w[ne]=min(w[ne], w[v]+l1+l2), dfs2(ne, v);
            up[ne][0]=v;
            be[ne][0][0][0]=min(l1, w[ne]+l2+w[v]);
            be[ne][0][0][1]=min(l1+w[v], w[ne]+l2);
            be[ne][0][1][0]=min(l2+w[v], w[ne]+l1);
            be[ne][0][1][1]=min(l2, w[ne]+l1+w[v]);
        }
    }
}
int lca(int u, int v)
{
    if(tin[u]>tin[v]) swap(u, v);
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>tin[u]) v=ne;
    }
    if(v!=u) v=up[v][0];
    return v;
}
pair <int, int> go(int u, int v, int ty)
{
    int dp[2];
    dp[ty]=0, dp[ty^1]=w[v];
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>=tin[u])
        {
            int dp2[2]={inf, inf};
            for(int a=0; a<2; a++)
            {
                for(int b=0; b<2; b++) dp2[b]=min(dp2[b], dp[a]+be[v][i][a][b]);
            }
            dp[0]=dp2[0], dp[1]=dp2[1], v=ne;
        }
    }
    return {dp[0], dp[1]};
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &w[a]);
    for(int a=0; a<n-1; a++)
    {
        int u, v, l1, l2;
        scanf("%lld%lld%lld%lld", &u, &v, &l1, &l2);
        u--, v--;
        sv[u].push_back({v, l1, l2});
        sv[v].push_back({u, l1, l2});
    }
    dfs(0, 0), dfs2(0, 0);
    be[0][0][0][1]=w[0], be[0][0][1][0]=w[0];
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++)
        {
            up[a][i]=up[up[a][i-1]][i-1];
            for(int b=0; b<2; b++)
            {
                for(int c=0; c<2; c++)
                {
                    be[a][i][b][c]=min(be[a][i-1][b][0]+be[up[a][i-1]][i-1][0][c], be[a][i-1][b][1]+be[up[a][i-1]][i-1][1][c]);
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        int u2=lca(u/2, v/2);
        pair <int, int> d1=go(u2, u/2, u%2), d2=go(u2, v/2, v%2);
        printf("%lld\n", min(d1.first+d2.first, d1.second+d2.second));
    }
}