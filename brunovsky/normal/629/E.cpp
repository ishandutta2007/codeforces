#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
namespace gnu = __gnu_pbds;

template <typename K, typename V, typename Hash>
using hash_map = gnu::gp_hash_table<K, V, Hash>;

struct Hasher {
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
    }
};

namespace std {

template <typename U, typename V>
struct hash<pair<U, V>> : Hasher {};

} // namespace std

#define long int64_t

// sum[u] = SUM((1+paths[c0,u])*size[c0,u])

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

struct lca_tree {
    int N, B;
    vector<vector<int>> up;
    vector<int> depth;

    static int need_bits(int n) {
        return 1 + (n > 1 ? 8 * sizeof(n) - __builtin_clz(n - 1) : 0);
    }

    explicit lca_tree(const vector<vector<int>>& tree, int root)
        : N(tree.size()), B(need_bits(N)), up(B, vector<int>(N)), depth(N) {
        init_dfs(tree, root, 0);

        for (int b = 1; b < B; b++) {
            for (int i = 1; i < N; i++) {
                int p = up[b - 1][i];
                up[b][i] = (p >= 1) ? up[b - 1][p] : 0;
            }
        }
    }

    void init_dfs(const vector<vector<int>>& tree, int u, int p) {
        up[0][u] = p;
        depth[u] = (p >= 1) ? depth[p] + 1 : 0;
        for (int v : tree[u]) {
            if (v != p) {
                init_dfs(tree, v, u);
            }
        }
    }

    int ancestor(int u, int steps) const {
        for (int b = B - 1; b >= 0; b--) {
            if (steps & (1 << b)) {
                u = up[b][u];
            }
        }
        return u;
    }

    int parent(int u) const { return up[0][u]; }

    int lca(int u, int v) const {
        if (depth[u] < depth[v]) {
            v = ancestor(v, depth[v] - depth[u]);
        } else if (depth[u] > depth[v]) {
            u = ancestor(u, depth[u] - depth[v]);
        }
        for (int k = B - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u], v = up[k][v];
            }
        }
        return u == v ? u : up[0][u];
    }

    int dist(int u, int v) { // # edges on path
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<vector<int>> tree(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> size(N + 1);
    vector<int> depth(N + 1);
    vector<int> parent(N + 1);
    vector<long> sum(N + 1);
    size[0] = N;

    auto dfs_forward = y_combinator([&](auto self, int u, int p) -> void {
        size[u] = 1;
        depth[u] = depth[p] + 1;
        sum[u] = depth[u];
        parent[u] = p;
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
                size[u] += size[v];
                sum[u] += sum[v];
            }
        }
    });

    dfs_forward(1, 0);

    unordered_map<pair<int, int>, long> dp;

    auto dfs_dp = y_combinator([&](auto self, int u, int p) -> void {
        dp[{u, 0}] = sum[u] - size[u] * depth[u];
        for (int v : tree[u]) {
            if (v != p) {
                long above = dp[{p, u}] + N - size[u];
                long below = sum[u] - sum[v] - (size[u] - size[v]) * depth[u];
                dp[{u, v}] = above + below;
                self(v, u);
            }
        }
    });

    dfs_dp(1, 0);

    lca_tree lca(tree, 1);

    cout << setprecision(7) << fixed << showpoint;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        int a = lca.lca(u, v);
        int dist = lca.dist(u, v);
        if (a == u) {
            int r = lca.ancestor(v, dist - 1);
            long us = N - size[r];
            long vs = size[v];
            double around = 1.0 * (us * dp.at({v, 0}) + vs * dp.at({u, r})) / (us * vs);
            cout << (1 + dist + around) << endl;
        } else if (a == v) {
            int r = lca.ancestor(u, dist - 1);
            long us = size[u];
            long vs = N - size[r];
            double around = 1.0 * (us * dp.at({v, r}) + vs * dp.at({u, 0})) / (us * vs);
            cout << (1 + dist + around) << endl;
        } else {
            long us = size[u];
            long vs = size[v];
            double around = 1.0 * (us * dp.at({v, 0}) + vs * dp.at({u, 0})) / (us * vs);
            cout << (1 + dist + around) << endl;
        }
    }

    return 0;
}