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
    vector<int> p(N);
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        cin >> p[i], p[i]--;
        tree[p[i]].push_back(i);
    }

    vector<int> subt(N, 1);
    y_combinator([&](auto self, int u) -> void {
        for (int v : tree[u]) {
            self(v);
            subt[u] += subt[v];
        }
    })(0);

    vector<double> val(N, 0);

    y_combinator([&](auto self, int u) -> void {
        // S kids
        // avg[0] = 0/(S-1) * sum
        // avg[i] = 1/(S-1) * sum
        // avg[S-1] = (S-1)/(S-1) * sum
        // sum/(S-1) * (S-1)*S/2
        int S = tree[u].size();
        if (S == 0) {
            return;
        }
        if (S == 1) {
            int v = tree[u][0];
            val[v] = val[u] + 1;
            return self(v);
        }
        for (int v : tree[u]) {
            int sum = subt[u] - subt[v] - 1;
            val[v] = 1 + val[u] + 1.0 * sum / 2;
            self(v);
        }
    })(0);

    cout << setprecision(9) << showpoint << fixed;

    for (int i = 0; i < N; i++) {
        cout << 1 + val[i] << " \n"[i + 1 == N];
    }
    return 0;
}