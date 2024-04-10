#include <bits/stdc++.h>

using namespace std;

const int max_n = 333, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int t, n, m, a[max_n][max_n], ans[max_n][max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[i][j]);
                ans[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    ans[i][j] += is_in(i + dx[k], j + dy[k]);
                }
                ok &= a[i][j] <= ans[i][j];
            }
        }
        if (ok) {
            puts("YES");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    printf("%d ", ans[i][j]);
                }
                puts("");
            }
        } else {
            puts("NO");
        }
    }
    return 0;
}