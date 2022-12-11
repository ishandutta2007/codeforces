#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
static const int MAXN = 64;
typedef std::pair<int, int> point;
static const int mov[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

int n, m, k;
char g[MAXN][MAXN];
int tag[MAXN][MAXN];
std::vector<point> lake[MAXN * MAXN];
int lakect = 0;
point lake_info[MAXN * MAXN];

inline std::vector<point> floodfill(int sx, int sy)
{
    static int qx[MAXN * MAXN], qy[MAXN * MAXN], qhead, qtail;
    static bool vis[MAXN][MAXN];
    qhead = 1, qtail = 0, qx[0] = sx, qy[0] = sy;
    memset(vis, false, sizeof vis);
    vis[sx][sy] = true;
    std::vector<point> ret;
    while (qhead > qtail) {
        int cx = qx[qtail], cy = qy[qtail++];
        ret.push_back(point(cx, cy));
        for (int d = 0; d < 4; ++d) {
            int nx = cx + mov[d][0], ny = cy + mov[d][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && g[nx][ny] == '.') {
                qx[qhead] = nx; qy[qhead++] = ny;
                vis[nx][ny] = true;
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) g[i][j] = getchar();

    std::vector<point> v;
#define FOREACH_P_IN(__v) \
        for (std::vector<point>::iterator p = (__v).begin(); p != (__v).end(); ++p)
    for (int i = 0; i < n; ++i) {
        if (g[i][0] == '.') {
            v = floodfill(i, 0);
            FOREACH_P_IN(v) g[p->first][p->second] = 'w';
        }
        if (g[i][m - 1] == '.') {
            v = floodfill(i, m - 1);
            FOREACH_P_IN(v) g[p->first][p->second] = 'w';
        }
    }
    for (int i = 0; i < m; ++i) {
        if (g[0][i] == '.') {
            v = floodfill(0, i);
            FOREACH_P_IN(v) g[p->first][p->second] = 'w';
        }
        if (g[n - 1][i] == '.') {
            v = floodfill(n - 1, i);
            FOREACH_P_IN(v) g[p->first][p->second] = 'w';
        }
    }
    memset(tag, -1, sizeof tag);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) if (tag[i][j] == -1 && g[i][j] == '.') {
            lake[lakect] = floodfill(i, j);
            FOREACH_P_IN(lake[lakect]) tag[p->first][p->second] = lakect;
            lake_info[lakect] = std::make_pair((int)lake[lakect].size(), lakect);
            ++lakect;
        }

    std::sort(lake_info, lake_info + lakect);
    int chg_ct = 0;
    for (int i = 0; i < lakect - k; ++i) {
        FOREACH_P_IN(lake[lake_info[i].second]) g[p->first][p->second] = '*';
        chg_ct += lake_info[i].first;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) if (g[i][j] == 'w') g[i][j] = '.';
    printf("%d\n", chg_ct);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) putchar(g[i][j]);

    return 0;
}