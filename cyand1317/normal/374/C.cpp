#include <cstdio>
#include <vector>
static const int MAXN = 1003;
static const int MAXV = 1000003;
typedef std::vector<int> edgelist;
static const int mov[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

int n, m, v;
char t[MAXN][MAXN];
edgelist e[MAXV];

int in_deg[MAXV] = { 0 };
int vis[MAXV] = { 0 };
bool acyclic = true;
int furthest[MAXV] = { 0 };

void dfs(int u, int p = -1)
{
    vis[u] = 1;
    furthest[u] = 1;
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (*i != p) {
        if (vis[*i] == 0) dfs(*i); else if (vis[*i] == 1) acyclic = false;
        if (!acyclic) break;
        if (furthest[u] < furthest[*i] + 1)
            furthest[u] = furthest[*i] + 1;
    }
    vis[u] = 2;
}

int main()
{
    int mapped[128];
    mapped['D'] = 0; mapped['I'] = 1;
    mapped['M'] = 2; mapped['A'] = 3;

    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) t[i][j] = mapped[getchar()];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 4; ++k) {
                int ii = i + mov[k][0], jj = j + mov[k][1];
                if (ii >= 0 && ii < n && jj >= 0 && jj < m && t[ii][jj] == (t[i][j] + 1) % 4) {
                    e[i * m + j].push_back(ii * m + jj);
                    ++in_deg[ii * m + jj];
                }
            }
        }

    bool no_entry = true;
    for (int i = 0; i < n * m; ++i)
        if (!vis[i] && t[i / m][i % m] == mapped['D']) {
            no_entry = false; dfs(i);
        }
    if (no_entry) dfs(0);
    if (!acyclic) puts("Poor Inna!");
    else {
        int ans = 0;
        for (int i = 0; i < n * m; ++i) if (ans < furthest[i]) ans = furthest[i];
        ans /= 4;
        if (ans == 0) puts("Poor Dima!"); else printf("%d\n", ans);
    }

    return 0;
}