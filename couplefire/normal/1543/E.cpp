#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(1<<n);
    for(int i = 0; i<n*(1<<(n-1)); i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ord;
    vector<bool> vis((1<<n), 0);
    queue<int> q({0});
    while(q.size()){
        int v = q.front(); q.pop();
        if(vis[v]) continue;
        vis[v] = 1, ord.push_back(v);
        for(auto u : adj[v])
            if(!vis[u]) q.push(u);
    }
    fill(vis.begin(), vis.end(), 0);
    vector<int> val(1<<n), id(1<<n);
    val[0] = 0, id[0] = 0, vis[0] = 1;
    for(int i = 1; i<=n; i++)
        val[ord[i]] = 1<<(i-1), id[1<<(i-1)] = ord[i], vis[ord[i]] = 1;
    for(int i = n+1; i<(1<<n); i++){
        val[ord[i]] = 0;
        for(auto u : adj[ord[i]])
            if(vis[u]) val[ord[i]] |= val[u];
        id[val[ord[i]]] = ord[i];
        vis[ord[i]] = 1;
    }
    for(int i = 0; i<(1<<n); i++)
        cout << id[i] << " ";
    cout << endl;
    int lg = 1;
    while(lg < n) lg *= 2;
    if(lg != n) return void(cout << -1 << endl);
    vector<int> ans(1<<n);
    for(int i = 0; i<(1<<n); i++){
        int bruh = 0;
        for(int j = 0; j<n; j++)
            bruh ^= j*((i>>j)&1);
        ans[id[i]] = bruh;
    }
    for(int i = 0; i<(1<<n); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}