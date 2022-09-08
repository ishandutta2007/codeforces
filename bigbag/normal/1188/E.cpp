#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 998244353;

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

const int max_f = 2 * max_n;

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

int n, a[max_n];

int func(int x, int z) {
    if (x < 0) {
        return 0;
    }
    int res = 0;
    res += get_c(x + n - 1, n - 1);
    res %= mod;
    if (x >= z) {
        res += mod - get_c(x - z + n - 1, n - 1);
        res %= mod;
    }
    return res;
}

int triv() {
    const int mx = *max_element(a, a + n);
    int ans = 0;
    for (int cnt = 0; cnt <= mx; ++cnt) {
        int z = 0, x = cnt;
        for (int i = 0; i < n; ++i) {
            if (a[i] - cnt < 0) {
                x -= (cnt - a[i] + n - 1) / n;
            } else {
                ++z;
            }
        }
        ans += func(x, z);
        ans %= mod;
    }
    return ans;
}

int sum[max_n], more[max_n];

int solve() {
    for (int i = 0; i < n; ++i) {
        ++more[a[i]];
        for (int x = a[i] + 1; x < max_n; x += n) {
            ++sum[x];
        }
    }
    for (int x = 1; x < max_n; ++x) {
        sum[x] += sum[x - 1];
    }
    for (int x = max_n - 2; x >= 0; --x) {
        more[x] += more[x + 1];
    }
    const int mx = *max_element(a, a + n);
    int ans = 0;
    for (int cnt = 0; cnt <= mx; ++cnt) {
        int z = more[cnt], x = cnt - sum[cnt];
        if (x < 0) {
            break;
        }
        //cout << cnt << ": " << z << " " << x << ", ans += " << func(x, z) << endl;
        ans += func(x, z);
        ans %= mod;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", solve());
    return 0;
}