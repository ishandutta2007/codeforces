/**
 *  created: 17/07/2021, 19:22:28
**/

#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2") // WINDOWS ONLY

#include <bits/stdc++.h>

using namespace std;

const int max_n = 21;
const int mod = 31607;

inline void inc(short int &x, int y) {
    x += y;
    if (x >= mod || x < 0) {
        x -= mod;
    }
}

inline void dec(short int &x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
}

inline int mul(int x, int y) {
    return x * y % mod;
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

const int r10000 = inv(10000);
const int max_mask = 1 << (max_n + 2);

int n, a[max_n][max_n];
short int dp[max_mask], need_sub[max_mask];

int get_update_mask(int i, int j) {
    const int full_mask = (1 << (n + 2)) - 1;
    int upd_mask = full_mask ^ (1 << j);
    if (i == j) {
        upd_mask ^= (1 << n);
    }
    if (i == n - 1 - j) {
        upd_mask ^= (1 << (n + 1));
    }
    return upd_mask;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 21;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = rand() % (mod - 1) + 1;
            }
        }

    } else {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                a[i][j] = mul(a[i][j], r10000);
            }
        }
    }
    const int full_mask = (1 << (n + 2)) - 1;
    dp[full_mask] = 1;
    for (int i = 0; i < n; ++i) {
        int p_all = 1;
        for (int j = 0; j < n; ++j) {
            p_all = mul(p_all, a[i][j]);
        }
        for (int mask = 0; mask < (1 << (n + 2)); ++mask) {
            need_sub[mask] = mul(dp[mask], p_all);
        }
        for (int j = 0; j < n; ++j) {
            if (i != j && i != n - 1 - j) {
                for (int m2 = 0; m2 < (1 << (n + 1 - j)); ++m2) {
                    const int start = (1 << j) | (m2 << (j + 1));
                    for (int mask = start; mask < start + (1 << j); ++mask) {
                        const int val = mul(dp[mask], 1 + mod - a[i][j]);
                        inc(dp[mask ^ (1 << j)], val);
                        dec(dp[mask], val);
                    }
                }
            } else {
                const int upd_mask = get_update_mask(i, j);
                for (int mask = 0; mask < (1 << (n + 2)); ++mask) {
                    if ((mask & upd_mask) != mask) {
                        const int val = mul(dp[mask], 1 + mod - a[i][j]);
                        inc(dp[mask & upd_mask], val);
                        dec(dp[mask], val);
                    }
                }
            }
        }
        for (int mask = 0; mask < (1 << (n + 2)); ++mask) {
            dec(dp[mask], need_sub[mask]);
        }
    }
    int ans = (1 + mod - dp[0]) % mod;
    cout << ans << "\n";
    return 0;
}