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

const int max_n = 1011, inf = 1011111111;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, -1, 1, 0};
const char c[] = {'D', 'L', 'R', 'U'};

int n, m, k, stx, sty, dist[max_n][max_n];
char s[max_n][max_n];

void wa() {
    printf("IMPOSSIBLE\n");
    exit(0);
}

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    dist[x][y] = 0;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_in(nx, ny) && s[nx][ny] != '*' && dist[nx][ny] == inf) {
                q.push(make_pair(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
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
        for (int j = 0; j < m; ++j) {
            dist[i][j] = inf;
            if (s[i][j] == 'X') {
                stx = i;
                sty = j;
            }
        }
    }
    if (k % 2 == 1) {
        wa();
    }
    bfs(stx, sty);
    for (int j = 0; j < k; ++j) {
        int f = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = stx + dx[i], ny = sty + dy[i];
            if (is_in(nx, ny) && s[nx][ny] != '*' && dist[nx][ny] <= k - j - 1) {
                stx = nx;
                sty = ny;
                printf("%c", c[i]);
                f = 1;
                break;
            }
        }
        if (f == 0) {
            if (j == 0) {
                wa();
            }
            printf("FAIL\n");
            exit(228);
        }
    }
    printf("\n");
    return 0;
}