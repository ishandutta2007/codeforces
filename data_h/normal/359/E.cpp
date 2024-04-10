#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 511;

int visit[N][N];

int map[N][N];
int n, sx, sy;
char buf[N * N * 6];
int len = 0;

int lightOn(int x1, int y1, int x2, int y2) {
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            if (map[i][j])
                return 1;
    return 0;
}

void dfs(int x, int y) {
    if (map[x][y] == 0) {
        map[x][y] = 1;
        buf[len++] = '1';
    }
    visit[x][y] = 1;
    if (x > 1 && !visit[x - 1][y] && lightOn(1, y, x - 1, y)) {
        buf[len++] = 'U';
        dfs(x - 1, y);
        buf[len++] = 'D';
    }
    if (x < n && !visit[x + 1][y] && lightOn(x + 1, y, n, y)) {
        buf[len++] = 'D';
        dfs(x + 1, y);
        buf[len++] = 'U';
    }
    if (y > 1 && !visit[x][y - 1] && lightOn(x, 1, x, y - 1)) {
        buf[len++] = 'L';
        dfs(x, y - 1);
        buf[len++] = 'R';
    }
    if (y < n && !visit[x][y + 1] && lightOn(x, y + 1, x, n)) {
        buf[len++] = 'R';
        dfs(x, y + 1);
        buf[len++] = 'L';
    }
    map[x][y] = 0;
    buf[len++] = '2';
}

int main() {
    scanf("%d %d %d", &n, &sx, &sy);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
    dfs(sx, sy);    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            if (map[i][j]) {
                puts("NO");
                return 0;
            }
    puts("YES");
    buf[len] = 0;
    puts(buf);
    return 0;
}