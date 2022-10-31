#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a[1001][1001];
int dis[41][1001][1001];
bool used[41];
vector<pair<int, int> > color[41];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int c) {
    memset(used, 0, sizeof(used));
    queue<pair<int, int> > Q;
    used[c] = true;
    for(auto &grid : color[c]) {
        dis[c][grid.first][grid.second] = 0;
        Q.push(make_pair(grid.first, grid.second));
    }
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if(!used[a[x][y]]) {
            used[a[x][y]] = true;
            for(auto &grid : color[a[x][y]]) {
                if(dis[c][grid.first][grid.second] == -1) {
                    dis[c][grid.first][grid.second] = dis[c][x][y] + 1;
                    Q.push(grid);
                }
            }
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 1 || ny < 1) continue;
            if(nx > n || ny > m) continue;
            if(dis[c][nx][ny] != -1) continue;
            dis[c][nx][ny] = dis[c][x][y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    memset(dis, -1, sizeof(dis));
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            color[a[i][j]].push_back(make_pair(i, j));
        }
    }

    for(int i = 1; i <= k; i++) bfs(i);

    int q; scanf("%d", &q);
    while(q--) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int ans = abs(x1 - x2) + abs(y1 - y2);
        for(int c = 1; c <= k; c++) {
            ans = min(ans, dis[c][x1][y1] + dis[c][x2][y2] + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/**
**/