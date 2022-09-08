#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1111111111;

int n, m, q, ans[max_n][max_n];
pair<int, int> a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = make_pair(i, j);
        }
    }
    while (q--) {
        int tp;
        scanf("%d", &tp);
        if (tp <= 2) {
            int x;
            scanf("%d", &x);
            --x;
            if (tp == 1) {
                pair<int, int> k = a[x][0];
                for (int i = 0; i + 1 < m; ++i) {
                    a[x][i] = a[x][i + 1];
                }
                a[x][m - 1] = k;
            } else {
                pair<int, int> k = a[0][x];
                for (int i = 0; i + 1 < n; ++i) {
                    a[i][x] = a[i + 1][x];
                }
                a[n - 1][x] = k;
            }
        } else {
            int x, y, q;
            scanf("%d%d%d", &x, &y, &q);
            --x;
            --y;
            ans[a[x][y].first][a[x][y].second] = q;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}