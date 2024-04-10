#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> mp;
long long n, m, l;
vector<vector<pair<long long, long long>>> adj;
vector<vector<pair<long long, long long>>> treeadj;
set<long long> badverts;
vector<bool> visited;
vector<vector<long long>> bad;
vector<long long> ddd;
long long diss[45][100005];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(long long v, long long p, long long w)
{
    if(visited[v]){
        badverts.insert(v);
        badverts.insert(p);
        return;
    }
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    visited[v] = 1;
    if(p != v) ddd[v] = ddd[p]+w;
    else ddd[v] = w;
    for (auto u : adj[v]) {
        if (u.first != p)
            dfs(u.first, v, u.second);
    }
    tout[v] = ++timer;
}

void dijkstra(long long x){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    long long disss[n];
    fill(disss, disss+n, 1e16);
    disss[x] = 0;
    pq.push({0, x});
    while(!pq.empty()){
        long long v = pq.top().second;
        long long dv = pq.top().first;
        pq.pop();
        if(dv != disss[v]) continue;
        for(auto i : adj[v]){
            long long u = i.first;
            long long w = i.second;
            if(disss[v] + w < disss[u]){
                disss[u] = disss[v] + w;
                pq.push({disss[u], u});
            }
        }
    }
    for(int i = 0; i<n; i++){
        diss[mp[x]][i] = disss[i];
    }
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    adj.resize(n);
    treeadj.resize(n);
    bad.resize(n);
    visited.assign(n, 0);
    ddd.resize(n);
    for(long long i = 0; i<m; i++){
        long long a, b, w; cin >> a >> b >> w;
        --a; --b;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    preprocess(0);
    long long cur = 0;
    for(auto i : badverts) mp[i] = cur++;
    for(auto i : badverts){
        dijkstra(i);
    }
    // for(long long i = 0; i<n; i++){
    //     cout << i+1 << endl;
    //     for(auto v : bad[i]) cout << v+1 << " ";
    //     cout << endl << endl;
    // }
    long long q; cin >> q;
    while(q--){
        long long a, b; cin >> a >> b;
        --a; --b;
        long long ans = ddd[a]+ddd[b]-2*ddd[lca(a, b)];
        for(auto i : badverts){
            ans = min(ans, diss[mp[i]][a]+diss[mp[i]][b]);
        }
        cout << ans << endl;
    }
}