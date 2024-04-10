#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int n, q, a[max_n], f[max_n][max_n], mx[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        f[i][i] = a[i];
        mx[i][i] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            f[i][i + len - 1] = f[i][i + len - 2] ^ f[i + 1][i + len - 1];
        }
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            mx[i][i + len - 1] = max({f[i][i + len - 1], mx[i][i + len - 2], mx[i + 1][i + len - 1]});
        }
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        printf("%d\n", mx[l][r]);
    }
    return 0;
}