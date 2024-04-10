#include <cstdio>
#include <queue>
#include <utility>
static const int MAXN = 504;
static const int MAX_OPS = 1e6 + 4;
static const int mov[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

int n, m;
char s[MAXN][MAXN];

int op_ct = 0;
char op_t[MAX_OPS]; int op_x[MAX_OPS], op_y[MAX_OPS];
inline void add_event(char t, int x, int y) {
    op_t[op_ct] = t; op_x[op_ct] = x; op_y[op_ct++] = y;
}

bool vis[MAXN][MAXN] = {{ false }};
void dfs_fill(int rx, int ry, bool is_root)
{
    vis[rx][ry] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = rx + mov[dir][0], ny = ry + mov[dir][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] == '.' && !vis[nx][ny])
            dfs_fill(nx, ny, false);
    }
    if (!is_root) {
        add_event('D', rx, ry);
        add_event('R', rx, ry);
    }
}

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) s[i][j] = getchar();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) if (s[i][j] == '.') add_event('B', i, j);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) if (s[i][j] == '.' && !vis[i][j]) dfs_fill(i, j, true);

    printf("%d\n", op_ct);
    for (int i = 0; i < op_ct; ++i) printf("%c %d %d\n", op_t[i], op_x[i] + 1, op_y[i] + 1);
    return 0;
}