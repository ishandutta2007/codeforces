#include <bits/stdc++.h>
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
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> adj(N);
        vector<long> delta(N);
        for (int i = 0; i < N; i++) {
            cin >> delta[i];
        }
        for (int i = 0; i < N; i++) {
            long t;
            cin >> t;
            delta[i] = t - delta[i];
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> depth(N);
        vector<bool> vis(N);
        vector<vector<int>> back(N);
        y_combinator([&](auto self, int u) -> void {
            vis[u] = true;
            for (int v : adj[u]) {
                if (!vis[v]) {
                    depth[v] = depth[u] + 1;
                    self(v);
                } else if (depth[v] < depth[u]) {
                    back[u].push_back(v);
                }
            }
        })(0);
        bool found_odd = false;
        for (int u = 1; u < N; u++) {
            for (int v : back[u]) {
                if (depth[u] % 2 == depth[v] % 2) {
                    found_odd = true;
                    break;
                }
            }
        }
        for (int u = 1; u < N; u++) {
            if (depth[u] % 2 == 0) {
                delta[0] += delta[u];
            } else {
                delta[0] -= delta[u];
            }
        }
        if (found_odd && delta[0] % 2 == 0) {
            cout << "YES\n";
            continue;
        } else if (delta[0] == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}