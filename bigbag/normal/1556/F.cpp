/**
 *  created: 29/08/2021, 18:41:55
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 15, inf = 1000111222;
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

string str_fraq(int x, int n = 20000) {
    stringstream res;
    pair<int, int> best(x, 1);
    for (int j = 1; j < n; ++j) {
        best = min(best, {mul(x, j), j});
    }
    res << best.first << "/" << best.second;
    return res.str();
}

const int max_mask = 1 << max_n;

int n, a[max_n], p_win[max_n][max_n];
int dp[max_mask];
int win_mask[max_n][max_mask];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p_win[i][j] = mul(a[i], inv(a[i] + a[j]));
        }
    }
    for (int i = 0; i < n; ++i) {
        win_mask[i][0] = 1;
        for (int mask = 1; mask < (1 << n); ++mask) {
            if (get_bit(mask, i)) {
                continue;
            }
            int id = __builtin_ctz(mask);
            win_mask[i][mask] = mul(win_mask[i][mask ^ (1 << id)], p_win[i][id]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        memset(dp, 0, sizeof(dp));
        dp[1 << i] = 1;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (!get_bit(mask, i)) {
                continue;
            }
            if (mask == (1 << i)) {
                continue;
            }
            dp[mask] = 1;
            for (int sub = (mask & (mask - 1)); sub; sub = mask & (sub - 1)) {
                if (!get_bit(sub, i)) {
                    continue;
                }
                int add = dp[sub];
                for (int j = 0; j < n; ++j) {
                    if (get_bit(mask, j) && !get_bit(sub, j)) {
                        add = mul(add, win_mask[j][sub]);
                    }
                }
                dec(dp[mask], add);
            }
        }
        inc(ans, dp[(1 << n) - 1]);
    }
    cout << ans << "\n";
    return 0;
}