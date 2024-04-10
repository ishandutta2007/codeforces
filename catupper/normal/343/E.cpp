#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<Int, P> T;

class Edge{
public:
    Int from, to, rev;
    Int cost, lim;
    Edge(Int from, Int to, Int cost, Int lim = -1, Int rev = -1):
        from(from),to(to),cost(cost),lim(lim),rev(rev){}
};
class Graph{
public:
    Int n;
    Int m;
    vector<vector<Edge>> edge;
    Graph(Int n = 0):n(n),m(0){
        edge = vector<vector<Edge>>(n);
    }
    void add_edge(Int from, Int to, Int cost = 1, Int lim = -1)
        {
            if(lim == -1){
                edge[from].push_back(Edge(from, to, cost));
                return;
            }
            edge[from].push_back(Edge(from, to, cost, lim, edge[to].size()));
            edge[to].push_back(Edge(to, from, -cost, 0, edge[from].size() - 1));
        }
};


class Dinic{
public:
    Graph *g;
    vector<int> iter, level, come;
    vector<int> color;
    Dinic(){};
    void bfs(int s){
        queue<int> q;
        fill(level.begin(), level.end(), INF);
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int x = q.front();q.pop();
            for(auto e:g->edge[x]){
                if(level[e.to] != INF)continue;
                if(e.lim <= 0)continue;
                level[e.to] = level[x] + 1;
                q.push(e.to);
            }
        }
    }

    Int dfs(int s, int t, Int f){
        if(s == t)return f;
        if(come[s])return 0;
        come[s] = true;
        for(int &i = iter[s];i < g->edge[s].size();i++){
            Edge &e = g->edge[s][i];
            if(e.lim <= 0)continue;
            Int tmp = dfs(e.to, t, min(f, e.lim));
            if(tmp == 0)continue;
            e.lim -= tmp;
            g->edge[e.to][e.rev].lim += tmp;
            return tmp;
        }
        return 0;
    }
    Int max_flow(Graph &_g, int s, int t){
        g = &_g;
        iter = vector<int>(g->n);
        color = vector<int>(g->n);
        level = vector<int>(g->n);
        come = vector<int>(g->n, 0);
        Int res = 0;
        while(true){
            bfs(s);
            if(level[t] == INF)break;
            fill(iter.begin(), iter.end(), 0);
            while(true){
                fill(come.begin(), come.end(), false);
                Int tmp = dfs(s, t, INF);
                if(tmp == 0)break;
                else res += tmp;
            }
        }
        return res;   
    }

    void color_cut(int s){
        if(color[s])return;
        color[s] = 1;
        for(auto e: g->edge[s]){
            if(e.lim > 0)color_cut(e.to);
        }
    }
};

class UnionFind{
public:
    int n;
    vector<int> u;
    UnionFind(int _n = 0){
        n = _n;
        u = vector<int>(n, -1);
    }
    int r(int x){
        if(u[x] < 0)return x;
        return u[x] = r(u[x]);
    }
    void unite(int x, int y){
        x = r(x);
        y = r(y);
        if(x == y)return;
        //if(-u[x] < -u[y])swap(x,y);
        u[x] += u[y];
        u[y] = x;
    }
    int size(int x){
        return -u[r(x)];
    }
};


class GomoryHu{
public:
    vector<vector<int> > components;
    vector<vector<P> > adj;
    vector<int> group;
    int n;
    vector<vector<P> > tree;
    GomoryHu(Graph g):tree(g.n),n(g.n),components(1),adj(1),group(g.n){        
        for(int i = 0;i < n;i++){
            components[0].push_back(i);
        }
        for(int i = 0;i < n-1;i++){
            int nxt_comp = 0;
            while(components[nxt_comp].size() == 1)nxt_comp++;
            for(auto x:components[nxt_comp])group[x] = x;
            for(auto to: adj[nxt_comp])dfs(to.first, nxt_comp, to.first + n);
            int s = components[nxt_comp][0], t = components[nxt_comp][1];
            Graph contract_g(n*2);
            for(int i = 0;i < n;i++){
                for(auto e:g.edge[i]){
                    if(group[e.from] == group[e.to])continue;
                    contract_g.add_edge(group[e.from], group[e.to], 1, e.cost);
                }
            }
            Dinic dinic;
            Int min_cut = dinic.max_flow(contract_g, s, t);dinic.color_cut(s);
            vector<int> s_comp, t_comp;
            for(auto v:components[nxt_comp]){
                if(dinic.color[v])s_comp.push_back(v);
                else t_comp.push_back(v);
            }
            vector<P> s_node, t_node;
            for(auto p:adj[nxt_comp]){
                int to = p.first;
                if(dinic.color[n + to]){
                    s_node.push_back(p);
                }
                else {
                    t_node.push_back(p);
                    for(int i = 0;i < adj[to].size();i++)
                        if(adj[to][i].first == nxt_comp)adj[to][i].first = components.size();
                }
            }
            s_node.push_back(P(components.size(),min_cut));
            t_node.push_back(P(nxt_comp, min_cut));
            components[nxt_comp] = s_comp;
            components.push_back(t_comp);
            adj[nxt_comp] = s_node;
            adj.push_back(t_node);
        }
        for(int i = 0;i < n;i++){
            int from = components[i][0];
            for(auto p:adj[i]){
                int to = components[p.first][0];
                int cost = p.second;
                tree[from].push_back(P(to, cost));
            }
        }
    }

    void dfs(int x, int last, int comp){
        for(auto v:components[x])group[v] = comp;
        for(auto p:adj[x]){
            int to = p.first;
            if(to == last)continue;
            dfs(to, x, comp);
        }        
    }
};

int main(){
    int n, m, u, v, c;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0;i < m;i++){
        cin >> u >> v >> c;u--,v--;
        g.add_edge(u, v, c);
        g.add_edge(v, u, c);
    }
    GomoryHu gh(g);
    auto tree = gh.tree;
    vector<T> edges;
    vector<vector<int>> comp(n);
    for(int i = 0;i < n;i++){
        comp[i].push_back(i);
        for(auto p:tree[i]){
            int to = p.first;
            int cost = p.second;
            if(i > to)continue;
            edges.push_back(T(cost, P(i, to)));
        }
    }
    sort(edges.rbegin(), edges.rend());
    UnionFind uf(n);
    Int cost_sum = 0;
    for(auto e: edges){
        int cost = e.first;
        int u = e.second.first, v= e.second.second;
        cost_sum += cost;
        u = uf.r(u);
        v = uf.r(v);
        for(auto x: comp[v])comp[u].push_back(x);
        comp[v].clear();
        uf.unite(u, v);
    }
    cout << cost_sum << endl;
    for(auto v:comp[uf.r(0)])cout << v+1 << " ";cout << endl;

    
    
    return 0;
}