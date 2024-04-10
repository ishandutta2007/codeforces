#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmax(int& a, int b) { a = max(a, b); }
int bit(int m, int b) { return m >> b & 1; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, x, y;
    cin >> N >> x >> y;
    if (x > y) {
        swap(x, y);
    }

    const int S = min(x + y, N), M = 1 << min(y, N), FULL = M - 1;
    int fit = N / S, rem = N - fit * S;

    vector<int> dp(M), mem(M), ok(M, 1);
    for (int m = 0; m < M; m++) {
        for (int i = 0; i + x < y; i++) {
            if (bit(m, i) && bit(m, i + x)) {
                dp[m] = -S;
                ok[m] = false;
                break;
            }
        }
    }
    for (int n = 1; n <= S; n++) {
        if (n - 1 == rem) {
            mem = dp;
        }
        vector<int> ndp(M, -S);
        for (int m = 0; m < M; m++) {
            int f = m << 1, o = f & FULL;
            if (ok[o])
                setmax(ndp[o], dp[m]);
            if (ok[o | 1] && !bit(f, y))
                setmax(ndp[o | 1], 1 + dp[m]);
        }
        swap(ndp, dp);
    }

    int ans = 0;
    for (int m = 0; m < M; m++) {
        ans = max(ans, fit * dp[m] + mem[m]);
    }
    cout << ans << '\n';
    return 0;
}