#include <bits/stdc++.h>

using namespace std;

const int max_n = 4111, max_k = 105, inf = 1000111222;

int n, m, q, cnt[max_n], w[15], cost[max_n], ans[max_n][max_k];
char a[15];

int get_mask() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += (a[i] - '0') * (1 << i);
    }
    return res;
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", a);
        ++cnt[get_mask()];
    }
    int all = (1 << n) - 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            cost[mask] += get_bit(mask, i) * w[i];
        }
    }
    for (int m1 = 0; m1 < (1 << n); ++m1) {
        for (int m2 = 0; m2 < (1 << n); ++m2) {
            int res = cost[m1 ^ m2 ^ all];
            if (res < max_k) {
                ans[m2][res] += cnt[m1];
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 1; j < max_k; ++j) {
            ans[i][j] += ans[i][j - 1];
        }
    }
    while (q--) {
        int k;
        scanf("%s%d", a, &k);
        printf("%d\n", ans[get_mask()][k]);
    }
    return 0;
}