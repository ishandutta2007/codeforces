#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=2e3+10, inf=1e18;
struct re
{
    int fr, to, cap;
};
int s, t, yk[sz], di[sz];
vector <int> sv[sz];
vector <re> edges;
void add_edge(int u, int v, int cap)
{
    sv[u].push_back(edges.size());
    edges.push_back({u, v, cap});
    sv[v].push_back(edges.size());
    edges.push_back({v, u, 0});// {v, u, cap} for bidirectional
}
bool bfs(int n)
{
    int qu[n], qf=0, qb=1;
    qu[0]=s;
    for(int a=0; a<n; a++) di[a]=inf;
    di[s]=0;
    while(qf<qb)
    {
        int v=qu[qf];
        for(int a=0; a<sv[v].size(); a++)
        {
            int i=sv[v][a];
            int ne=edges[i].to;
            if(di[ne]==inf and edges[i].cap>0)
            {
                di[ne]=di[v]+1, qu[qb]=ne, qb++;
            }
        }
        qf++;
    }
    return di[t]!=inf;
}
int dfs(int v, int flow)
{
    if(v==t) return flow;
    while(yk[v]<sv[v].size())
    {
        int i=sv[v][yk[v]];
        int ne=edges[i].to;
        if(di[ne]==di[v]+1 and edges[i].cap>0)
        {
            int re=dfs(ne, min(flow, edges[i].cap));
            if(re)
            {
                edges[i].cap-=re;
                edges[i^1].cap+=re;
                return re;
            }
        }
        yk[v]++;
    }
    return 0;
}
int dinic(int n)
{
    int flow=0;
    while(bfs(n))
    {
        for(int a=0; a<n; a++) yk[a]=0;
        while(1)
        {
            int add=dfs(s, inf);
            if(add) flow+=add;
            else break;
        }
    }
    return flow;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    s=n+m, t=n+m+1;
    for(int a=0; a<n; a++)
    {
        int w;
        cin>>w;
        add_edge(m+a, t, w);
    }
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--, v--;
        add_edge(s, a, w);
        add_edge(a, m+u, inf);
        add_edge(a, m+v, inf);
        an+=w;
    }
    cout<<an-dinic(n+m+2);
}