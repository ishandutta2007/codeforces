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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> color(N);
    for (int i = 0; i < N; i++) {
        cin >> color[i];
    }

    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parent(N), blacks(N);

    y_combinator([&](auto self, int u, int p = -1) -> void {
        parent[u] = p;
        blacks[u] += color[u] == 1;
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
                blacks[u] += blacks[v];
            }
        }
    })(0, -1);

    vector<vector<int>> adj(N);

    for (int v = 1; v < N; v++) {
        int u = parent[v];
        if (color[v] == 1 || blacks[v] >= 2) {
            adj[v].push_back(u);
        }
        if (color[u] == 1 || blacks[0] - blacks[v] >= 2) {
            adj[u].push_back(v);
        }
    }

    vector<int> ans = color;
    vector<int> bfs;
    int S = 0;

    for (int u = 0; u < N; u++) {
        if (color[u] == 1) {
            bfs.push_back(u), S++;
        }
    }

    for (int i = 0; i < S; i++) {
        int u = bfs[i];
        for (int v : adj[u]) {
            if (ans[v] == 0) {
                ans[v] = 1;
                bfs.push_back(v), S++;
            }
        }
    }

    for (int u = 0; u < N; u++) {
        cout << ans[u] << " \n"[u + 1 == N];
    }

    return 0;
}