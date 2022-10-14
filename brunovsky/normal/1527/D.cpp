#include <bits/stdc++.h>

using namespace std;

#define long int64_t

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
    int N, B, nil;
    vector<vector<int>> up;
    vector<long> subt;
    vector<int> depth;

    static int need_bits(int n) {
        return 1 + (n > 1 ? 8 * sizeof(n) - __builtin_clz(n - 1) : 0);
    }

    explicit lca_tree(const vector<vector<int>>& tree, int root, int nil = -1)
        : N(tree.size()), B(need_bits(N)), nil(nil), up(B, vector<int>(N, nil)), subt(N),
          depth(N) {
        init_dfs(tree, root, nil);

        for (int b = 1; b < B; b++) {
            for (int i = 1; i < N; i++) {
                if (up[b - 1][i] != nil) {
                    up[b][i] = up[b - 1][up[b - 1][i]];
                }
            }
        }
    }

    void init_dfs(const vector<vector<int>>& tree, int u, int p) {
        up[0][u] = p;
        depth[u] = p != nil ? depth[p] + 1 : 0;
        subt[u] = 1;
        for (int v : tree[u]) {
            if (v != p) {
                init_dfs(tree, v, u);
                subt[u] += subt[v];
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
    ios::sync_with_stdio(true);
    unsigned T;
    cin >> T >> ws;
    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> tree(N);
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        lca_tree lca(tree, 0, -1);

        vector<long> geq(N + 1); // how many paths with mex >= i
        geq[0] = 1LL * N * (N - 1) / 2;

        // deal with 0 first. path passes through 0 so mex>=1.
        long prefix = 1;
        for (int u : tree[0]) {
            geq[1] += lca.subt[u] * prefix;
            prefix += lca.subt[u];
        }

        int branches = 0;
        int l = -1, r = -1;
        set<int> path = {0};

        auto add = [&](int u) {
            while (!path.count(u)) {
                path.insert(u);
                u = lca.parent(u);
            }
        };

        for (int u = 1; u < N; u++) {
            // path passes through [0..u], so mex>=u+1.
            if (branches == 0) {
                branches = 1;
                l = u;
                add(l);
            } else if (path.count(u)) {
                // don't have to do anything
            } else if (l == lca.lca(u, l)) {
                // extend path on the left
                add(u);
                l = u;
            } else if (r != -1 && r == lca.lca(u, r)) {
                // extend path on the right
                add(u);
                r = u;
            } else if (branches == 1) {
                if (lca.lca(u, l) == 0) {
                    branches = 2;
                    add(u);
                    r = u;
                } else {
                    break;
                }
            } else {
                break;
            }
            assert(l != -1);
            if (r == -1) {
                int except = lca.ancestor(l, lca.depth[l] - 1);
                geq[u + 1] = lca.subt[l] * (N - lca.subt[except]);
            } else {
                geq[u + 1] = lca.subt[l] * lca.subt[r];
            }
        }

        vector<long> mex(N + 1);
        mex[N] = geq[N];
        for (int i = N - 1; i >= 0; i--) {
            mex[i] = geq[i] - geq[i + 1];
        }

        for (int i = 0; i <= N; i++) {
            cout << mex[i] << " \n"[i == N];
        }
    }
    return 0;
}