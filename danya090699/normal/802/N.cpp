#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e4;

int src, dst;
struct edge{
    int to, f, cap, rev, cost;
};
vector < edge > g[sz];

void add_edge(int a, int b, int cap, int cost){
    edge ab = {b, 0, cap, g[b].size(), cost};
    edge ba = {a, 0, 0, g[a].size(), -cost};
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
    int flow = 0, flowcost = 0, INF = 1e18;

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
    int n, k, src2;
    cin>>n>>k;
    src=n*2, src2=src+1, dst=src+2;
    add_edge(src, src2, k, 0);
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        add_edge(src2, a, 1, x);
        add_edge(a, a+n, 1, 0);
    }
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        add_edge(a+n, dst, 1, x);
        if(a+1<n) add_edge(a+n, a+n+1, 1e9, 0);
    }
    cout<<mincost(n*2+3).second;
}