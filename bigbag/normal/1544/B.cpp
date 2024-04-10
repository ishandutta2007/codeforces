/**
 *  created: 17/07/2021, 17:40:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 22, inf = 1000111222;

int t, n, m, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i += 2) {
            a[0][i] = 1;
            a[n - 1][i] = 1;
        }
        for (int i = 2; i + 2 < n; i += 2) {
            a[i][0] = 1;
            a[i][m - 1] = 1;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d", a[i][j]);
            }
            puts("");
        }
    }
    return 0;
}