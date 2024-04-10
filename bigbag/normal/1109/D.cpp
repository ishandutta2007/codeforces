#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 1000000007;

int power(int a, int b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2);
    }
    return (1LL * a * power(a, b - 1)) % mod;
}

int f[max_n], rf[max_n];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * i * f[i - 1]) % mod;
    }
    rf[max_n - 1] = power(f[max_n - 1], mod - 2);
    for (int i = max_n - 2; i > 0; --i) {
        rf[i] = (1LL * (i + 1) * rf[i + 1]) % mod;
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = (1LL * f[n] * rf[k]) % mod;
    return (1LL * res * rf[n - k]) % mod;
}

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int n, m, a, b, pwm[max_n];
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    cin >> n >> m >> a >> b;
    pwm[0] = 1;
    for (int i = 1; i < n; ++i) {
        pwm[i] = mul(pwm[i - 1], m);
    }
    for (int l = 1; l <= m && l < n; ++l) {
        int x = get_c(m - 1, l - 1);

        x = mul(x, get_c(n - 2, l - 1));
        x = mul(x, f[l - 1]);

        x = mul(x, pwm[n - 1 - l]);

        int N = n - l - 1;
        if (N) {
            x = mul(x, l + 1);
            x = mul(x, power(l + N + 1, N - 1));
        }

        ans += x;
        if (ans >= mod) {
            ans -= mod;
        }
    }
    cout << ans << endl;
    return 0;
}