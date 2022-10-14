#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

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

auto build_tree_centroid_decomposition(const vector<vector<int>>& tree) {
    int V = tree.size();
    vector<int> subsize(V), cparent(V);
    vector<bool> mark(V, false);
    int marked = 0;

    auto dfs_centroid = y_combinator([&](auto self, int S, int u, int p, int cp) -> bool {
        subsize[u] = 1;
        bool is = true;
        for (int v : tree[u]) {
            if (v != p && !mark[v]) {
                if (self(S, v, u, cp)) {
                    return true;
                } else {
                    subsize[u] += subsize[v];
                    is &= subsize[v] <= S / 2;
                }
            }
        }
        if (is && S - subsize[u] <= S / 2) {
            mark[u] = true, cparent[u] = cp, marked++;
            for (int v : tree[u]) {
                if (v != p && !mark[v]) {
                    self(subsize[v], v, u, u);
                } else if (v == p && !mark[v]) {
                    self(S - subsize[u], v, u, u);
                }
            }
            return true;
        }
        return false;
    });

    dfs_centroid(V, 0, -1, -1);
    assert(marked == V);
    return cparent;
}

auto solve() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto cparent = build_tree_centroid_decomposition(adj);
    vector<vector<int>> cchildren(N);
    int root = -1;
    for (int u = 0; u < N; u++) {
        if (cparent[u] == -1) {
            root = u;
        } else {
            cchildren[cparent[u]].push_back(u);
        }
    }
    vector<int> bfs(N);
    vector<char> name(N);
    int i = 0, S = 1;
    bfs[0] = root;
    name[root] = 'A';
    while (i < S) {
        int u = bfs[i++];
        for (int v : cchildren[u]) {
            bfs[S++] = v;
            name[v] = name[u] + 1;
        }
    }
    for (int u = 0; u < N; u++) {
        cout << name[u] << " \n"[u + 1 == N];
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}