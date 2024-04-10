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
    vector<vector<pair<int, int>>> tree(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c, u--, v--, c--;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }

    vector<vector<int>> trail(N);
    vector<int> subt(N, 1), reach(2 * N); // [N,2N) are roots for each color
    for (int i = 0; i < N; i++) {
        trail[i].push_back(i + N);
        reach[i + N] = N;
    }

    y_combinator([&](auto self, int u, int p) -> void {
        for (auto [v, c] : tree[u]) {
            if (v != p) {
                trail[c].push_back(v);
                self(v, u);
                subt[u] += subt[v];
                trail[c].pop_back();
                reach[trail[c].back()] -= subt[v]; // can't cross uv
            }
        }
        reach[u] += subt[u];
    })(0, -1);

    int64_t ans = 0;

    y_combinator([&](auto self, int u, int p) -> void {
        for (auto [v, c] : tree[u]) {
            if (v != p) {
                ans += 1LL * reach[v] * reach[trail[c].back()];
                trail[c].push_back(v);
                self(v, u);
                trail[c].pop_back();
            }
        }
    })(0, -1);

    cout << ans << '\n';
    return 0;
}

// based on jiangly sub