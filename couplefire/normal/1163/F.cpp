#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1<<18;
const int INF = 1e17+5;

int n, m, q;
array<int, 3> edges[N];
vector<array<int, 2>> adj[N];
int par[3][N], id[3][N], dist[3][N], ans[N], path[N];
int tree[2*N];
vector<array<int, 3>> qs[N];
vector<array<int, 3>> es[N];

void upd(int idx, int val, int v = 1, int tl = 0, int tr = N-1){
    if(tr < idx || tl > idx) return;
    if(tl == tr){
        tree[v] = min(tree[v], val);
        return;
    }
    int tm = (tl+tr)>>1;
    upd(idx, val, v*2, tl, tm);
    upd(idx, val, v*2+1, tm+1, tr);
    tree[v] = min(tree[v*2], tree[v*2+1]);
}

int query(int l, int r, int v = 1, int tl = 0, int tr = N-1){
    if(tr < l || tl > r) return INF;
    if(l <= tl && tr <= r) return tree[v];
    int tm = (tl+tr)>>1;
    return min(query(l, r, v*2, tl, tm), query(l, r, v*2+1, tm+1, tr));
}

void solve(int* t_par, int* t_id, int* t_dist, int s, int t, bool f){
    fill(t_par, t_par+N, -1);
    fill(t_dist, t_dist+N, INF);
    fill(t_id, t_id+N, -1);
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    t_dist[s] = 0; pq.push({0, s}); t_id[s] = id[0][s];
    while(pq.size()){
        int v = pq.top()[1], d = pq.top()[0]; pq.pop();
        if(t_dist[v] != d) continue;
        for(auto to : adj[v]){
            int u = to[0], w = to[1];
            if(d+w < t_dist[u]){
                t_par[u] = v, t_dist[u] = d+w, pq.push({d+w, u});
                if(!f) t_id[u] = (id[0][u]>=0?id[0][u]:t_id[v]);
            }
        }
    }
    if(f){
        vector<int> lol;
        int v = t;
        while(v != -1)
            lol.push_back(v), v = t_par[v];
        reverse(lol.begin(), lol.end());
        for(int i = 0; i<(int)lol.size(); i++)
            t_id[lol[i]] = i, path[i] = lol[i];
    }
}

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 0; i<m; i++){
        int a, b, w; cin >> a >> b >> w; --a, --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        edges[i] = {a, b, w};
    }
    solve(par[0], id[0], dist[0], 0, n-1, 1);
    solve(par[1], id[1], dist[1], 0, n-1, 0);
    solve(par[2], id[2], dist[2], n-1, 0, 0);
    for(int i = 0; i<q; i++){
        int t, x; cin >> t >> x; --t;
        int u = edges[t][0], v = edges[t][1];
        if(id[0][u] == -1 || id[0][v] == -1){
            ans[i] = min({dist[0][n-1], dist[1][u]+dist[2][v]+x, dist[2][u]+dist[1][v]+x}); 
            continue;
        }
        if(id[0][u] > id[0][v]) swap(u, v);
        if(id[0][v] != id[0][u]+1){
            ans[i] = min({dist[0][n-1], dist[1][u]+dist[2][v]+x, dist[2][u]+dist[1][v]+x});  
            continue;
        }
        qs[id[0][u]].push_back({x, i, t});
    }
    fill(tree, tree+2*N, INF);
    for(int i = 0; i<m; i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        if(dist[1][u]+dist[2][v] > dist[2][u]+dist[1][v]) swap(u, v);
        es[id[1][u]].push_back({u, v, w});
    }
    for(int i = 0; i<n; i++){
        if(es[i].empty()) continue;
        multiset<int> bruh;
        for(auto x : es[i]){
            int u = x[0], v = x[1], w = x[2];
            if(id[0][u] != -1 && id[0][v] != -1 && id[0][v] == id[0][u]+1){
                bruh.insert(w); continue;
            }
            upd(id[2][v], dist[1][u]+dist[2][v]+w);
        }
        for(auto x : qs[i]){
            int w = x[0], idx = x[1];
            bruh.erase(bruh.find(edges[x[2]][2]));
            bruh.insert(w);
            int a = (*bruh.begin());
            ans[idx] = min(dist[1][path[i]]+dist[2][path[i+1]]+a, query(i+1, N-1));
            bruh.erase(bruh.find(w));
            bruh.insert(edges[x[2]][2]);
        }
    }
    for(int i = 0; i<q; i++)
        cout << ans[i] << '\n';
}