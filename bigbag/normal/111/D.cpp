#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, max_k = 1111111, mod = 1000000007;

int n, m, k, dp[max_n][max_n], f[max_k], rf[max_k];

long long power(long long x, long long y, long long mod) {
    if (y == 0) {
        return 1 % mod;
    }
    if (y % 2 == 0) {
        return power((x * x) % mod, y / 2, mod);
    }
    return (x * power(x, y - 1, mod)) % mod;
}

int get_c(int n, int k) {
    return (1LL * ((1LL * f[n] * rf[k]) % mod) * rf[n - k]) % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    if (m == 1) {
        cout << power(k, n, mod) << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 1;
        for (int j = 2; j <= i; ++j) {
            dp[i][j] = (1LL * dp[i - 1][j] * j + dp[i - 1][j - 1]) % mod;
        }
    }
    f[0] = 1;
    rf[0] = 1;
    for (int i = 1; i < max_k; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
        rf[i] = power(f[i], mod - 2, mod);
    }
    int ans = 0;
    for (int y = 1; y <= n; ++y) {
        for (int x = 0; x <= y; ++x) {
            if (2 * y - x <= k) {
                int pl = get_c(k, 2 * y - x);
                pl = (1LL * pl * get_c(2 * y - x, y - x)) % mod;
                pl = (1LL * pl * get_c(y, x)) % mod;
                pl = (1LL * pl * power(x, n * (m - 2), mod)) % mod;
                pl = (1LL * pl * dp[n][y]) % mod;
                pl = (1LL * pl * dp[n][y]) % mod;
                pl = (1LL * pl * f[y]) % mod;
                pl = (1LL * pl * f[y]) % mod;
                //cout << y << " " << x << "  +=  " << pl << endl;
                ans = (ans + pl) % mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}