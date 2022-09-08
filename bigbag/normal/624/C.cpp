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

const int max_n = 555, inf = 1111111111;

int n, m, cnt, a[max_n][max_n], col[max_n];

bool dfs(int v, int c) {
    col[v] = c;
    int ncol = 3;
    if (c == 3) {
        ncol = 1;
    }
    ++cnt;
    for (int i = 1; i <= n; ++i) {
        if (a[v][i]) {
            if (col[i] == 0) {
                if (!dfs(i, ncol)) {
                    return false;
                }
            } else if (col[i] == c) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                a[i][j] = 1;
            }
        }
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (col[i] == 0) {
            cnt = 0;
            if (!dfs(i, 1)) {
                printf("No\n");
                return 0;
            }
            if (cnt == 1) {
                col[i] = 2;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (a[i][j] == 0) {
                if (min(col[i], col[j]) == 1 && max(col[i], col[j]) == 3) {
                    printf("No\n");
                    return 0;
                }
            } else {
                if (min(col[i], col[j]) == 1 && max(col[i], col[j]) == 3) {
                    continue;
                }
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for (int i = 1; i <= n; ++i) {
        printf("%c", 'a' + col[i] - 1);
    }
    printf("\n");
    return 0;
}