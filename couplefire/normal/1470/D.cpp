#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
vector<bool> marked;

void dfs(int v){
    visited[v] = 1;
    bool work = 1;
    for(auto u : adj[v]) if(marked[u]) work = 0;
    if(work){
        ans.push_back(v); marked[v] = 1;
    }
    for(auto u : adj[v]){
        if(visited[u]) continue;
        dfs(u);
    }
}

void solve(){
    cin >> n >> m;
    adj.clear(); visited.clear(); ans.clear(); marked.clear();
    adj.resize(n); visited.assign(n, 0); marked.assign(n, 0);
    for(int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
        --a; --b; adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs(0);
    for(int i = 0; i<n; i++) if(!visited[i]){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto v : ans) cout << v+1 << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}