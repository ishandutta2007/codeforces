/**
 *  created: 22/01/2022, 17:25:14
**/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int r2 = (mod + 1) / 2;

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

inline void dec(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

inline int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

string str_fraction(int x, int n = 20) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
        best = min(best, {mod - mul(x, j), -j});
    }
    if (best.second < 0) {
        best.first *= -1;
        best.second *= -1;
    }
    res << best.first << "/" << best.second;
    return res.str();
}

const int max_f = 1000111;

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

int t, n, m, k;
int rpw[max_f];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    get_all_f();
    rpw[0] = 1;
    for (int i = 1; i < max_f; ++i) {
        rpw[i] = mul(rpw[i - 1], r2);
    }
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int ans = 0;
        for (int i = 0; i <= m; ++i) {
            inc(ans, mul(2, mul(i, get_c(n, m - i))));
        }
        ans = mul(ans, k);
        ans = mul(ans, rpw[n]);
        cout << ans << "\n";
    }
    return 0;
}