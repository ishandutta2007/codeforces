#include <cstdio>
#include <queue>
static const int MAXN = 54;

enum state { TBD = 0, WINS, LOSES };
int n;
state g[MAXN][MAXN] = {{ TBD }};
bool vis[MAXN] = { false };

int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n * (n - 1) / 2 - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        g[u][v] = WINS;
        g[v][u] = LOSES;
    }
    u = v = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j && g[i][j] == TBD) {
            u = i; v = j; break;
        }
        if (u != -1) break;
    }

    std::queue<int> q;
    vis[u] = true; q.push(u);
    while (!q.empty()) {
        int w = q.front(); q.pop();
        for (int i = 0; i < n; ++i) if (!vis[i] && g[w][i] == WINS) {
            vis[i] = true; q.push(i);
        }
    }
    if (!vis[v]) { n = u; u = v; v = n; }
    printf("%d %d\n", u + 1, v + 1);

    return 0;
}