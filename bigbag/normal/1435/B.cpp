#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int t, n, m, a[max_n][max_n], b[max_n][max_n], pos[max_n * max_n], p[max_n];

bool cmp(int i, int j) {
    return pos[a[i][0]] < pos[a[j][0]];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &b[i][j]);
                pos[b[i][j]] = j;
            }
        }
        sort(p, p + n, cmp);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                printf("%d ", a[p[i]][j]);
            }
            puts("");
        }
    }
    return 0;
}