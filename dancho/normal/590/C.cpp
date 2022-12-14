#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
char t[1024][1024];

int d[3][1024][1024];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", t[i]);
    }

    memset(d, -1, sizeof(d));
    for (char c = '1'; c <= '3'; ++c) {
        deque<pair<int, int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (t[i][j] == c) {
                    d[c - '1'][i][j] = 0;
                    q.push_back(make_pair(i, j));
                }
            }
        }
        while (q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for (int k = 0; k < 4; ++k) {
                int nx, ny;
                nx = x + dx[k];
                ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if (t[nx][ny] == '.') {
                        if (d[c - '1'][nx][ny] == -1) {
                            d[c - '1'][nx][ny] = d[c - '1'][x][y] + 1;
                            q.push_back(make_pair(nx, ny));
                        }
                    } else if (t[nx][ny] >= '1' && t[nx][ny] <= '3') {
                        if (d[c - '1'][nx][ny] == -1 ||
                            d[c - '1'][nx][ny] > d[c - '1'][x][y]) {
                            d[c - '1'][nx][ny] = d[c - '1'][x][y];
                            q.push_front(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }
    int ans = (1 << 29);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int sm = 0;
            bool ok = true;
            for (int k = 0; k < 3; ++k) {
                if (d[k][i][j] == -1) {
                    ok = false;
                }
                sm += d[k][i][j];
            }
            if (t[i][j] == '.') {
                sm -= 2;
            }
            if (ok) {
                // printf("OK %d %d -> %d\n", i, j, sm);
                ans = min(ans, sm);
            }
        }
    }
    if (ans < (1 << 29)) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
    return 0;
}