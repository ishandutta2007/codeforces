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

struct min_map : map<int, int> {
    // Insert (i,v) for all i<=key
    void adjust(int key, int v) {
        auto it = lower_bound(key);
        while (it != end() && v < it->second) {
            it = erase(it);
        }
        if (it != end() && key == it->first) {
            return;
        }
        if (it == begin() || v < prev(it)->second) {
            emplace_hint(it, key, v);
        }
    }

    // Query minimum over range [0,key]
    int query(int key, int bad) const {
        auto it = upper_bound(key);
        return it == begin() ? bad : prev(it)->second;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> runs(M);
    vector<vector<int>> by_length(N + 1);
    for (int i = 0; i < M; i++) {
        auto& [l, r] = runs[i];
        cin >> l >> r, l--;
        by_length[r - l].push_back(i);
    }
    vector<min_map> seg(4 * N);
    vector<int> leaf(N);
    y_combinator([&](auto self, int i, int l, int r) -> void {
        if (l + 1 == r) {
            leaf[l] = i;
        } else {
            int m = (l + r) / 2;
            self(i << 1, l, m);
            self(i << 1 | 1, m, r);
        }
    })(1, 0, N);
    auto insert = [&](int l, int r, int t) -> void {
        int i = leaf[l];
        while (i > 0) {
            seg[i].adjust(r, t);
            i >>= 1;
        }
    };
    auto query = y_combinator([&](auto self, int i, int l, int r, int L, int R) -> int {
        if (r <= L || R <= l) {
            return M;
        }
        if (L <= l && r <= R) {
            return seg[i].query(R, M);
        }
        int m = (l + r) / 2;
        return min(self(i << 1, l, m, L, R), self(i << 1 | 1, m, r, L, R));
    });
    vector<int> ans(N + 1);
    for (int x = N; x >= 1; x--) {
        for (int i : by_length[x]) {
            auto [l, r] = runs[i];
            insert(l, r, i);
        }
        y_combinator([&](auto self, int L, int R) -> void {
            if (R - L < x) {
                return;
            }
            int i = query(1, 0, N, L, R);
            if (i < M) {
                auto [l, r] = runs[i];
                assert(L <= l && r <= R);
                ans[x] += r - l;
                self(L, l);
                self(r, R);
            }
        })(0, N);
    }
    for (int x = 1; x <= N; x++) {
        cout << ans[x] << '\n';
    }
    return 0;
}