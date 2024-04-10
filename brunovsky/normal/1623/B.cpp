#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

using A = array<int, 2>;

struct rev_compare {
    inline bool operator()(A a, A b) const {
        return make_pair(a[0], -a[1]) < make_pair(b[0], -b[1]);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<A> ranges(N);
        for (auto& [l, r] : ranges) {
            cin >> l >> r;
        }

        sort(begin(ranges), end(ranges), rev_compare{});

        vector<array<int, 3>> ans(N);

        for (int i = 0; i + 1 < N; i++) {
            auto [l, r] = ranges[i];
            auto [a, b] = ranges[i + 1];
            if (a == l) {
                ans[i] = {l, r, b + 1};
            } else {
                ans[i] = {l, r, l};
            }
        }

        int u = ranges[N - 1][0];
        ans[N - 1] = {u, u, u};

        for (auto [l, r, d] : ans) {
            cout << l << ' ' << r << ' ' << d << '\n';
        }
        cout << '\n';
    }
    return 0;
}