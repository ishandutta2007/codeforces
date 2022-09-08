#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, mod = 998244353;
const int max_x = 100111;

int n, k, a[max_n], dp[max_n][max_n], res[max_x];
int ans;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int x = a[n] / (k - 1); x >= 1; --x) {
        dp[0][0] = 1;
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            while (a[i] - a[pos + 1] >= x) {
                ++pos;
            }
            dp[i][0] = 1;
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[pos][j - 1]) % mod;
            }
        }
        res[x] = dp[n][k];
        ans += mul(res[x] + mod - res[x + 1], x);
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}