#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

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

const int max_f = 200222;

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

const int max_n = 200222;

int n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[(i + 1) % n]) {
            ++cnt;
        }
    }
    int rk = inv((k + mod - 2) % mod);
    int ans = 0;
    if (k == 1) {
    } else if (k == 2) {
        for (int i = 1; i <= cnt; ++i) {
            if (i > cnt - i) {
                int add = get_c(cnt, i);
                ans += add;
                ans %= mod;
            }
        }
        ans = mul(ans, power(k, n - cnt));
    } else {
        ans = power(k, n);
        for (int i = 0; i <= cnt; ++i) {
            if ((cnt - i) % 2 == 0) {
                int eq = (cnt - i) / 2;
                int add = get_c(cnt, eq);
                add = mul(add, get_c(cnt - eq, eq));
                add = mul(add, power(k, n - cnt));
                add = mul(add, power(k - 2, i));
                add = (mod - add) % mod;
                ans += add;
                ans %= mod;
            }
        }
        ans = mul(ans, inv(2));
    }
    printf("%d\n", ans);
    return 0;
}