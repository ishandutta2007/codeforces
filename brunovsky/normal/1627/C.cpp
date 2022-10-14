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
    // Just use 2 and 3 and 5
    // If node has degree 3 we have
    // a+b is prime, a+c is prime, b+c is prime, a,b,c are prime
    // suppose a=2, then b+c is even, contradiction
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<vector<pair<int, int>>> tree(N);
        vector<int> deg(N);
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            tree[u].emplace_back(v, i);
            tree[v].emplace_back(u, i);
            deg[u]++, deg[v]++;
        }

        int M = *max_element(begin(deg), end(deg));
        if (M >= 3) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> me(N);

        y_combinator([&](auto self, int u, int p, int val) -> int {
            for (auto [v, i] : tree[u]) {
                if (v != p) {
                    me[i] = val;
                    val = val == 2 ? 3 : 2;
                    self(v, u, val);
                }
            }
            return val;
        })(0, -1, 2);

        for (int i = 1; i < N; i++) {
            cout << me[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}