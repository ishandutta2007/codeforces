/**
 *  created: 30/12/2020, 17:11:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 505555, mod = 1000000007;
const int max_b = 60;

int t, n, cnt[max_b];

bool get_bit(long long x, int pos) {
    return (x >> pos) & 1;
}

inline void inc(int &x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

const bool debug = 0;

mt19937_64 gen;
long long x[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        t = 1;
    } else {
        scanf("%d", &t);
    }
    while (t--) {
        if (debug) {
            n = 500000;
        } else {
            scanf("%d", &n);
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            if (debug) {
                x[i] = (1LL << max_b) - 1;
            } else {
                scanf("%I64d", &x[i]);
            }
            for (int a = 0; a < max_b; ++a) {
                if (get_bit(x[i], a)) {
                    ++cnt[a];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int coef = 0;
            int add_i = 0;
            for (int b = 0; b < max_b; ++b) {
                int add = (1LL << b) % mod;
                if (get_bit(x[i], b)) {
                    add = mul(add, n);
                    inc(coef, mul(cnt[b], (1LL << b) % mod));
                } else {
                    add = mul(add, cnt[b]);
                }
                inc(add_i, add);
            }
            inc(ans, mul(add_i, coef));
        }
        printf("%d\n", ans);
    }
    return 0;
}