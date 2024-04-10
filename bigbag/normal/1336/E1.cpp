#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;
const int max_m = 37;
const int max_b = 16;
const int max_mask = 1 << max_b;

int n, m, f[max_m], ans[max_m];
long long a[max_n];
vector<long long> v;
int q1 = 0, q2 = 1, dp[2][max_m][max_mask];

void add(long long x) {
    for (long long y : v) {
        if ((x ^ y) < x) {
            x ^= y;
        }
    }
    if (!x) {
        return;
    }
    for (long long &y : v) {
        if ((x ^ y) < y) {
            y ^= x;
        }
    }
    v.push_back(x);
}

bool get_bit(long long mask, int pos) {
    return (mask >> pos) & 1;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        n = 200000;
        m = 35;
        for (int i = 0; i < 0; ++i) {
            a[i] = 1LL << i;
        }
        mt19937 gen;
        for (int i = 0; i < n; ++i) {
            //a[i] = gen();
        }
    } else {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &a[i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        add(a[i]);
    }
    if (v.size() < 20) {
        for (int mask = 0; mask < (1 << v.size()); ++mask) {
            long long x = 0;
            for (int i = 0; i < v.size(); ++i) {
                if (get_bit(mask, i)) {
                    x ^= v[i];
                }
            }
            ++ans[__builtin_popcountll(x)];
        }
    } else {
        for (long long x : v) {
            int pos = -1;
            for (int i = m - 1; i >= 0; --i) {
                if (get_bit(x, i)) {
                    pos = i;
                    break;
                }
            }
            f[pos] = 1;
        }
        dp[q1][0][0] = 1;
        // v.size() >= 20
        // m - v.size() <= 15
        const int max_m = 1 << (m - v.size());
        for (long long x : v) {
            int x_mask = 0, cur = 0;
            for (int i = 0; i < m; ++i) {
                if (!f[i]) {
                    if (get_bit(x, i)) {
                        x_mask += 1 << cur;
                    }
                    ++cur;
                }
            }
            for (int c = 0; c <= v.size(); ++c) {
                fill(dp[q2][c], dp[q2][c] + max_m, 0);
            }
            for (int c = 0; c <= v.size(); ++c) {
                for (int mask = 0; mask < max_m; ++mask) {
                    dp[q2][c][mask] += dp[q1][c][mask];
                    dp[q2][c][mask] %= mod;
                    dp[q2][c + 1][mask ^ x_mask] += dp[q1][c][mask];
                    dp[q2][c + 1][mask ^ x_mask] %= mod;
                }
            }
            swap(q1, q2);
        }
        for (int c = 0; c <= v.size(); ++c) {
            for (int mask = 0; mask < max_m; ++mask) {
                ans[__builtin_popcount(mask) + c] += dp[q1][c][mask];
                ans[__builtin_popcount(mask) + c] %= mod;
            }
        }
    }
    int k = 1;
    for (int i = v.size(); i < n; ++i) {
        k = mul(2, k);
    }
    for (int i = 0; i <= m; ++i) {
        printf("%d ", mul(ans[i], k));
    }
    puts("");
    return 0;
}