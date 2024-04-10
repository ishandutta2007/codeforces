#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, mod = 998244353;

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
    x %= mod;
    return power(x, mod - 2);
}

int n, s, a[max_n], dp[max_n];
int A[max_n], B[max_n], C[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    const int rs = inv(s);
    for (int x = 0; x < s; ++x) {
        const int coef = inv(1 + mod - mul(s - x, mul(rs, mul(n - 2, inv(n - 1)))));
        A[x] = mul(coef, mul(x, rs));
        B[x] = mul(coef, mul(s - x, mul(rs, inv(n - 1))));
        C[x] = coef;
    }
    for (int x = 1; x < s; ++x) {
        int nb, nc;
        const int coef = inv(mod + 1 - mul(A[x], B[x - 1]));
        nb = mul(coef, B[x]);
        nc = mul(coef, mul(A[x], C[x - 1]) + C[x]);
        A[x] = 0;
        B[x] = nb;
        C[x] = nc;
    }
    for (int x = s - 1; x >= 0; --x) {
        dp[x] = (mul(B[x], dp[x + 1]) + C[x]) % mod;
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        tot += dp[a[i]];
        tot %= mod;
    }
    int ans = mul(n, tot + mod - mul(n - 1, dp[0]));
    ans = mul(ans, inv(mul(n, n)));
    printf("%d\n", ans);
    return 0;
}