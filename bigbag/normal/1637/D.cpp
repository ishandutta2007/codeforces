/**
 *  created: 12/02/2022, 16:56:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 2000111222;
const int max_x = max_n * max_n;

int t, n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int sum_sq = 0, tot = 0;
        for (int i = 0; i < n; ++i) {
            sum_sq += a[i] * a[i];
            sum_sq += b[i] * b[i];
            tot += a[i];
            tot += b[i];
        }
        bitset<max_x> dp;
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            dp = (dp << a[i]) | (dp << b[i]);
        }
        int ans = inf;
        for (int s1 = 0; s1 < max_x; ++s1) {
            if (dp[s1]) {
                int s2 = tot - s1;
                ans = min(ans, s1 * s1 + s2 * s2 + (n - 2) * sum_sq);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}