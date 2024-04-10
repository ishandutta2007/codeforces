#include <bits/stdc++.h>

using namespace std;

int mod = 1000000007;

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

const int max_f = 250555;

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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n >> mod;
    get_all_f();
    int ans = 0;
    for (int len = 1; len <= n; ++len) {
        int add = mul(n - len + 1, n - len + 1);
        add = mul(add, f[len]);
        add = mul(add, f[n - len]);
        ans += add;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}