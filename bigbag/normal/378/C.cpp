#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 555, inf = 111111111;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, s, cnt, used[max_n][max_n];
char aa[max_n][max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y) {
    //cout << x << ' ' << y << ' ' << cnt << endl;
    used[x][y] = 1;
    if (cnt == s) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                //cout << used[i][j];
                if (aa[i][j] == '.' && used[i][j] == 0) {
                    printf("X");
                } else {
                    printf("%c", aa[i][j]);
                }
            }
            printf("\n");
        }
        exit(0);
    }
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (is_in(a, b) && used[a][b] == 0 && aa[a][b] == '.') {
            ++cnt;
            dfs(a, b);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d\n", &n, &m, &s);
    int cnt1 = 0, stx, sty;
    for (int i = 0; i < n; ++i) {
        gets(aa[i]);
        for (int j = 0; j < m; ++j) {
            if (aa[i][j] == '.') {
                ++cnt1;
                stx = i;
                sty = j;
            }
        }
    }
    cnt = 1;
    s = cnt1 - s;
    dfs(stx, sty);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << used[i][j];
            /*if (aa[i][j] == '.' && used[i][j] == 0) {
                printf("X");
            } else {
                printf("%c", aa[i][j]);
            }*/
        }
        printf("\n");
    }
    return 0;
}