#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9+10;

int src, src2, dst;
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
int last[sz], last2[7];
main()
{
    for(int a=0; a<sz; a++) last[a]=-1;
    for(int a=0; a<7; a++) last2[a]=-1;
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    src=n*4, src2=src+1, dst=src+2;
    add_edge(src, src2, 4, 0);
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=n-1; a>=0; a--)
    {
        add_edge(a*4, a*4+1, 1, 0);
        add_edge(a*4+2, a*4, inf, 0);
        add_edge(a*4+3, a*4, inf, 0);
        add_edge(src2, a*4, inf, a);
        add_edge(a*4+1, dst, inf, n-a-1);
        int x=ar[a];
        if(last[x+1]!=-1)
        {
            int ne=last[x+1];
            add_edge(a*4+1, ne*4+2, inf, ne-a-1);
        }
        if(last[x-1]!=-1)
        {
            int ne=last[x-1];
            add_edge(a*4+1, ne*4+2, inf, ne-a-1);
        }
        if(last[x]!=-1)
        {
            int ne=last[x];
            add_edge(a*4+2, ne*4+2, inf, ne-a);
        }
        last[x]=a;
        if(last2[x%7]!=-1)
        {
            int ne=last2[x%7];
            add_edge(a*4+1, ne*4+3, inf, ne-a-1);
            add_edge(a*4+3, ne*4+3, inf, ne-a);
        }
        last2[x%7]=a;
    }
    cout<<n*4-mincost(n*4+3).second;
}