#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct lca_incremental {
    vector<int> parent, depth, jump;

    lca_incremental() = default;
    lca_incremental(int N) : parent(N, -1), depth(N), jump(N) {}

    lca_incremental(const vector<vector<int>>& tree, int root) {
        int N = tree.size();
        ensure(N);
        dfs_tree_root(tree, root);
        for (int u = 0; u < N; u++) {
            if (u != root && parent[u] == -1) {
                dfs_tree_root(tree, u);
            }
        }
    }

    int num_nodes() const { return parent.size(); }

    void add_root(int u) {
        ensure(u);
        parent[u] = u;
        depth[u] = 0;
        jump[u] = u;
    }

    void add_child(int p, int u) {
        ensure(u);
        parent[u] = p;
        depth[u] = depth[p] + 1;
        int t = jump[p];
        jump[u] = depth[p] + depth[jump[t]] == 2 * depth[t] ? jump[t] : p;
    }

    int ancestor(int u, int steps) const {
        assert(0 <= steps && steps <= depth[u]);
        int dest = depth[u] - steps;
        while (depth[u] > dest) {
            if (depth[jump[u]] < dest) {
                u = parent[u];
            } else {
                u = jump[u];
            }
        }
        return u;
    }

    // Assumes u and v in the same tree, edit this otherwise
    int lca(int u, int v) const {
        if (depth[u] < depth[v]) {
            v = ancestor(v, depth[v] - depth[u]);
        } else if (depth[u] > depth[v]) {
            u = ancestor(u, depth[u] - depth[v]);
        }
        while (u != v) {
            if (jump[u] == jump[v]) {
                u = parent[u], v = parent[v];
            } else {
                u = jump[u], v = jump[v];
            }
        }
        return u;
    }

    auto get_path(int u, int v) {
        int a = lca(u, v);
        int D = depth[u] - depth[a] + 1;
        vector<int> path;
        while (u != a) {
            path.push_back(u), u = parent[u];
        }
        path.push_back(a);
        while (v != a) {
            path.push_back(v), v = parent[v];
        }
        reverse(begin(path) + D, end(path));
        return path;
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }

    bool conn(int u, int v) const {
        return ancestor(u, depth[u]) == ancestor(v, depth[v]);
    }

  private:
    void ensure(int N) {
        if (int S = parent.size(); S < N) {
            parent.resize(N + 1, -1);
            depth.resize(N + 1, 0);
            jump.resize(N + 1, 0);
        }
    }

    void dfs_tree(const vector<vector<int>>& tree, int u, int p) {
        for (int v : tree[u]) {
            if (v != p) {
                add_child(u, v);
                dfs_tree(tree, v, u);
            }
        }
    }

    void dfs_tree_root(const vector<vector<int>>& tree, int root) {
        add_root(root);
        dfs_tree(tree, root, -1);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> p(N), at(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i], p[i]--;
        at[p[i]] = i;
    }

    map<array<int, 2>, int> swap_index;
    vector<array<int, 2>> swaps;
    vector<int> swap_count(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        swaps.push_back({u, v});
        swap_index[{u, v}] = swap_index[{v, u}] = i;
        swap_count[u]++, swap_count[v]++;
    }

    vector<vector<int>> tree(N);
    for (auto [u, v] : swaps) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    lca_incremental lca(tree, 0);

    vector<vector<int>> out(M);
    for (int u = 0; u < N; u++) {
        if (u != p[u]) {
            auto path = lca.get_path(u, at[u]);
            int P = path.size();
            for (int i = 2; i < P; i++) {
                int a = path[i - 2], b = path[i - 1], c = path[i];
                int e = swap_index.at({a, b});
                int f = swap_index.at({b, c});
                out[f].push_back(e);
            }
        }
    }

    vector<int> indeg(M);
    for (int e = 0; e < M; e++) {
        for (int f : out[e]) {
            indeg[f]++;
        }
    }

    vector<int> bfs;
    for (int e = 0; e < M; e++) {
        if (indeg[e] == 0) {
            bfs.push_back(e);
        }
    }

    for (int i = 0, B = bfs.size(); i < B; i++) {
        int e = bfs[i];
        for (int f : out[e]) {
            if (--indeg[f] == 0) {
                bfs.push_back(f), B++;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cout << bfs[i] + 1 << " \n"[i + 1 == M];
    }
    return 0;
}