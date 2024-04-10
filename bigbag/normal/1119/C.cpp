#include <bits/stdc++.h>

using namespace std;

const int max_n = 505, inf = 1000111222;

int n, m, a[max_n][max_n], b[max_n][max_n];
int x[max_n], y[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[i][j]);
            a[i][j] ^= b[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            x[i] ^= a[i][j];
            y[j] ^= a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (x[i]) {
            puts("No");
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (y[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}