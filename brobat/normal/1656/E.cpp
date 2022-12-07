#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
vector<vector<int>> adj;
vector <int> depth;
vector <int> ans;
int root;

void bfs() {
    queue <int> q;
    q.push(root);
    depth[root] = 0;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(depth[next] == -1) {
                depth[next] = depth[curr] + 1;
                q.push(next);
            }
        }
    }
}

void dfs(int node) {
    int children = 0;
    for(auto next : adj[node]) {
        if(depth[next] > depth[node]) {
            dfs(next);
            children++;
        }
    }
    if(depth[node] == 0) {
        ans[node] = children;
    } else {
        if(depth[node] % 2 == 0) {
            // Sum of sub-tree must be 1.
            ans[node] = children + 1;
        } else {
            ans[node] = -(children + 1);
        }
    }
}

void solve() {
    cin >> n;
    adj.resize(n);
    depth.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        depth[i] = -1;
        ans[i] = 0;
    }
    root = -1;
    for(int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        if(root == -1) {
            if((int)adj[t1].size() >= 2) root = t1;
            if((int)adj[t2].size() >= 2) root = t2;
        }
    }
    bfs();
    dfs(root);
    for(auto i : ans) cout << i << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}