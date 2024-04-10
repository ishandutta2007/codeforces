/**
 *  created: 19/12/2020, 11:43:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, max_x = 10011, inf = 1000111222;

int n, a[max_n], b[max_n];
int dp[max_n][max_x];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < max_x; ++j) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;
    cin >> n;
    int totb = 0, tota = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i] >> a[i];
        for (int cnt = i; cnt >= 0; --cnt) {
            for (int sb = 0; sb <= totb; ++sb) {
                dp[cnt + 1][sb + b[i]] = max(dp[cnt + 1][sb + b[i]], dp[cnt][sb] + a[i]);
            }
        }
        tota += a[i];
        totb += b[i];
    }
    for (int k = 1; k <= n; ++k) {
        int ans = 0;
        for (int sb = 0; sb <= totb; ++sb) {
            ans = max(ans, min(2 * sb, tota + dp[k][sb]));
        }
        cout << ans / 2 << "." << 5 * (ans % 2) << " ";
    }
    cout << "\n";
    return 0;
}