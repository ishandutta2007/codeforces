#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, used[max_n][max_n];
char s[max_n][max_n];

void wa() {
    puts("-1");
    exit(0);
}

bool is_in(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int x, int y) {
    //cout << x << " " << y << endl;
    used[x][y] = 1;
    for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (is_in(nx, ny) && !used[nx][ny] && s[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            cnt += s[i][j] == '#';
        }
    }
    if (!cnt) {
        puts("0");
        return 0;
    }
    int rows = 0, cols = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        int l = inf, r = -inf;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                l = min(l, j);
                r = max(r, j);
                ++cnt;
            }
        }
        if (!cnt) {
            ++rows;
            continue;
        }
        if (cnt != r - l + 1) {
            wa();
        }
    }
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        int l = inf, r = -inf;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == '#') {
                l = min(l, j);
                r = max(r, j);
                ++cnt;
            }
        }
        if (!cnt) {
            ++cols;
            continue;
        }
        if (cnt != r - l + 1) {
            wa();
        }
    }
    //cout << r << " " << c << endl;
    if (rows || cols) {
        if (rows == 0 || cols == 0) {
            wa();
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && s[i][j] == '#') {
                ++ans;
                dfs(i, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}