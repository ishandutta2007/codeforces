#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
int pr[sz], tin[sz], up[sz][20], ma[sz][20], mi[sz][20], timer=0;
vector <int> tr[sz];
void dfs(int v)
{
    tin[v]=timer++;
    for(int a=0; a<tr[v].size(); a++) dfs(tr[v][a]);
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
int go(int u, int v, int w)
{
    int re=0;
    for(int i=19; i>=0; i--)
    {
        int ne=up[v][i];
        if(tin[ne]>=tin[u])
        {
            mi[v][i]=min(mi[v][i], w);
            re=max(ma[v][i], re);
            v=ne;
        }
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int re[m][3];
    vector <pair <int, int> > sv[n];
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
        sv[v].push_back({u, w});
        re[a][0]=u, re[a][1]=v, re[a][2]=w;
    }
    int di[n];
    for(int a=1; a<n; a++) di[a]=inf;
    set <pair <int, int> > se;
    di[0]=0;
    se.insert({0, 0});
    while(se.size())
    {
        int v=(*se.begin()).second;
        if(v)
        {
            tr[pr[v]].push_back(v);
            ma[v][0]=di[v];
            up[v][0]=pr[v];
        }
        se.erase(se.begin());
        di[v]=-1;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, w=sv[v][a].second;
            if(di[ne]>=w)
            {
                se.erase({di[ne], ne});
                di[ne]=w, pr[ne]=v;
                se.insert({di[ne], ne});
            }
        }
    }
    dfs(0);
    for(int a=0; a<n; a++) for(int b=0; b<20; b++) mi[a][b]=inf;
    for(int i=1; i<20; i++)
    {
        for(int a=0; a<n; a++)
        {
            up[a][i]=up[up[a][i-1]][i-1];
            ma[a][i]=max(ma[a][i-1], ma[up[a][i-1]][i-1]);
        }
    }
    int an[m];
    for(int a=0; a<m; a++)
    {
        int u=re[a][0], v=re[a][1], w=re[a][2];
        if(pr[u]!=v and pr[v]!=u)
        {
            int u2=lca(u, v);
            an[a]=max(go(u2, u, w), go(u2, v, w));
        }
    }
    for(int i=19; i; i--)
    {
        for(int a=0; a<n; a++)
        {
            mi[a][i-1]=min(mi[a][i-1], mi[a][i]);
            mi[up[a][i-1]][i-1]=min(mi[up[a][i-1]][i-1], mi[a][i]);
        }
    }
    for(int a=0; a<m; a++)
    {
        int u=re[a][0], v=re[a][1];
        if(pr[u]==v) swap(u, v);
        if(pr[v]==u) an[a]=mi[v][0];
    }
    cout<<an[0];
}