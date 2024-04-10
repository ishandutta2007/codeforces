#include <bits/stdc++.h>

#define MAXN (2010)

int n, m;
int x, y;
int ss, tt;
char s[MAXN][MAXN];
int dir[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int dis[MAXN][MAXN];
bool vis[MAXN][MAXN];

bool in(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

std::queue<std::pair<int, int>> q;

void bfs(int s, int t, int d) {
    std::queue<std::pair<int, int>> q;
    q.push({s, t});
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u.first, y = u.second;
        for (int k = 1; k < 4; ++k) {
            int tx = x + dir[k][0];
            int ty = y + dir[k][1];
            if (!in(tx, ty) || vis[tx][ty] || ::s[tx][ty] == '*') continue;
            q.push({tx, ty});
            ::q.push({tx, ty});
            vis[tx][ty] = true;
            dis[tx][ty] = d;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &ss, &tt);
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }
    q.push({ss, tt});
    vis[ss][tt] = true;
    memset(dis, -1, sizeof(dis));
    dis[ss][tt] = 0;
    bfs(ss, tt, dis[ss][tt]);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u.first, y = u.second;
        int pre = dis[x][y];
        x += dir[0][0];
        y += dir[0][1];
        if (!in(x, y) || vis[x][y] || s[x][y] == '*') continue;
        vis[x][y] = true;
        q.push({x, y});
        dis[x][y] = pre + 1;
        bfs(x, y, dis[x][y]);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dis[i][j] == -1) continue;
            if (dis[i][j] <= x && dis[i][j] + j - tt <= y) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}