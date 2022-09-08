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
const int max_c = max_n * max_n;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, k, ans, cnt, res, tm, last[max_c], in[max_c], sz[max_c], used[max_n][max_n];
char s[max_n][max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

void dfs(int x, int y) {
    //cout << "(" << x << " " << y << ") ";
    used[x][y] = cnt;
    ++sz[cnt];
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (is_in(a, b) && used[a][b] == 0 && s[a][b] == '.') {
            dfs(a, b);
        }
    }
}

void add(int x, int y) {
    if (last[used[x][y]] == tm || used[x][y] == 0) {
        return;
    }
    //cout << x << " " << y << "  += " << sz[used[x][y]] - in[used[x][y]] << endl;
    last[used[x][y]] = tm;
    res += sz[used[x][y]] - in[used[x][y]];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[i][j] == 0 && s[i][j] == '.') {
                ++cnt;
                //cout << cnt << " : ";
                dfs(i, j);
                //cout << endl;
            }
        }
    }
    for (int i = 0; i + k <= n; ++i) {
        for (int j = 1; j <= cnt; ++j) {
            in[j] = 0;
        }
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (i <= x && x <= i + k - 1 && y <= k - 1) {
                    ++in[used[x][y]];
                }
            }
        }
        for (int j = 0; j + k <= n; ++j) {
            res = 0;
            ++tm;
            for (int q = 0; q < k; ++q) {
                if (i - 1 >= 0) {
                    add(i - 1, j + q);
                }
                if (i + k < n) {
                    add(i + k, j + q);
                }
                if (j - 1 >= 0) {
                    add(i + q, j - 1);
                }
                if (j + k < n) {
                    add(i + q, j + k);
                }
            }
            //cout << i << " " << j << " : res = " << res << "  \n";
            //return 0;
            /*for (int q = 1; q <= cnt; ++q) {
                cout << in[q] << " ";
            }
            cout << endl;*/
            ans = max(ans, res);
            for (int q = 0; q < k; ++q) {
                --in[used[i + q][j]];
                if (j + k < n) {
                    ++in[used[i + q][j + k]];
                }
            }
        }
    }
    printf("%d\n", ans + k * k);
    return 0;
}