#include <iostream>

using namespace std;

const int max_n = 202222, mod = 1000000007;

int q1, q2, r, g, last_ans, dp[2][max_n];

int main() {
    cin >> r >> g;
    q1 = 0;
    q2 = 1;
    dp[0][r] = 1;
    for (int i = 0; ; ++i) {
        //cout << i << ": " << endl;
        int ans = 0;
        for (int j = 0; j <= r; ++j) {
            dp[q2][j] = 0;
        }
        for (int j = 0; j <= r; ++j) {
            //cout << dp[q1][j] << " ";
            int k = g - ((i * (i + 1)) / 2 - (r - j));
            if (k > i) {
                dp[q2][j] += dp[q1][j];
                if (dp[q2][j] >= mod) dp[q2][j] -= mod;
            }
            if (j > i) {
                dp[q2][j - i - 1] += dp[q1][j];
                if (dp[q2][j - i - 1] >= mod) dp[q2][j - i - 1] -= mod;
            }
            //ans += dp[q2][j];
        }
        for (int j = 0; j <= r; ++j) {
            ans += dp[q2][j];
            if (ans >= mod) ans -= mod;
        }
        //cout << "  " << ans << endl;
        if (ans == 0) {
            cout << last_ans << endl;
            return 0;
        }
        last_ans = ans;
        swap(q1, q2);
    }
    return 0;
}