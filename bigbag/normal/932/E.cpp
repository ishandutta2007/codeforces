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

int power(int a, int b, int mod) {
    if (b == -1) {
        b = mod - 2;
    }
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

const int max_n = 5005, mod = 1000000007;

int c[max_n][max_n];

void get_all_c() {
    c[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

int n, k, a[max_n], y[max_n], pw[max_n];
int pref[max_n], suf[max_n];

void precalc() {
    for (int i = 1; i < max_n; ++i) {
        pw[i] = power(i, k, mod);
    }
    for (int n = 1; n <= k + 1; ++n) {
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (1LL * c[n][i] * pw[i]) % mod;
        }
        y[n] = sum % mod;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_c();
    cin >> n >> k;
    precalc();
    if (n <= k + 1) {
        cout << y[n] << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= k + 1; ++i) {
        a[i] = (n - i) % mod;
    }
    pref[0] = 1;
    suf[k + 2] = 1;
    for (int i = 1; i <= k + 1; ++i) {
        pref[i] = (1LL * pref[i - 1] * a[i]) % mod;
    }
    for (int i = k + 1; i >= 1; --i) {
        suf[i] = (1LL * suf[i + 1] * a[i]) % mod;

    }
    for (int i = 1; i <= k + 1; ++i) {
        y[i] = (1LL * y[i] * power(2, k - i, mod)) % mod;
        int rev = 1;
        for (int j = 1; j <= k + 1; ++j) {
            if (i != j) {
                int del = (i - j + mod) % mod;
                rev = (1LL * rev * del) % mod;
            }
        }
        y[i] = (1LL * y[i] * power(rev, mod - 2, mod)) % mod;
        int x = (1LL * pref[i - 1] * suf[i + 1]) % mod;
        //cout << y[i] << " " << x << endl;
        ans += (1LL * x * y[i]) % mod;
        ans %= mod;
    }
    ans = (1LL * ans * power(2, n - k, mod)) % mod;
    cout << ans << endl;
    return 0;
}