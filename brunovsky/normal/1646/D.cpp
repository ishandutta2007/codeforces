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
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if (N == 2) {
        cout << "2 2\n1 1\n";
        return 0;
    }

    vector<pair<int, int>> dp_yes(N);
    vector<pair<int, int>> dp_no(N);
    vector<int> w(N);

    y_combinator([&](auto self, int u, int p = -1) -> void {
        for (int v : tree[u]) {
            if (v != p) {
                self(v, u);
            }
        }
        for (int v : tree[u]) {
            auto a = dp_no[v];
            auto b = max(dp_yes[v], dp_no[v]);
            dp_yes[u].first += a.first;
            dp_yes[u].second += a.second;
            dp_no[u].first += b.first;
            dp_no[u].second += b.second;
        }
        dp_yes[u].first++;
        dp_yes[u].second -= tree[u].size();
    })(0);

    y_combinator([&](auto self, int u, int cant, int p = -1) -> void {
        bool take = !cant && dp_yes[u] > dp_no[u];
        w[u] = take ? tree[u].size() : 1;
        for (int v : tree[u]) {
            if (v != p) {
                self(v, take, u);
            }
        }
    })(0, dp_yes[0].first < dp_no[0].first);

    int count = max(dp_yes[0].first, dp_no[0].first);
    int64_t cost = accumulate(begin(w), end(w), 0LL);

    cout << count << ' ' << cost << '\n';
    for (int u = 0; u < N; u++) {
        cout << w[u] << " \n"[u + 1 == N];
    }
    return 0;
}