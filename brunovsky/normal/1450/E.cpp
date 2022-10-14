#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmin(int& a, int b) { a = min(a, b); }

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
    vector<array<int, 3>> friends(M);
    for (auto& [u, v, b] : friends) {
        cin >> u >> v >> b, u--, v--;
    }
    vector<vector<pair<int, int>>> adj(N);
    for (auto [u, v, b] : friends) {
        if (b == 1) {
            adj[u].emplace_back(v, +1);
            adj[v].emplace_back(u, -1);
        } else {
            adj[u].emplace_back(v, +1);
            adj[v].emplace_back(u, +1);
        }
    }

    const int inf = INT_MAX / 5;
    vector<vector<int>> dist(N, vector<int>(N, inf));
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int u = 0; u < N; u++) {
        for (auto [v, c] : adj[u]) {
            setmin(dist[u][v], c);
        }
    }

    for (int k = 0; k < N; k++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                setmin(dist[u][v], dist[u][k] + dist[k][v]);
            }
            if (dist[u][u] < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    vector<int> color(N, -1);
    color[0] = 0;
    y_combinator([&](auto self, int u) -> void {
        for (auto [v, _] : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                self(v);
            }
            if (color[u] == color[v]) {
                cout << "NO\n";
                exit(0);
            }
        }
    })(0);

    int a = 0, b = 0;
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (dist[u][v] > dist[a][b]) {
                a = u, b = v;
            }
        }
    }

    cout << "YES\n";
    cout << dist[a][b] << '\n';
    for (int u = 0; u < N; u++) {
        cout << dist[a][u] << " \n"[u + 1 == N];
    }
    return 0;
}