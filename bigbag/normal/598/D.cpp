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

const int max_n = 1111, inf = 1111111111;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, k, used[max_n][max_n], f[max_n][max_n], res[max_n * max_n], ans, cnt;
char s[max_n][max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void dfs(int x, int y, int cnt) {
    used[x][y] = cnt;
    for (int i = 0; i < 4; ++i) {
        int a = x + dx[i], b = y + dy[i];
        if (is_in(a, b)) {
            if (s[a][b] == '.') {
                if (used[a][b] == 0) {
                    dfs(a, b, cnt);
                }
            } else {
                ++ans;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j] == 0 && s[i][j] == '.') {
                ans = 0;
                ++cnt;
                dfs(i, j, cnt);
                res[cnt] = ans;
            }
        }
    }
    while (k--) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        printf("%d\n", res[used[x][y]]);
    }
    return 0;
}