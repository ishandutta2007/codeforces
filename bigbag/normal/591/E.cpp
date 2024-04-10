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

const int max_n = 1111, inf = 111111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, dist[3][max_n][max_n], a[3][3];
char s[max_n][max_n];

bool is_in(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void bfs(int num) {
    queue<pair<int, int> > q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[num][i][j] = inf;
            if (s[i][j] == num + '1') {
                q.push(make_pair(i, j));
                dist[num][i][j] = 0;
            }
        }
    }
    a[num][0] = a[num][1] = a[num][2] = inf;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if (is_in(nx, ny) && dist[num][nx][ny] == inf && s[nx][ny] != '#') {
                dist[num][nx][ny] = dist[num][v.first][v.second] + 1;
                q.push(make_pair(nx, ny));
                if ('1' <= s[nx][ny] && s[nx][ny] <= '3') {
                    a[num][s[nx][ny] - '1'] = min(a[num][s[nx][ny] - '1'], dist[num][nx][ny]);
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    bfs(0);
    bfs(1);
    bfs(2);
    int ans = min(a[0][1] + a[0][2] - 2, min(a[0][1] + a[1][2] - 2, a[0][2] + a[1][2] - 2));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = min(ans, dist[0][i][j] + dist[1][i][j] + dist[2][i][j] - 2);
        }
    }
    if (ans >= inf - 10) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}