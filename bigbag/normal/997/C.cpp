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

const int max_n = 1000111, mod = 998244353;

int power(int a, long long b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int f[max_n], rf[max_n];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * i * f[i - 1]) % mod;
        rf[i] = power(f[i], mod - 2, mod);
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

int n, ans;
int r3 = power(3, mod - 2, mod);

int sum_triv(int i, int q) {
    int pl = 0;
    for (int j = 1; j <= n; ++j) {
        int x = mul(get_c(n, j), power(q, j, mod));
        if ((i + j) % 2 == 0) {
            x = mod - x;
        }
        pl += x;
        pl %= mod;
    }
    return pl;
}

int sum_ok(int i, int q) {
    int pl = (power((1 + mod - q) % mod, n, mod)) + mod - 1;
    pl %= mod;
    if (i % 2 == 0) {
        pl = (mod - pl) % mod;
    }
    return pl;
}

void add() {
    int res = 0;
    //int q = power(r3, n, mod);
    for (int i = 1; i <= n; ++i) {
        int coef = mul(get_c(n, i), power(3, 1LL * n * n - 1LL * n * i, mod));
        //int q = mul(q, 3);
        int q = power(r3, n - i, mod);
        //cout << i << " " << q << "    " << sum_triv(i, q) << " " << sum_ok(i, q) << endl;
        res += mul(coef, sum_ok(i, q));
        res %= mod;
    }
    res = mul(3, res);

    ans += res;
    ans %= mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    cin >> n;
    int PW = 1;
    for (int i = 1; i <= n; ++i) {
        PW = mul(PW, 3);
        int x = mul(get_c(n, i), PW);
        x = mul(x, power(3, 1LL * n * (n - i), mod));
        if (i % 2 == 0) {
            x = mod - x;
        }
        ans += x;
        ans %= mod;
    }
    ans = mul(ans, 2);
    add();
    cout << ans << endl;
    return 0;
}