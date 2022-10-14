#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
    vector<vector<pair<int, int>>> adj(N + 1);
    vector<array<int, 2>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(i, v);
        adj[v].emplace_back(i, u);
        edges[i] = {u, v};
    }
    vector<bool> paired(M);
    vector<bool> vis(N + 1);
    vector<pair<int, int>> pairings;
    auto dfs = y_combinator([&](auto self, int u, int p) -> void {
        vis[u] = true;
        for (auto [e, v] : adj[u]) {
            if (e != p && !vis[v]) {
                self(v, e);
            }
        }
        vector<int> available;
        for (auto [e, v] : adj[u]) {
            if (e != p && !paired[e]) {
                available.push_back(e);
            }
        }
        int A = available.size();
        for (int i = 0; i + 1 < A; i += 2) {
            pairings.emplace_back(available[i], available[i + 1]);
            paired[available[i]] = true;
            paired[available[i + 1]] = true;
        }
        if ((A & 1) && p != -1 && !paired[p]) {
            int e = available.back();
            pairings.emplace_back(e, p);
            paired[e] = true;
            paired[p] = true;
        }
    });
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) {
            dfs(u, -1);
        }
    }
    cout << pairings.size() << '\n';
    for (auto [a, b] : pairings) {
        auto [u, v] = edges[a];
        auto [w, x] = edges[b];
        if (u == w) {
            swap(u, v);
        } else if (u == x) {
            swap(u, v), swap(w, x);
        } else if (v == x) {
            swap(w, x);
        }
        assert(v == w);
        cout << u << ' ' << w << ' ' << x << '\n';
    }
    return 0;
}