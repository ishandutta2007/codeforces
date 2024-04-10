/**
 *  created: 25/06/2022, 18:11:11
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 1000000007;

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

const int r2 = (mod + 1) / 2;
int n, a[max_n];

int func(int x, int n) {
    int A = mul(n, x);
    inc(A, mul(x, x));
    dec(A, 1);
    int B = f[n + x];
    dec(B, f[n + x + 1]);
    int Q = (mod - mul(n + 1, mul(A, B))) % mod;
    int W = mul(x, mul(x + 1, mul(f[n + 1], n + x)));
    return mul(Q, inv(W));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    get_all_f();
    cin >> n;
    ++n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = a[0], sum = a[0];
    for (int i = 1; i < n; ++i) {
        if (!a[i]) {
            break;
        }
        while (a[i - 1] > a[i]) {
            --a[i - 1];
            dec(sum, mul(f[i - 1 + a[i - 1]], rf[a[i - 1]]));
        }
        inc(sum, func(i, a[i] - 1));
        inc(ans, mul(sum, rf[i]));
    }
    cout << ans << "\n";
    return 0;
}