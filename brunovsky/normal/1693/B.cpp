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
        vector<int> parent(N, -1);
        vector<vector<int>> tree(N);
        for (int i = 1; i < N; i++) {
            cin >> parent[i], parent[i]--;
            tree[parent[i]].push_back(i);
        }
        vector<int64_t> l(N), r(N);
        for (int i = 0; i < N; i++) {
            cin >> l[i] >> r[i];
        }
        int ops = 0;
        y_combinator([&](auto self, int u, int p) -> int64_t {
            int64_t sum = 0;
            for (int v : tree[u]) {
                if (v != p) {
                    sum += self(v, u);
                }
            }
            if (sum < l[u]) {
                ops++;
                return r[u];
            } else {
                return min(sum, r[u]);
            }
        })(0, -1);
        cout << ops << '\n';
    }
    return 0;
}