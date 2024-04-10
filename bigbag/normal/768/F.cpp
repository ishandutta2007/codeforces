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

const int max_n = 201111, mod = 1000000007;

int power(int a, int b, int mod) {
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

int dp1[max_n], dp2[max_n], dp3[max_n];
int a, b, c, x, y;

void get_dp(int dp[], int x, int mn) {
    if (x == 0) {
        dp[0] = 1;
    }
    for (int i = 1; i < max_n; ++i) {
        long long y = x - 1LL * i * mn;
        if (y < 0) {
            break;
        }
        dp[i] = get_c(y + i - 1, i - 1);
    }
}

void upd(int &x, long long y) {
    y %= mod;
    x += y;
    x %= mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    cin >> a >> b >> c;
    get_dp(dp1, a, 1);
    get_dp(dp2, b, 1);
    get_dp(dp3, b, c + 1);
    for (int i = 1; i < max_n; ++i) {
        upd(x, 1LL * dp1[i] * dp2[i - 1]);
        upd(x, 1LL * dp1[i] * dp2[i]);

        upd(x, 1LL * dp2[i] * dp1[i - 1]);
        upd(x, 1LL * dp2[i] * dp1[i]);
    }

    for (int i = 1; i < max_n; ++i) {
        upd(y, 1LL * dp1[i] * dp3[i - 1]);
        upd(y, 1LL * dp1[i] * dp3[i]);

        upd(y, 1LL * dp3[i] * dp1[i - 1]);
        upd(y, 1LL * dp3[i] * dp1[i]);
    }
    swap(x, y);
    cout << (1LL * x * power(y, mod - 2, mod)) % mod << endl;
    return 0;
}