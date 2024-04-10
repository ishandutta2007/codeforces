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

auto solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> mark(N, 0);
    vector<int> good;
    int marked = 0;

    auto dfs = y_combinator([&](auto self, int u) -> void {
        bool found_center = false;
        for (int v : g[u]) {
            found_center |= mark[v] == 1;
        }
        if (!found_center) {
            mark[u] = 1;
            good.push_back(u);
        } else {
            mark[u] = 2;
        }
        marked++;
        for (int v : g[u]) {
            if (!mark[v]) {
                self(v);
            }
        }
    });
    dfs(0);
    if (marked < N) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int G = good.size();
        cout << G << endl;
        for (int u = 0; u < G; u++) {
            cout << good[u] + 1 << " \n"[u + 1 == G];
        }
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}