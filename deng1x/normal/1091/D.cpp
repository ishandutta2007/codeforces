#include <bits/stdc++.h>

const int mod = 998244353;
const int MAXN = 1000010;

int n;
int fact[MAXN], inv[MAXN], c[MAXN];

int powmod(int a, int b) {
    int ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = 1ll * ret * a % mod;
        a = 1ll * a * a % mod;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
    inv[MAXN - 1] = powmod(fact[MAXN - 1], mod - 2);
    for (int i = MAXN - 1 - 1; ~i; --i) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    }

    int ans = fact[n];
    for (int i = 1; i <= n; ++i) {
        c[i] = 1ll * fact[n] * inv[i] % mod * inv[n - i] % mod * fact[n - i] % mod;
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = (c[i] - c[i + 1] + mod) % mod;
        if (i != n) ans = (ans + 1ll * c[i] * (n - i - 1)) % mod;
    }
    printf("%d\n", ans);
    return 0;
}