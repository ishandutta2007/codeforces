#include <bits/stdc++.h>

using namespace std;

const int max_n = 66, mod = 1000000007;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(mul(x, x), y / 2);
    }
    return mul(x, power(x, y - 1));
}

int k, dp[2][max_n], rev[max_n];
long long n;
vector<long long> a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        int c = 0;
        while (n % i == 0) {
            ++c;
            n /= i;
        }
        if (c) {
            a.push_back(i);
            b.push_back(c);
        }
    }
    if (n > 1) {
        a.push_back(n);
        b.push_back(1);
    }
    for (int i = 1; i < max_n; ++i) {
        rev[i] = power(i, mod - 2);
    }
    int ans = 1;
    for (int i = 0; i < b.size(); ++i) {
        memset(dp, 0, sizeof(dp));
        int q1 = 0, q2 = 1;
        dp[q1][b[i]] = 1;
        for (int it = 0; it < k; ++it) {
            memset(dp[q2], 0, sizeof(dp[q2]));
            for (int q = 0; q <= b[i]; ++q) {
                for (int w = 0; w <= q; ++w) {
                    dp[q2][w] += mul(dp[q1][q], rev[q + 1]);
                    dp[q2][w] %= mod;
                }
            }
            swap(q1, q2);
        }
        int res = 0;
        int x = 1;
        for (int j = 0; j <= b[i]; ++j) {
            res += mul(x, dp[q1][j]);
            res %= mod;
            x = mul(x, a[i] % mod);
        }
        ans = mul(ans, res);
    }
    cout << ans << endl;
    return 0;
}