#include <bits/stdc++.h>
using namespace std;

class LCA {
public:
    int n, l, timer;
    vector<vector<int>> adj, up;
    vector <int> tin, tout, depth;

    LCA(vector<vector<int>> _adj, int root = 0) : adj(_adj) {
        n = adj.size();
        l = ceil(log2(n)) + 1;
        timer = 0;
        tin.resize(n);
        tout.resize(n);
        depth.resize(n);
        up.assign(n, vector<int>(l));
        dfs(root, root, 0);
    }

    void dfs(int node, int prev, int d) {
        tin[node] = ++timer;
        depth[node] = d;
        up[node][0] = prev;
        for(int i = 1; i < l; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
        for(auto next : adj[node]) {
            if(next != prev) dfs(next, node, d + 1);
        }
        tout[node] = ++timer;
    }

    bool is_ancestor(int x, int y) {
        return tin[x] <= tin[y] && tout[x] >= tout[y];
    }

    int query(int u, int v) {
        if(is_ancestor(u, v)) return u;
        if(is_ancestor(v, u)) return v;
        for(int i = l - 1; i >= 0; i--) {
            if(!is_ancestor(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }

    int go_up(int x, int k) {
        if(k > depth[x]) return -1;
        for(int i = l - 1; i >= 0; i--) {
            if((k >> i) & 1) x = up[x][i];
        }
        return x;
    }
};

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    LCA lca(adj);
    vector <int> p = CentroidDecomposition(adj).p;
    vector <int> dist(n, (int)1E9);

    auto DIST = [&](int x, int y) -> int {
        int z = lca.query(x, y);
        return lca.depth[x] + lca.depth[y] - 2*lca.depth[z];
    };

    auto UPDATE = [&](int node) -> void {
        int curr = node;
        while(curr >= 0) {
            dist[curr] = min(dist[curr], DIST(node, curr));
            curr = p[curr];
        }
    };

    auto QUERY = [&](int node) -> int {
        int curr = node;
        int ans = (int)1E9;
        while(curr >= 0) {
            ans = min(ans, dist[curr] + DIST(node, curr));
            curr = p[curr];
        }
        return ans;
    };

    UPDATE(0);

    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --y;
        if(x == 1) UPDATE(y);
        else cout << QUERY(y) << '\n';
    }

    return 0;
}