#include <bits/stdc++.h>

#define MAXN (710)

int n;
int a[MAXN];
int gcd[MAXN][MAXN], f[MAXN][MAXN][2];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            gcd[i][j] = std::__gcd(a[i], a[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        f[i][i][0] = (!i || gcd[i - 1][i] > 1);
        f[i][i][1] = (i == n - 1 || gcd[i][i + 1] > 1);
    }
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i + k < n; ++i) {
            for (int j = i; j <= i + k; ++j) {
                if (i == 0 || gcd[i - 1][j] > 1) {
                    bool tmp = ((i == j) || f[i][j - 1][1]);
                    f[i][i + k][0] |= (tmp && ((j == i + k) || f[j + 1][i + k][0]));
                }
                if (i + k + 1 == n || gcd[j][i + k + 1] > 1) {
                    bool tmp = ((i == j) || f[i][j - 1][1]);
                    f[i][i + k][1] |= (tmp && ((j == i + k) || f[j + 1][i + k][0]));
                }
            }
        }
    }
    printf((f[0][n - 1][0] | f[0][n - 1][1]) ? "Yes\n" : "No\n");
    return 0;
}