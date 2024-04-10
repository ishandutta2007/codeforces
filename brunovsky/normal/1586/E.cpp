#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct lca_schieber_vishkin {
    int N, timer = 0;
    vector<int> preorder, parent, I, A, head, depth;

    static int lowest_one_bit(int n) { return n & -n; }
    static int highest_one_bit(int n) { return n ? 1 << (31 - __builtin_clz(n)) : 0; }

    // Give zero=0 for 1-based indexing and zero=-1 for 0-based indexing
    explicit lca_schieber_vishkin(const vector<vector<int>>& tree, int root = -1)
        : N(tree.size()), preorder(N, -1), parent(N), I(N), A(N), head(N), depth(N) {
        if (root != -1) {
            init_dfs1(tree, root, -1);
            init_dfs2(tree, root, -1, 0);
        }
        for (int u = 0; u < N; u++) {
            if (preorder[u] == -1) {
                init_dfs1(tree, u, -1);
                init_dfs2(tree, u, -1, 0);
            }
        }
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

    void init_dfs1(const vector<vector<int>>& tree, int u, int p) {
        parent[u] = p;
        I[u] = preorder[u] = timer++;
        for (int v : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                init_dfs1(tree, v, u);
                if (lowest_one_bit(I[u]) < lowest_one_bit(I[v])) {
                    I[u] = I[v];
                }
            }
        }
        head[I[u]] = u;
    }

    void init_dfs2(const vector<vector<int>>& tree, int u, int p, int parent) {
        A[u] = parent | lowest_one_bit(I[u]);
        for (int v : tree[u]) {
            if (v != p) {
                init_dfs2(tree, v, u, A[u]);
            }
        }
    }

    int enter_into_strip(int u, int hz) const {
        if (lowest_one_bit(I[u]) == hz)
            return u;
        int hw = highest_one_bit(A[u] & (hz - 1));
        return parent[head[(I[u] & -hw) | hw]];
    }

    int lca(int u, int v) const {
        int hb = I[u] == I[v] ? lowest_one_bit(I[u]) : highest_one_bit(I[u] ^ I[v]);
        int hz = lowest_one_bit(A[u] & A[v] & -hb);
        int eu = enter_into_strip(u, hz);
        int ev = enter_into_strip(v, hz);
        return preorder[eu] < preorder[ev] ? eu : ev;
    }

    int dist(int u, int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};

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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N), tree(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> vis(N);

    y_combinator([&](auto self, int u) -> void {
        vis[u] = true;
        for (int v : graph[u]) {
            if (!vis[v]) {
                tree[u].push_back(v);
                tree[v].push_back(u);
                self(v);
            }
        }
    })(0);

    lca_schieber_vishkin lca(tree, 0);

    int Q;
    cin >> Q;
    vector<array<int, 2>> queries(Q);
    vector<int> deg(N);

    for (auto& [u, v] : queries) {
        cin >> u >> v, u--, v--;
        deg[u]++, deg[v]++;
    }

    int odd = 0;
    for (int u = 0; u < N; u++) {
        odd += deg[u] % 2;
    }

    assert(odd % 2 == 0);
    if (odd > 0) {
        cout << "NO\n";
        cout << odd / 2 << '\n';
        return 0;
    }

    cout << "YES\n";
    for (int q = 0; q < Q; q++) {
        auto [u, v] = queries[q];
        auto path = lca.get_path(u, v);
        int P = path.size();
        int a = lca.lca(u, v);
        cout << P << '\n';
        for (int i = 0; i < P; i++) {
            cout << path[i] + 1 << " \n"[i + 1 == P];
        }
    }

    return 0;
}