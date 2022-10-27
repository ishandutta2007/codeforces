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

void solve() {
    int N, paths;
    cin >> N >> paths;

    vector<int> parent(N);
    vector<vector<int>> tree(N);
    for (int i = 1; i < N; i++) {
        cin >> parent[i];
        parent[i]--;
        tree[parent[i]].push_back(i);
    }

    vector<int64_t> score(N);
    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    vector<int64_t> lo(N), hi(N);

    y_combinator([&](auto self, int u, int k) -> void {
        lo[u] = k * score[u];
        hi[u] = (k + 1) * score[u];

        int s = tree[u].size();
        if (s == 0) {
            return;
        }
        int each = k / s;
        int more = k - each * s;
        assert(0 <= more && more < s);

        vector<int64_t> add;
        int64_t sum = 0;
        for (int v : tree[u]) {
            self(v, each);
            sum += lo[v];
            add.push_back(hi[v] - lo[v]);
        }
        sort(rbegin(add), rend(add));
        lo[u] += sum + accumulate(begin(add), begin(add) + more, 0LL);
        hi[u] += sum + accumulate(begin(add), begin(add) + more + 1, 0LL);
    })(0, paths);

    cout << lo[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}