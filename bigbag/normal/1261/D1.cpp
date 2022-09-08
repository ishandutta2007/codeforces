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
    for (int i = 1; i <= cnt; ++i) {
        int st = 0;
        if (k == 2) {
            st = cnt - i;
        }
        int pw = power(k - 2, cnt - i - st);
        for (int j = st; j < i && i + j <= cnt; ++j) {
            int add = get_c(cnt, i);
            add = mul(add, get_c(cnt - i, j));
            add = mul(add, pw);
            ans += add;
            ans %= mod;
            //cout << i << " " << j << ": " << add << endl;
            pw = mul(pw, rk);
        }
    }
    ans = mul(ans, power(k, n - cnt));
    printf("%d\n", ans);
    return 0;
}