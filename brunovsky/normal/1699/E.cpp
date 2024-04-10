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
        int N, M;
        cin >> N >> M;
        vector<int8_t> input(M + 1);
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            input[a] = true;
        }

        vector<int> count(M + 1);
        int lo = M, hi = 0;
        for (int v = 1; v <= M; v++) {
            if (input[v]) {
                count[v]++;
                lo = min(lo, v);
                hi = max(hi, v);
            }
        }

        vector<int> dp(M + 1);
        iota(begin(dp), end(dp), 0);
        int ans = M - 1;

        for (int i = M; i >= 1; i--) {
            for (int v = i; 1LL * i * v <= M; v++) {
                if (dp[i * v] > dp[v]) {
                    count[dp[i * v]] -= input[i * v];
                    dp[i * v] = dp[v];
                    count[dp[i * v]] += input[i * v];
                }
            }
            while (count[hi] == 0) {
                hi--;
            }
            if (i <= lo) {
                ans = min(ans, hi - i);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

// based on jiangly sub