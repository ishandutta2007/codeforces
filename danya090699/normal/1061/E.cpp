#include <bits/stdc++.h>
using namespace std;
const int sz=3e3+10, inf=1e5+10;
vector <int> sv[2][sz];
int pr[2][sz], nu[2][sz], su[2][sz];
void dfs(int i, int v)
{
    for(int a=0; a<sv[i][v].size(); a++)
    {
        int ne=sv[i][v][a];
        if(ne!=pr[i][v]) pr[i][ne]=v, dfs(i, ne);
    }
}
void dfs2(int i, int v, int u)
{
    nu[i][v]=u;
    for(int a=0; a<sv[i][v].size(); a++)
    {
        int ne=sv[i][v][a];
        if(ne!=pr[i][v])
        {
            if(su[i][ne]) su[i][u]-=su[i][ne], dfs2(i, ne, ne);
            else dfs2(i, ne, u);
        }
    }
}

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


int d[sz], pot[sz], prevedge[sz], prevnode[sz];
struct Cmp{
    inline bool operator()(const int &lhs, const int &rhs){
        if(d[lhs] != d[rhs]) return d[lhs] < d[rhs];
        return lhs < rhs;
    }
};
set < int, Cmp > q;

pair < int, int > mincost(int n){
    int cinf=1e9;
    int flow = 0;
    int flowcost = 0;
    while(true){
        for(int i = 0; i < n; i++) d[i] = cinf;
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
        if(d[dst] == cinf) break;
        for(int i = 0; i < n; i++) pot[i] += d[i];
        int df = cinf;
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
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, rt[2];
    cin>>n>>rt[0]>>rt[1];
    rt[0]--, rt[1]--;
    src=n*3, dst=n*3+1;
    int va[n];
    for(int a=0; a<n; a++) scanf("%d", &va[a]);
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[i][u].push_back(v);
            sv[i][v].push_back(u);
        }
        pr[i][rt[i]]=rt[i], dfs(i, rt[i]);
    }
    int tot[2]={0, 0}, ok=1;
    for(int i=0; i<2; i++)
    {
        int qq;
        cin>>qq;
        for(int a=0; a<qq; a++)
        {
            int v;
            scanf("%d", &v);
            v--;
            scanf("%d", &su[i][v]);
        }
        dfs2(i, rt[i], rt[i]);
        for(int a=0; a<n; a++)
        {
            if(i==0) add_edge(nu[i][a]+n, a, 1, inf-va[a]);
            else add_edge(a, nu[i][a]+2*n, 1, 0);

            if(nu[i][a]==a)
            {
                if(su[i][a]<0) ok=0;
                else
                {
                    tot[i]+=su[i][a];

                    if(i==0) add_edge(src, a+n, su[i][a], 0);
                    else add_edge(a+2*n, dst, su[i][a], 0);
                }
            }
        }
    }
    if(tot[0]!=tot[1]) ok=0;
    if(ok)
    {
        pair <int, int> an=mincost(n*3+2);
        if(an.first==tot[0]) cout<<-(an.second-inf*an.first);
        else cout<<-1;
    }
    else cout<<-1;
}