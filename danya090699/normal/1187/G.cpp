#include <bits/stdc++.h>
using namespace std;
const int TIME=150, inf=1e9, sz=1e4;

int src, dst;

struct edge{
    int to, f, cap, rev, cost;
};
vector < edge > g[sz];

void add_edge(int a, int b, int cap, int cost){
    edge ab = {b, 0, cap, int(g[b].size()), cost};
    edge ba = {a, 0, 0, int(g[a].size()), -cost};
    g[a].push_back(ab);
    g[b].push_back(ba);
}

int d[sz];
struct Cmp{
    inline bool operator()(const int &lhs, const int &rhs){
        if(d[lhs] != d[rhs]) return d[lhs] < d[rhs];
        return lhs < rhs;
    }
};

// O(n^2*m*logm) or O(m*flow*logm)
pair < int, int > mincost(int n){

    set < int, Cmp > q;
    int pot[n], prevedge[n], prevnode[n];
    int flow = 0, flowcost = 0, INF = 1e9;

    for(int a=0; a<n; a++) pot[a]=0;
    while(true){
        for(int i = 0; i < n; i++) d[i] = INF;
        d[src] = 0;
        q.insert(src);
        while(!q.empty()){
            int v = *q.begin();
            q.erase(q.begin());
            for(int i = 0; i < (int)g[v].size(); i++){
                edge e = g[v][i];
                if(e.f < e.cap){
                    int to = e.to;
                    int w = e.cost;
                    int di = d[v] + pot[v] - pot[to] + w;
                    if(d[to] > di){
                        q.erase(to);
                        d[to] = di;
                        prevnode[to] = v;
                        prevedge[to] = i;
                        q.insert(to);
                    }
                }
            }
        }
        if(d[dst] == INF) break;
        for(int i = 0; i < n; i++) pot[i] += d[i];
        int df = INF;
        for(int v = dst; v != src; v = prevnode[v]){
            int par = prevnode[v];
            int i = prevedge[v];
            df = min(df, g[par][i].cap - g[par][i].f);
        }
        flow += df;
        for(int v = dst; v != src; v = prevnode[v]){
            int par = prevnode[v];
            int i = prevedge[v];
            g[par][i].f += df;
            flowcost += df * g[par][i].cost;
            g[v][g[par][i].rev].f -= df;
        }
    }
    return make_pair(flow, flowcost);
}

main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, c, d;
    cin>>n>>m>>k>>c>>d;
    src=n*TIME, dst=src+1;
    for(int a=0; a<k; a++)
    {
        int v;
        cin>>v;
        v--, add_edge(src, v*TIME, 1, 0);
    }
    for(int a=0; a<n; a++) for(int b=0; b+1<TIME; b++) add_edge(a*TIME+b, a*TIME+b+1, inf, c);
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        for(int h=0; h+1<TIME; h++)
        {
            for(int q=1; q<=n; q++)
            {
                add_edge(u*TIME+h, v*TIME+h+1, 1, c+(q*q-(q-1)*(q-1))*d);
                add_edge(v*TIME+h, u*TIME+h+1, 1, c+(q*q-(q-1)*(q-1))*d);
            }
        }
    }
    for(int a=0; a<TIME; a++) add_edge(a, dst, inf, 0);

    cout<<mincost(n*TIME+2).second;
}