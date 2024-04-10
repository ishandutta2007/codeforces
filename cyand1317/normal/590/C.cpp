#include <cstdio>
static const int INF = 0x1fffffff;
static const int MAXN = 1004;
static const int mov[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
template <typename T> inline void update_min(T &var, const T val) {
    if (var > val) var = val;
}

int n, m;
char a[MAXN][MAXN];
int d[3][MAXN][MAXN];
int d_state[3][3];

void bfs(int state_id)
{
    static int qx[MAXN * MAXN], qy[MAXN * MAXN], qhead, qtail;
    qhead = 0, qtail = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) if (a[i][j] == '1' + state_id) {
            qx[qhead] = i; qy[qhead++] = j;
            d[state_id][i][j] = 0;
        } else d[state_id][i][j] = INF;
    for (int i = 0; i < 3; ++i) d_state[state_id][i] = INF;

    while (qtail < qhead) {
        int cx = qx[qtail], cy = qy[qtail]; ++qtail;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + mov[dir][0], ny = cy + mov[dir][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && d[state_id][nx][ny] == INF) {
                d[state_id][nx][ny] = d[state_id][cx][cy] + 1;
                qx[qhead] = nx; qy[qhead++] = ny;
                if (a[nx][ny] >= '1' && a[nx][ny] <= '3')
                    update_min(d_state[state_id][a[nx][ny] - '1'], d[state_id][nx][ny]);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) a[i][j] = getchar();

    for (int i = 0; i < 3; ++i) bfs(i);

    int ans = INF;
    update_min(ans, d_state[0][1] + d_state[1][2] - 2);
    update_min(ans, d_state[0][2] + d_state[2][1] - 2);
    update_min(ans, d_state[1][0] + d_state[0][2] - 2);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            update_min(ans, d[0][i][j] + d[1][i][j] + d[2][i][j] - 2);

    // Prevent things as INF + 1 - 2
    printf("%d\n", ans >= INF / 2 ? -1 : ans);

    return 0;
}