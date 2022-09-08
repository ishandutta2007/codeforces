#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, t, dist[max_n][max_n];
char s[max_n][max_n];

bool is_in(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[i][j] = -1;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (is_in(x, y) && s[i][j] == s[x][y]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                    break;
                }
            }
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (is_in(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    while (t--) {
        int x, y;
        long long p;
        scanf("%d%d%I64d", &x, &y, &p);
        --x;
        --y;
        if (dist[x][y] == -1 || p <= dist[x][y]) {
            printf("%c\n", s[x][y]);
        } else if (dist[x][y] % 2 == p % 2) {
            printf("%c\n", s[x][y]);
        } else {
            printf("%c\n", s[x][y] ^ '0' ^ '1');
        }
    }
    return 0;
}