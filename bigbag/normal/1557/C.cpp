/**
 *  created: 09/08/2021, 17:43:34
**/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;

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

string str_fraq(int x, int n = 20) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
    }
    res << best.first << "/" << best.second;
    return res.str();
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

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int sum = 0;
        for (int i = 0; i <= n; i += 2) {
            inc(sum, get_c(n, i));
        }
        int ans = 0;
        if (n % 2 == 0) {
            dec(sum, 1);
            int x = power(2, n);
            ans = power(sum, k);
            for (int i = 0; i < k; ++i) {
                inc(ans, mul(power(sum, i), power(x, k - 1 - i)));
            }
        } else {
            inc(sum, 1);
            ans = power(sum, k);
        }
        cout << ans << "\n";
    }
    return 0;
}