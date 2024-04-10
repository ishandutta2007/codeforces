#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        a.erase(unique(begin(a), end(a)), end(a));
        N = a.size();

        multiset<array<int, 3>> vals;
        for (int i = 0; i < N; i++) {
            vals.insert({a[i], a[i], 1});
        }

        int ans = (*vals.rbegin())[0] - (*vals.begin())[0];
        while (ans > 0 && (*vals.rbegin())[2] < K) {
            auto [n, v, k] = *vals.rbegin();
            vals.erase(prev(end(vals)));
            int m = min(K, (v + n) / n);
            vals.insert({v / m, v, m});
            ans = min(ans, (*vals.rbegin())[0] - (*vals.begin())[0]);
        }
        cout << ans << '\n';
    }

    return 0;
}