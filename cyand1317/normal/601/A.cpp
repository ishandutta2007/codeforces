#include <cstdio>
#include <queue>
static const int MAXN = 404;
static const int INF = 0x7fffffff;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n, m;
bool rwy[MAXN][MAXN] = {{ false }};

int bfs(bool f)
{
    static int dist[MAXN];
    dist[0] = 0;
    for (int i = 1; i < n; ++i) dist[i] = INF;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < n; ++v) if (dist[v] == INF && rwy[u][v] == f) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
        if (u == n - 1) break;
    }
    return dist[n - 1] == INF ? -1 : dist[n - 1];
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v); --u, --v;
        rwy[u][v] = rwy[v][u] = true;
    }

    int d1 = bfs(true), d2 = bfs(false);
    int ans = (d1 == -1 || d2 == -1) ? -1 : max(d1, d2);
    printf("%d\n", ans);
    return 0;
}