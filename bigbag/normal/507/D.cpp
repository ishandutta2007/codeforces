
#include <iostream>

using namespace std;

int n, k, m, dp[1111][1111][2];

int main() {
    cin >> n >> k >> m;
    int st = 0;
    if (n == 1) {
        st = 1;
    }
    for (int i = st; i <= 9; ++i) {
        ++dp[1][i % k][(i && (i % k == 0))];
    }
    long long pw = 1;
    for (int i = 1; i < n; ++i) {
        pw = (pw * 10) % k;
        for (int j = 0; j < k; ++j) {
            for (int f = 0; f < 2; ++f) {
                st = 0;
                if (i + 1 == n) {
                    st = 1;
                }
                for (int digit = st; digit <= 9; ++digit) {
                    int o = (digit * pw + j) % k;
                    dp[i + 1][o][(f || (digit && o == 0))] += dp[i][j][f];
                    dp[i + 1][o][(f || (digit && o == 0))] %= m;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans = (ans + dp[n][i][1]) % m;
    }
    cout << ans << endl;
    return 0;
}