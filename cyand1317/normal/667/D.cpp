#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
static const int MAXN = 3006;

int n, m;
bool a[MAXN][MAXN] = {{ false }};
std::vector<int> g[MAXN];
int dis[MAXN][MAXN];
std::pair<int, int> far[2][MAXN][MAXN];

void find_farthest_3(int u)
{
    static int q[MAXN], qhead, qtail;
    q[0] = u; qhead = 1; qtail = 0; dis[u][u] = 0;
    while (qhead > qtail) {
        int v = q[qtail++];
        for (std::vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i) if (dis[u][*i] == -1) {
            q[qhead++] = *i;
            dis[u][*i] = dis[u][v] + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        far[0][u][i] = std::make_pair(dis[u][i], i);
        far[1][i][u] = std::make_pair(dis[u][i], u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        a[u - 1][v - 1] = true;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j]) g[i].push_back(j);
    memset(dis, -1, sizeof dis);
    for (int i = 0; i < n; ++i) find_farthest_3(i);
    for (int i = 0; i < n; ++i) {
        std::sort(far[0][i], far[0][i] + n, std::greater< std::pair<int, int> >());
        std::sort(far[1][i], far[1][i] + n, std::greater< std::pair<int, int> >());
    }
    int ans = -1;
    int ans_vert[4] = { -1, -1, -1, -1 };
    int a, b, c, d;
    for (b = 0; b < n; ++b)
        for (c = 0; c < n; ++c) if (b != c && dis[b][c] >= 0) {
            for (int i = 0; i < 3; ++i) if ((a = far[1][b][i].second) >= 0 && a != c && a != b)
                for (int j = 0; j < 3; ++j) if ((d = far[0][c][j].second) >= 0 && d != b && d != c && d != a) {
                    int cur = dis[a][b] + dis[b][c] + dis[c][d];
                    if (ans < cur) {
                        ans = cur;
                        ans_vert[0] = a;
                        ans_vert[1] = b;
                        ans_vert[2] = c;
                        ans_vert[3] = d;
                    }
                }
        }
    printf("%d %d %d %d\n", ans_vert[0] + 1, ans_vert[1] + 1, ans_vert[2] + 1, ans_vert[3] + 1);
    return 0;
}