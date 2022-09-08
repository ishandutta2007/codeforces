/**
 *  created: 04/04/2021, 20:25:24
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5555, mod = 998244353;

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

const int max_f = max_n;

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
    //cout << "$$$" << n <<  " " << k << endl;
    if (n < k) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

int get_partitions(int n, int cnt) {
    return get_c(n + cnt - 1, cnt - 1);
}

int val1[max_n], val2[max_n];

void calc_val(int h, int m, int val[]) {
    for (int i = 0; i < m; ++i) {
        val[i] = mul(get_partitions(h, i + 1), get_partitions(h - 1, m - i));
    }
}

int solve(int n, int m) {
    int res = 0;
    for (int h = 1; h < n; ++h) {
        calc_val(h, m, val1);
        calc_val(n - h, m, val2);
        reverse(val2, val2 + m);
        int sum = 0;
        for (int i = m - 1; i >= 0; --i) {
            inc(res, mul(val1[i], sum));
            inc(sum, val2[i]);
        }
    }
    for (int i = 0; i + 1 < m; ++i) {
        int h2 = n - 1, sum = 0;
        for (int h1 = 1; h1 < n; ++h1) {
            int val1 = mul(get_partitions(h1, i + 1), get_partitions(n - h1 - 1, i + 2));
            while (h2 >= 1 && h1 + h2 > n) {
                int val2 = mul(get_partitions(h2, m - i - 1), get_partitions(n - h2 - 1, m - i));
                inc(sum, val2);
                --h2;
            }
            inc(res, mul(sum, val1));
        }
    }
    res = mul(res, 2);
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}