#include <bits/stdc++.h>

using namespace std;

const int max_n = 2000111, mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

const int max_f = 4000222;

int f[max_f], rf[max_f];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        f[i] = mul(i, f[i - 1]);
    }
    rf[max_f - 1] = inv(f[max_f - 1]);
    for (int i = max_f - 2; i > 0; --i) {
        rf[i] = mul(i + 1, rf[i + 1]);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

string str_fraq(int x, int n = 20) {
    stringstream res;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (i == mul(x, j)) {
                res << i << "/" << j;
                return res.str();
            }
        }
    }
    res << x;
    return res.str();
}

int n, m, dp[max_n];
int im1;

int func(int k) {
    return mul(k, im1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    cin >> n >> m;
    im1 = inv(m + 1);
    int sum = 0;
    for (int x = 1; x <= n; ++x) {
        const int k = n - x;
        dp[x] = (func(k) + 1) % mod;

        dp[x] += mul(f[x], mul(f[m], mul(rf[x + m], sum)));
        dp[x] %= mod;

        const int C0 = mul(rf[x + m], mul(f[x], mul(f[m], get_c(m - 1 + x, m - 1))));
        int coef = (1 + mod - C0) % mod;

        dp[x] += func(x);
        dp[x] %= mod;
        dp[x] = mul(dp[x], inv(coef));
        sum += mul(dp[x], get_c(m - 1 + x, x));
        sum %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}