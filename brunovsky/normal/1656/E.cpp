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
        int N;
        cin >> N;
        vector<vector<int>> tree(N);
        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v, u--, v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // find some leaf
        int leaf = -1;
        for (int i = 0; i < N; i++) {
            if (tree[i].size() == 1u) {
                leaf = i;
                break;
            }
        }

        // Let k be the value of this leaf
        // Let S be the sum of all the values

        vector<int> val(N);
        val[leaf] = 1;

        // value at u is x[u]S+y[u]k

        y_combinator([&](auto self, int u, int p, int X) -> void {
            // T + CX = S <=> T = S - CX
            int C = tree[u].size();
            val[u] = -C * X;
            X += val[u] + (C - 2) * X;
            for (int v : tree[u]) {
                if (v != p) {
                    self(v, u, X);
                }
            }
        })(tree[leaf][0], leaf, 1);

        for (int u = 0; u < N; u++) {
            cout << val[u] << " \n"[u + 1 == N];
        }
    }
    return 0;
}

// Let the sum be S, which doesn't have to be small
// Suppose there are C components remaining and we're at u with value V
// V + Cx = S <=> x = (S - V) / C