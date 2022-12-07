#include <bits/stdc++.h>
using namespace std;

class CentroidDecomposition {
public:
    int n;
    vector<vector<int>> adj; // original tree
    vector<int> p; // new tree, represented by parent array
    vector<bool> vis;
    vector <int> sz; // size of subtree, will keep changing while finding centroid decomposition

    CentroidDecomposition(vector<vector<int>> _adj) {
        adj = _adj;
        n = adj.size();
        p.assign(n, -1);
        vis.assign(n, false);
        sz.resize(n);
        init_centroid(0, -1);
    }

    int find_size(int node, int prev) {
        sz[node] = 1;
        for(auto next : adj[node]) {
            if(next != prev && !vis[next]) {
                sz[node] += find_size(next, node);
            }
        }
        return sz[node];
    }

    int find_centroid(int node, int prev, int n) {
        // n --> size of the subtree we are solving for
        for(auto next : adj[node]) {
            if(next != prev && !vis[next]) {
                if(sz[next] > n/2) {
                    return find_centroid(next, node, n);
                }
            }
        }
        return node;
    }

    void init_centroid(int node, int prev) {
        find_size(node, prev);
        int c = find_centroid(node, node, sz[node]);
        vis[c] = true;
        p[c] = prev;
        for(auto next : adj[c]) {
            if(!vis[next]) {
                init_centroid(next, c);
            }
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector <int> p = CentroidDecomposition(adj).p;
    vector<vector<int>> g(n);
    int root = -1;
    for(int i = 0; i < n; i++) {
        if(p[i] == -1) {
            root = i;
        } else {
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
    }
    vector <int> ans(n);
    
    function<void(int, int, int)> dfs = [&](int node, int prev, int depth) -> void {
        ans[node] = depth;
        for(auto next : g[node]) {
            if(next != prev) dfs(next, node, depth + 1);
        }
    };

    dfs(root, root, 0);

    for(auto i : ans) cout << (char)('A' + i) << " ";
    
    return 0;
}