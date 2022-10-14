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
    int N;
    cin >> N;
    vector<vector<int>> tree(N);
    vector<int> l(N), r(N);
    for (int i = 0; i < N; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    // dp[u][0] -> we pick low
    // dp[u][1] -> we pick high
    vector<array<long, 2>> dp(N);

    auto dfs = y_combinator([&](auto self, int u, int p) -> void {
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
                dp[u][0] += max(abs(l[u] - l[v]) + dp[v][0], abs(l[u] - r[v]) + dp[v][1]);
                dp[u][1] += max(abs(r[u] - l[v]) + dp[v][0], abs(r[u] - r[v]) + dp[v][1]);
            }
        }
    });

    dfs(0, -1);
    return max(dp[0][0], dp[0][1]);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}