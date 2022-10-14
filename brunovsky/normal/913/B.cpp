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
        int p;
        cin >> p, p--;
        tree[p].push_back(i);
    }
    bool ok = true;
    y_combinator([&](auto self, int u, int p) -> int {
        int leaf = 1, cnt = 0;
        for (int v : tree[u]) {
            if (v != p) {
                cnt += self(v, u);
                leaf = 0;
            }
        }
        ok &= leaf || cnt >= 3;
        return leaf;
    })(0, -1);
    cout << (ok ? "Yes\n" : "No\n");
    return 0;
}