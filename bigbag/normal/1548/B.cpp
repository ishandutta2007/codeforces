/**
 *  created: 01/08/2021, 17:49:29
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, max_lev = 18, inf = 1000111222;

struct sparse_table {
    long long gcd[max_lev][max_n];

    void init(int n, long long a[]) {
        for (int i = 0; i < n; ++i) {
            gcd[0][i] = a[i];
        }
        for (int i = 1; i < max_lev; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                gcd[i][j] = __gcd(gcd[i - 1][j], gcd[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    long long get_gcd(int l, int r) const {
        const int lev = 31 - __builtin_clz(r - l + 1);
        return __gcd(gcd[lev][l], gcd[lev][r - (1 << lev) + 1]);
    }
};

int t, n;
long long a[max_n];
sparse_table st;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i + 1 < n; ++i) {
            a[i] = abs(a[i + 1] - a[i]);
        }
        st.init(n - 1, a);
        int ans = 0, r = -1;
        for (int i = 0; i + 1 < n; ++i) {
            r = max(r, i - 1);
            while (r + 2 < n && st.get_gcd(i, r + 1) > 1) {
                ++r;
            }
            ans = max(ans, r - i + 1);
        }
        printf("%d\n", 1 + ans);
    }
    return 0;
}