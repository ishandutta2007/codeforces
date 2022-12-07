#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18, sz=2e3+10;

struct re
{
    int fr, to, cap;
};
int S, T, yk[sz], di[sz];
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
    qu[0]=S;
    for(int a=0; a<n; a++) di[a]=inf;
    di[S]=0;
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
    return di[T]!=inf;
}
int dfs(int v, int flow)
{
    if(v==T) return flow;
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
            int add=dfs(S, inf);
            if(add) flow+=add;
            else break;
        }
    }
    return flow;
}

main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int sm[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) sm[a][b]=(a==b) ? 0 : inf;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sm[u][v]=1, sm[v][u]=1;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            for(int c=0; c<n; c++) sm[b][c]=min(sm[b][c], min(sm[b][a]+sm[a][c], inf));
        }
    }
    int shq, baq, k;
    cin>>shq>>baq>>k;
    int sh[shq][4];
    for(int a=0; a<shq; a++)
    {
        for(int b=0; b<4; b++) scanf("%lld", &sh[a][b]);
        sh[a][0]--;
    }
    vector <pair <int, int> > sp[n];
    for(int a=0; a<baq; a++)
    {
        int v, d, g;
        scanf("%lld%lld%lld", &v, &d, &g);
        v--;
        sp[v].push_back({d, g});
    }
    for(int a=0; a<n; a++)
    {
        sp[a].push_back({0, -inf});
        sort(sp[a].begin(), sp[a].end());
        for(int b=1; b<sp[a].size(); b++) sp[a][b].second=max(sp[a][b-1].second, sp[a][b].second);
    }
    int va[shq];
    for(int a=0; a<shq; a++)
    {
        va[a]=-inf;
        int v=sh[a][0], f=sh[a][1], di=sh[a][2], pri=sh[a][3];
        for(int b=0; b<n; b++)
        {
            if(sm[v][b]<=di)
            {
                int p=upper_bound(sp[b].begin(), sp[b].end(), make_pair(f, inf))-sp[b].begin();
                va[a]=max(va[a], sp[b][p-1].second);
            }
        }
        va[a]-=pri;
    }
    map <int, int> ma;
    int re[k][2], vq=0;
    for(int a=0; a<k; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        ma[u]=0, ma[v]=0;
        re[a][0]=u, re[a][1]=v;
    }
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=vq++;
    S=vq++, T=vq++;
    int an=0;
    for(int a=0; a<shq; a++)
    {
        if(ma.find(a)==ma.end()) an+=max(va[a], 0ll);
        else
        {
            if(va[a]>0) add_edge(S, ma[a], va[a]), an+=va[a];
            else add_edge(ma[a], T, -va[a]);
        }
    }
    for(int a=0; a<k; a++)
    {
        int u=ma[re[a][0]], v=ma[re[a][1]];
        add_edge(u, v, inf);
    }
    an-=dinic(vq);
    cout<<an;
}