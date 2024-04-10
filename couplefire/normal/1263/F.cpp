#include <bits/stdc++.h>
using namespace std;

struct Dinic{
    using F = int;
    struct Edge{int to, rev; F f;};
    int n; vector<vector<Edge>> adj;
    void init(int _n){n = _n; adj.resize(n);}
    void ae(int a, int b, F cap){
        adj[a].push_back({b, (int)adj[b].size(), cap});
        adj[b].push_back({a, (int)adj[a].size()-1, 0});
    }
    vector<int> lev, ptr;
    bool bfs(int s, int t){
        lev = ptr = vector<int>(n);
        lev[s] = 1; queue<int> q({s});
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto e : adj[u]) if(e.f && !lev[e.to]) q.push(e.to), lev[e.to] = lev[u]+1;
        }
        return lev[t];
    }
    F dfs(int v, int t, F flo){
        if(v == t) return flo;
        for(int& i = ptr[v]; i<(int)adj[v].size(); i++){
            Edge& e = adj[v][i];
            if(lev[e.to] != lev[v]+1 || !e.f) continue;
            if(F df = dfs(e.to, t, min(flo, e.f))){
                e.f -= df; adj[e.to][e.rev].f += df;
                return df;
            }
        }
        return 0;
    }
    F maxFlow(int s, int t){
        F tot = 0;
        while(bfs(s, t)) while(F df = dfs(s, t, numeric_limits<F>::max())) tot += df;
        return tot;
    }
} dinic;

const int N = 2005;

int n, a, b, a_pos[N], b_pos[N], a_tin[N], a_tout[N], b_tin[N], b_tout[N];
vector<int> a_adj[N], b_adj[N];

void a_dfs(int v, int p){
    a_tin[v] = N, a_tout[v] = 0;
    for(auto u : a_adj[v])
        if(u!=p) a_dfs(u, v), a_tin[v] = min(a_tin[v], a_tin[u]), a_tout[v] = max(a_tout[v], a_tout[u]);
    if(a_tin[v]==N)
        a_tin[v] = a_pos[v], a_tout[v] = a_pos[v];
}

void b_dfs(int v, int p){
    b_tin[v] = N, b_tout[v] = 0;
    for(auto u : b_adj[v])
        if(u!=p) b_dfs(u, v), b_tin[v] = min(b_tin[v], b_tin[u]), b_tout[v] = max(b_tout[v], b_tout[u]);
    if(b_tin[v]==N)
        b_tin[v] = b_pos[v], b_tout[v] = b_pos[v];
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> a;
    for(int i = 1; i<a; ++i){
        int p; cin >> p; --p;
        a_adj[p].push_back(i);
    }
    for(int i = 0; i<n; ++i){
        int x; cin >> x; --x;
        a_pos[x] = i;
    }
    cin >> b;
    for(int i = 1; i<b; ++i){
        int p; cin >> p; --p;
        b_adj[p].push_back(i);
    }
    for(int i = 0; i<n; ++i){
        int x; cin >> x; --x;
        b_pos[x] = i;
    }
    a_dfs(0, -1); b_dfs(0, -1);
    dinic.init(2*N+2);
    for(int i = 1; i<a; ++i)
        dinic.ae(2*N, i, 1);
    for(int i = 1; i<b; ++i)
        dinic.ae(N+i, 2*N+1, 1);
    for(int i = 1; i<a; ++i)
        for(int j = 1; j<b; ++j)
            if(!(a_tout[i]<b_tin[j] || b_tout[j]<a_tin[i]))
                dinic.ae(i, N+j, 1e9);
    cout << a+b-2-dinic.maxFlow(2*N, 2*N+1) << '\n';
}