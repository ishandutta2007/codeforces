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
    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> constraints(M);
    vector<vector<int>> g(N);
    for (auto& [t, u, v] : constraints) {
        cin >> t >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(N, -1);
    auto dfs = y_combinator([&](auto self, int u, int c) -> bool {
        color[u] = c;
        for (int v : g[u]) {
            if (color[v] != -1 && color[u] == color[v]) {
                return false;
            } else if (color[v] == -1) {
                if (!self(v, 1 - c)) {
                    return false;
                }
            }
        }
        return true;
    });

    for (int u = 0; u < N; u++) {
        if (color[u] == -1) {
            if (!dfs(u, 0)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    vector<vector<int>> dag(N);
    for (auto [t, u, v] : constraints) {
        assert(color[u] != color[v]);
        if (t == 1 && color[u] == 0) {
            dag[v].push_back(u);
        } else if (t == 1 && color[u] == 1) {
            dag[u].push_back(v);
        } else if (t == 2 && color[u] == 0) {
            dag[u].push_back(v);
        } else if (t == 2 && color[u] == 1) {
            dag[v].push_back(u);
        }
    }

    vector<int> indeg(N);
    for (int u = 0; u < N; u++) {
        for (int v : dag[u]) {
            indeg[v]++;
        }
    }

    vector<int> topo(N), index(N);
    int B = 0;
    for (int u = 0; u < N; u++) {
        if (indeg[u] == 0) {
            index[u] = B;
            topo[B++] = u;
        }
    }
    for (int i = 0; i < B; i++) {
        int u = topo[i];
        for (int v : dag[u]) {
            if (--indeg[v] == 0) {
                index[v] = B;
                topo[B++] = v;
            }
        }
    }
    if (B < N) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int u = 0; u < N; u++) {
        cout << (color[u] ? "L" : "R") << ' ' << index[u] << '\n';
    }
    return 0;
}