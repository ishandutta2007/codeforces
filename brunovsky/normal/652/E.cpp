#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

auto biconnected_components(const vector<vector<int>>& adj) {
    int N = adj.size();
    vector<int> depth(N, -1), parent(N, -1), cutcount(N), order(N);
    int timer = 0;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        order[timer++] = u;
        for (int v : adj[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                self(v);
                cutcount[u] += cutcount[v];
            } else if (depth[u] < depth[v]) {
                cutcount[u]--;
            } else if (depth[u] > depth[v]) {
                cutcount[u]++;
            }
        }
        cutcount[u]--;
    });

    for (int u = 0; u < N; u++) {
        if (depth[u] == -1) {
            depth[u] = 0;
            dfs(u);
        }
    }

    int B = 0;
    vector<int> bmap(N);
    for (int u : order) {
        if (depth[u] && cutcount[u]) {
            bmap[u] = bmap[parent[u]];
        } else {
            bmap[u] = B++;
        }
    }

    vector<int> block_parent(B, -1);
    for (int u = 0; u < N; u++) {
        for (int v : adj[u]) {
            if (depth[v] < depth[u] && bmap[u] != bmap[v]) {
                block_parent[bmap[u]] = bmap[v];
            }
        }
    }

    return make_tuple(B, move(bmap), move(block_parent));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<array<int, 2>> artifs;
    for (int i = 0; i < M; i++) {
        int u, v, z;
        cin >> u >> v >> z, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (z == 1) {
            artifs.push_back({u, v});
        }
    }
    auto [V, bmap, parent] = biconnected_components(adj);
    int a, b;
    cin >> a >> b, a--, b--;
    vector<int> inside(V), upwards(V);
    for (auto [x, y] : artifs) {
        int u = bmap[x];
        int v = bmap[y];
        if (u == v) {
            inside[u] = true;
        } else if (u == parent[v]) {
            upwards[v] = true;
        } else if (v == parent[u]) {
            upwards[u] = true;
        } else {
            assert(false);
        }
    }
    a = bmap[a];
    b = bmap[b];
    int u = a, v = b;
    while (u != v) {
        u = parent[u] == -1 ? b : parent[u];
        v = parent[v] == -1 ? a : parent[v];
    }
    int c = u;
    bool ok = false;
    while (a != c) {
        ok |= inside[a] || upwards[a];
        a = parent[a];
    }
    while (b != c) {
        ok |= inside[b] || upwards[b];
        b = parent[b];
    }
    ok |= c != -1 && inside[c];
    ok &= c != -1;
    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}