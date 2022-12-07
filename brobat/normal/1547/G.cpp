#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
vector<vector<int>> adj;
vector<int> state, vis, ans;

void dfs(int node) {
    state[node] = 1;
    if(ans[node] == 0) {
        ans[node] = 1;
    }
    for(auto next : adj[node]) {
        if(state[next] == 0) dfs(next);
        else if(state[next] == 1) {
            vis[next] = 1;
        } else if(ans[next] == 1) {
            ans[next] = 2;
            dfs(next);
        }
    }
    state[node] = 2;
}

void bfs() {
    queue <int> q;
    for(int i = 0; i < n; i++) {
        if(vis[i]) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(!vis[next]) {
                q.push(next);
                vis[next] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(vis[i] == 1 && ans[i] != 0) {
            ans[i] = -1;
        }
    }
}

void solve() {
    cin >> n;
    adj.resize(n);
    state.resize(n);
    vis.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        state[i] = 0;
        vis[i] = 0;
        ans[i] = 0;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
    }
    dfs(0);
    bfs();
    for(auto i : ans) cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}