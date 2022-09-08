/**
 *  created: 29/08/2021, 18:29:09
**/

#include <bits/stdc++.h>

using namespace std;

const int max_lev = 18;
const int max_n = 101111;
const long long inf = 1000111222000111222;

template<typename T, int z = 1> // z = -1 for maximum
struct sparse_table {
    T mn[max_lev][max_n];

    void init(int n, T a[]) {
        for (int i = 0; i < n; ++i) {
            mn[0][i] = z * a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get_min(int l, int r) const {
        if (l > r) {
            return z * inf;
        }
        const int lev = 31 - __builtin_clz(r - l + 1);
        return z * min(mn[lev][l], mn[lev][r - (1 << lev) + 1]);
    }
};

int n, q, a[max_n], b[max_n];
long long sum[max_n];
sparse_table<long long> mn;
sparse_table<long long, -1> mx;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        a[i] -= b[i];
    }
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
    mn.init(n, sum);
    mx.init(n, sum);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        long long pr = 0;
        if (l) {
            pr = sum[l - 1];
        }
        if (sum[r] != pr || mx.get_min(l, r) > pr) {
            puts("-1");
        } else {
            printf("%lld\n", -(mn.get_min(l, r) - pr));
        }
    }
    return 0;
}