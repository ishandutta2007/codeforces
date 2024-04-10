#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmin(int64_t& a, int64_t b) { a = min(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> d(N + 1), a(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    d[N] = L;

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(K + 1, INT64_MAX / 2));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        // We do not remove anything
        for (int k = 0; k <= K; k++) {
            setmin(dp[i + 1][k], dp[i][k] + (d[i + 1] - d[i]) * a[i]);
        }
        // We remove this stop and m-1 before
        for (int m = 1; m <= min(i, K); m++) {
            for (int k = 0; k + m <= K; k++) {
                int j = i - m;
                setmin(dp[i + 1][m + k], dp[j][k] + (d[i + 1] - d[j]) * a[j]);
            }
        }
    }

    auto ans = *min_element(begin(dp[N]), end(dp[N]));
    cout << ans << '\n';
    return 0;
}