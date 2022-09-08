/**
 *  created: 11/12/2020, 16:38:51
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int t, n, m, mx[max_n][max_n];
char a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", a[i]);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '.') {
                    continue;
                }
                mx[i][j] = 0;
                if (i + 1 < n && j - 1 >= 0 && j + 1 < m && a[i + 1][j - 1] == '*' && a[i + 1][j] == '*' && a[i + 1][j + 1] == '*') {
                    mx[i][j] = min(mx[i + 1][j - 1], mx[i + 1][j + 1]);
                }
                ++mx[i][j];
                ans += mx[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}