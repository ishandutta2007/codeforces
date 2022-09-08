/**
 *  created: 23/04/2021, 17:39:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, m, a[max_n][max_n], used[max_n][max_n];
int ans[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                used[i][j] = 0;
            }
        }
        for (int it = 0; it < m; ++it) {
            int x = -1, y = -1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (!used[i][j] && (x == -1 || a[x][y] > a[i][j])) {
                        x = i;
                        y = j;
                    }
                }
            }
            //cout << "#" << x << " " << y << endl;
            for (int i = 0; i < n; ++i) {
                if (i == x) {
                    ans[i][it] = a[i][y];
                    used[i][y] = 1;
                    continue;
                }
                int y = -1;
                for (int j = 0; j < m; ++j) {
                    if (!used[i][j] && (y == -1 || a[i][y] < a[i][j])) {
                        y = j;
                    }
                }
                ans[i][it] = a[i][y];
                used[i][y] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}