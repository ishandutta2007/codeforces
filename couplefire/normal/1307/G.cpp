#include <bits/stdc++.h>
using namespace std;

struct MCMF{
    using F = int; using C = int;
    struct Edge{int to, rev; F f; C cost;};
    int n; vector<C> p, dist; vector<pair<int, int>> pre; vector<vector<Edge>> adj;
    vector<pair<long long, C>> ans;
    void init(int _n){
        n = _n; p.resize(n); dist.resize(n); pre.resize(n); adj.resize(n);
    }
    void ae(int u, int v, F cap, C cost){
        adj[u].push_back({v, (int)adj[v].size(), cap, cost});
        adj[v].push_back({u, (int)adj[u].size()-1, 0, -cost});
    }
    bool path(int s, int t){
        const C INF = numeric_limits<C>::max(); dist.assign(n, INF);
        using T = pair<C, int>; priority_queue<T, vector<T>, greater<T>> todo;
        todo.push({dist[s] = 0, s});
        while(!todo.empty()){
            T x = todo.top(); todo.pop();
            if(x.first > dist[x.second]) continue;
            for(auto& e : adj[x.second]){
                if(e.f && dist[e.to] > x.first+e.cost+p[x.second]-p[e.to])
                    dist[e.to] = x.first+e.cost+p[x.second]-p[e.to], pre[e.to] = {x.second, e.rev}, todo.push({dist[e.to], e.to});
            }
        }
        return dist[t] != INF;
    }
    pair<F, C> maxFlow(int s, int t){
        for(int x = 0; x<n; x++) for(int i = 0; i<n; i++) 
            for(auto& e : adj[i]) if(e.f) p[e.to] = min(p[e.to], p[i]+e.cost);
        F totFlow = 0; C totCost = 0;
        while(path(s, t)){
            for(int i = 0; i<n; i++) p[i] += dist[i];
            ans.push_back({1ll*totFlow*(p[t]-p[s])-totCost, (p[t]-p[s])});
            F df = numeric_limits<F>::max();
            for(int x = t; x != s; x = pre[x].first){
                Edge& e = adj[pre[x].first][adj[x][pre[x].second].rev];
                df = min(df, e.f);
            }
            totFlow += df, totCost += (p[t]-p[s])*df;
            for(int x = t; x != s; x = pre[x].first){
                Edge& e = adj[x][pre[x].second]; e.f += df;
                adj[pre[x].first][e.rev].f -= df;
            }
            // cout << totFlow << " " << dist[t] << endl;
        }
        ans.push_back({1ll*totFlow*dist[t]-totCost, dist[t]});
        return {totFlow, totCost};
    }
} mcmf;

int n, m, q;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cout << fixed << setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    mcmf.init(n);
    for(int i = 0; i<m; i++){
        int u, v, w; cin >> u >> v >> w; --u; --v;
        mcmf.ae(u, v, 1, w);
    }
    mcmf.maxFlow(0, n-1);
    // cout << mcmf.ans << endl;
    cin >> q;
    while(q--){
        long long x; cin >> x;
        auto it = lower_bound(mcmf.ans.begin(), mcmf.ans.end(), pair<long long, int>{x+1, 0});
        long double ans = (long double)1.0*((it-1)->second*(it->first-x)+it->second*(x-(it-1)->first))/(it->first-(it-1)->first);
        cout << ans << endl;
    }
}