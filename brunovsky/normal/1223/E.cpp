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
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<vector<pair<int, int>>> tree(N);
        for (int i = 1; i < N; i++) {
            int u, v, w;
            cin >> u >> v >> w, u--, v--;
            tree[u].emplace_back(v, w);
            tree[v].emplace_back(u, w);
        }
        auto ans = y_combinator([&](auto self, int u, int p, int c) -> array<int64_t, 2> {
            vector<int64_t> kids;
            int64_t base = 0;
            for (auto [v, w] : tree[u]) {
                if (v != p) {
                    auto [a, b] = self(v, u, w);
                    kids.push_back(max<int64_t>(b - a, 0));
                    base += a;
                }
            }
            int S = kids.size();
            if (S == 0) {
                return {0, c};
            }
            sort(rbegin(kids), rend(kids));
            auto nop = base + accumulate(begin(kids), begin(kids) + min(S, K), 0LL);
            auto yes = base + accumulate(begin(kids), begin(kids) + min(S, K - 1), 0LL);
            return {nop, yes + c};
        })(0, -1, 0);
        cout << max(ans[0], ans[1]) << '\n';
    }
    return 0;
}