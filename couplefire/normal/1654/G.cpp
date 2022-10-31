#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int INF = 0x3f3f3f3f;

int n; bool l[N], vis[N];
vector<int> adj[N];
vector<int> good[N];
int h[N], ans[N], mx[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; ++i)
        cin >> l[i];
    for(int i = 0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    memset(h, INF, sizeof h);
    for(int i = 0; i<n; ++i)
        if(l[i]) q.push(i), h[i] = 0, vis[i] = 1;
    while(q.size()){
        int v = q.front(); q.pop();
        for(auto u : adj[v]){
            if(vis[u]) continue;
            h[u] = h[v]+1;
            vis[u] = 1;
            q.push(u);
        }
    }
    memset(vis, 0, sizeof vis);
    for(int i = 0; i<n; ++i){
        bool ok = 0;
        for(auto v : adj[i])
            if(h[v]==h[i]){
                ok = 1;
                break;
            }
        if(ok) good[h[i]].push_back(i);
    }
    for(int i = 0; i<n; ++i)
        ans[i] = h[i];
    for(int i = n-1; i>=0; --i){
        if(good[i].empty()) continue;
        fill(mx, mx+N, -INF);
        vector<int> cur_layer = good[i];
        for(auto x : good[i])
            mx[x] = 0;
        while(cur_layer.size()){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for(auto x : cur_layer)
                pq.push({mx[x], x});
            vector<int> nxt_layer;
            while(pq.size()){
                int d = pq.top().first;
                int v = pq.top().second;
                pq.pop();
                if(d!=mx[v]) continue;
                for(auto u : adj[v]){
                    if(h[u]==h[v]+1){
                        nxt_layer.push_back(u);
                        mx[u] = max(mx[u], d+1);
                    }
                    if(h[u]!=h[v]) continue;
                    if(mx[u]<min(-1, d-1)){
                        mx[u] = min(-1, d-1);
                        pq.push({mx[u], u});
                    }
                }
            }
            sort(nxt_layer.begin(), nxt_layer.end());
            nxt_layer.erase(unique(nxt_layer.begin(), nxt_layer.end()), nxt_layer.end());
            swap(cur_layer, nxt_layer);
        }
        memset(vis, 0, sizeof vis);
        for(int j = 0; j<n; ++j)
            if(mx[j]>=0) ans[j] = 2*h[j]-i;
    }
    for(int i = 0; i<n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}