#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    int64_t L;
    cin >> N >> L;
    vector<int64_t> c(N);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    vector<int64_t> dp(32);
    dp[0] = c[0];
    for (int i = 1; i < 32; i++) {
        dp[i] = i < N ? min(c[i], 2 * dp[i - 1]) : 2 * dp[i - 1];
    }
    int64_t ans = INT64_MAX;
    do {
        int64_t cost = 0;
        for (int i = 0; i < 32; i++) {
            cost += (L >> i & 1) ? dp[i] : 0;
        }
        ans = min(ans, cost);
        L += 1LL << __builtin_ctzll(L);
    } while (L <= (1LL << 30));

    cout << ans << '\n';
    return 0;
}