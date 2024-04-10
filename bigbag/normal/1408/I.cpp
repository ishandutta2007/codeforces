#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int mul(int x, int y) {
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

const int max_f = (1 << 16) + 5;

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

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

const int max_mask = (1 << 16), inf = 1000111222;
const int max_pos = 12, small = 16;
const int max_cnt = 17;

int n, k, c, a[max_pos][small];
int to_xor, ans[max_mask], cnt[2][max_cnt][small], tmp_ways[2][2][max_cnt][small], tmp[small];
int ways[max_pos][2][max_cnt][small];
int dp1[1 << 6][max_cnt][small];
int dp2[1 << 6][max_cnt][small], tmp_dp[2][max_cnt][small];
vector<vector<pair<int, int>>> all;

void rec(int pos, int need, vector<pair<int, int>> v) {
    if (pos == 17) {
        all.push_back(v);
        return;
    }
    for (int c = 0; c * pos <= need; ++c) {
        if (c) {
            v.push_back({pos, c});
        }
        rec(pos + 1, need - c * pos, v);
        if (c) {
            v.pop_back();
        }
    }
}

unsigned long long tmp_conv[small];

void xor_convolution(int a[small], int b[small], int c[small]) {
    memset(tmp_conv, 0, 8 * small);
    for (int x = 0; x < small; ++x) {
        for (int y = 0; y < small; ++y) {
            tmp_conv[x ^ y] += 1LL * a[x] * b[y];
        }
    }
    for (int i = 0; i < small; ++i) {
        c[i] = tmp_conv[i] % mod;
    }
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

void calc_dp(int l, int r, int dp[1 << 6][max_cnt][small]) {
    for (int mask_rev = 0; mask_rev < (1 << (r - l)); ++mask_rev) {
        memset(tmp_dp, 0, sizeof(tmp_dp));
        int q1 = 0, q2 = 1;
        tmp_dp[q1][0][0] = 1;
        for (int i = l; i < r; ++i) {
            memset(tmp_dp[q2], 0, sizeof(tmp_dp[q2]));
            for (int c1 = 0; c1 <= k; ++c1) {
                for (int c2 = 0; c1 + c2 <= k; ++c2) {
                    const int coef = get_c(c1 + c2, c1);
                    xor_convolution(tmp_dp[q1][c1], ways[i][get_bit(mask_rev, i - l)][c2], tmp);
                    for (int mask = 0; mask < small; ++mask) {
                        inc(tmp_dp[q2][c1 + c2][mask], mul(coef, tmp[mask]));
                    }
                }
            }
            swap(q1, q2);
        }
        for (int c = 0; c <= k; ++c) {
            for (int mask = 0; mask < small; ++mask) {
                dp[mask_rev][c][mask] = tmp_dp[q1][c][mask];
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    scanf("%d%d%d", &n, &k, &c);
    rec(1, k, {});
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        to_xor ^= x;
        int cnt = 0;
        if ((x >> 4)) {
            cnt = __builtin_ctz(x >> 4);
        }
        ++a[cnt][x & (small - 1)];
    }
    for (int pos = 0; pos < max_pos; ++pos) {
        int q1 = 0, q2 = 1;
        memset(tmp_ways, 0, sizeof(tmp_ways));
        tmp_ways[q1][0][0][0] = 1;
        for (int mask = 0; mask < small; ++mask) {
            memset(cnt, 0, sizeof(cnt));
            for (const auto &v : all) {
                int elems = 0;
                for (const auto &p : v) {
                    elems += p.second;
                }
                if (elems > a[pos][mask]) {
                    continue;
                }
                int res = 1;
                int tot = 0, cur = a[pos][mask];
                int res_mask = 0, rev = 0;
                for (const auto &p : v) {
                    res = mul(res, get_c(cur, p.second));
                    cur -= p.second;
                    res = mul(res, power(rf[p.first], p.second));
                    tot += p.first * p.second;
                    if (p.second % 2) {
                        res_mask ^= mask;
                        res_mask ^= (mask + small - p.first) & (small - 1);
                        if (mask < p.first) {
                            rev ^= 1;
                        }
                    }
                    //cout << "(" << p.first << " " << p.second << ") ";
                }
                res = mul(res, f[tot]);
                //if (!v.empty()) cout << pos << " " << rev << " " << tot << " " << mask << "   res = " << res << endl;
                inc(cnt[rev][tot][res_mask], res);
            }
            memset(tmp_ways[q2], 0, sizeof(tmp_ways[q2]));
            for (int cur_rev = 0; cur_rev < 2; ++cur_rev) {
                for (int nxt_rev = 0; nxt_rev < 2; ++nxt_rev) {
                    for (int c1 = 0; c1 <= k; ++c1) {
                        for (int c2 = 0; c1 + c2 <= k; ++c2) {
                            const int coef = get_c(c1 + c2, c1);
                            xor_convolution(tmp_ways[q1][cur_rev][c1], cnt[nxt_rev][c2], tmp);
                            for (int mask = 0; mask < small; ++mask) {
                                inc(tmp_ways[q2][cur_rev ^ nxt_rev][c1 + c2][mask], mul(coef, tmp[mask]));
                            }
                        }
                    }
                }
            }
            swap(q1, q2);
        }
        for (int rev = 0; rev < 2; ++rev) {
            for (int c = 0; c <= k; ++c) {
                for (int mask = 0; mask < small; ++mask) {
                    ways[pos][rev][c][mask] = tmp_ways[q1][rev][c][mask];
                }
            }
        }
    }
    calc_dp(0, max_pos / 2, dp1);
    calc_dp(max_pos / 2, max_pos, dp2);
    for (int m1 = 0; m1 < (1 << 6); ++m1) {
        for (int m2 = 0; m2 < (1 << 6); ++m2) {
            const int full = m1 | (m2 << 6);
            int big_mask = 0;
            for (int i = 0; i < max_pos; ++i) {
                if (get_bit(full, i)) {
                    big_mask ^= (1 << (i + 1)) - 1;
                }
            }
            big_mask <<= 4;
            for (int c1 = 0; c1 <= k; ++c1) {
                const int c2 = k - c1;
                const int coef = get_c(c1 + c2, c1);
                xor_convolution(dp1[m1][c1], dp2[m2][c2], tmp);
                for (int mask = 0; mask < small; ++mask) {
                    inc(ans[to_xor ^ mask ^ big_mask], mul(coef, tmp[mask]));
                }
            }
        }
    }
    int tot = inv(power(n, k));
    for (int i = 0; i < (1 << c); ++i) {
        //printf("%d %d\n", i, ans[i]);
        printf("%d ", mul(ans[i], tot));
    }
    return 0;
}