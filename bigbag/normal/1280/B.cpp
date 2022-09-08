#include <bits/stdc++.h>

using namespace std;

const int max_n = 66, inf = 1000111222;

int t, n, m, a[max_n][max_n];
int r[max_n][max_n];
int d[max_n][max_n];
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            for (int j = 0; j < m; ++j) {
                a[i][j] = (s[i][j] == 'A');
                tot += a[i][j];
            }
        }
        if (tot == 0) {
            puts("MORTAL");
            continue;
        }
        if (tot == n * m) {
            puts("0");
            continue;
        }
        for (int i = 0; i < n; ++i) {
            r[i][m] = m;
            for (int j = m - 1; j >= 0; --j) {
                r[i][j] = j;
                if (a[i][j]) {
                    r[i][j] = r[i][j + 1];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            d[n][i] = n;
            for (int j = n - 1; j >= 0; --j) {
                d[j][i] = j;
                if (a[j][i]) {
                    d[j][i] = d[j + 1][i];
                }
            }
        }
        if (r[0][0] == m || r[n - 1][0] == m || d[0][0] == n || d[0][m - 1] == n) {
            puts("1");
            continue;
        }
        vector<int> cols{0, m - 1};
        vector<int> rows{0, n - 1};
        bool ok = false;
        for (int i : rows) {
            for (int j : cols) {
                ok |= a[i][j];
            }
        }
        for (int i = 0; i < n && !ok; ++i) {
            for (int j = 0; j < m && !ok; ++j) {
                for (int col : cols) {
                    if (d[0][col] >= i && d[d[i][j]][col] >= n) {
                        ok = true;
                        break;
                    }
                }
                for (int row : rows) {
                    if (r[row][0] >= j && r[row][r[i][j]] >= m) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        if(ok) {
            puts("2");
            continue;
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            cnt += a[0][i];
            cnt += a[n - 1][i];
        }
        for (int i = 0; i < n; ++i) {
            cnt += a[i][0];
            cnt += a[i][m - 1];
        }
        if (cnt) {
            puts("3");
        } else {
            puts("4");
        }
    }
    return 0;
}