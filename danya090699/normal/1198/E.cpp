#include <bits/stdc++.h>
using namespace std;
const int sz=220, inf=1e9+100;
int X[sz], Y[sz];
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
    int n, m;
    cin>>n>>m;
    map <int, int> x, y;
    x[0]=0, x[n]=0, y[0]=0, y[n]=0;
    int ar[m][4];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<4; b++) cin>>ar[a][b];

        ar[a][0]--, ar[a][1]--;

        x[ar[a][0]]=0, y[ar[a][1]]=0, x[ar[a][2]]=0, y[ar[a][3]]=0;
    }
    int qx=0;
    for(auto it=x.begin(); it!=x.end(); it++) (*it).second=qx, X[qx]=(*it).first, qx++;
    qx--;
    int qy=0;
    for(auto it=y.begin(); it!=y.end(); it++) (*it).second=qy, Y[qy]=(*it).first, qy++;
    qy--;
    bool fi[qx][qy];
    for(int a=0; a<qx; a++) for(int b=0; b<qy; b++) fi[a][b]=0;
    for(int a=0; a<m; a++)
    {
        int lx=x[ar[a][0]], ly=y[ar[a][1]], rx=x[ar[a][2]], ry=y[ar[a][3]];
        for(int b=lx; b<rx; b++)
        {
            for(int c=ly; c<ry; c++) fi[b][c]=1;
        }
    }
    s=qx+qy, t=s+1;
    for(int a=0; a<qx; a++) add_edge(s, a, X[a+1]-X[a]);
    for(int a=0; a<qy; a++) add_edge(a+qx, t, Y[a+1]-Y[a]);
    for(int a=0; a<qx; a++)
    {
        for(int b=0; b<qy; b++)
        {
            if(fi[a][b]) add_edge(a, b+qx, inf);
        }
    }
    cout<<dinic(qx+qy+2);
}