#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int cost[] = {0, 0, 1, 0};

int ans, n, m, sx, sy, mxa, mxb, dist[max_n][max_n];
char a[max_n][max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m && a[x][y] == '.';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &mxa, &mxb);
    --sx;
    --sy;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            dist[i][j] = inf;
        }
    }
    queue<pair<int, int>> q[2];
    dist[sx][sy] = 0;
    q[0].push({sx, sy});
    while (!q[0].empty() || !q[1].empty()) {
        if (q[0].empty()) {
            while (!q[1].empty()) {
                q[0].push(q[1].front());
                q[1].pop();
            }
        }
        int x = q[0].front().first;
        int y = q[0].front().second;
        q[0].pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nd = dist[x][y] + cost[i];
            if (is_in(nx, ny) && nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                q[cost[i]].push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int l = dist[i][j];
            int r = l + j - sy;
            if (l <= mxa && r <= mxb) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}