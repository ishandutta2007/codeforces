#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXN = 1024;
static const int MAXM = 1024 * 2;

int n, m, x, y;
int head[MAXN], dest[MAXM], len[MAXM], next[MAXM];
int64 d[MAXN][MAXN];
int t[MAXN], c[MAXN];
int64 f[MAXN];

inline void add_edge(int u, int v, int ww) {
    static int w = 0;
    dest[w] = v; len[w] = ww; next[w] = head[u]; head[u] = w++;
}

typedef std::pair<int64, int> node_info;
typedef std::priority_queue<node_info,
    std::vector<node_info>, std::greater<node_info>
> node_container;

inline void dijkstra(int source) {
    static int64 d[MAXN];
    for (int i = 0; i < n; ++i) d[i] = INF64;
    node_container q;
    d[source] = 0; q.push(node_info(0, source));
    node_info r;
    while (!q.empty()) {
        do { r = q.top(); q.pop(); } while (!q.empty() && d[r.second] != r.first);
        if (d[r.second] != r.first) break;
        for (int w = head[r.second]; w != -1; w = next[w]) if (d[dest[w]] > r.first + len[w]) {
            d[dest[w]] = r.first + len[w];
            q.push(node_info(d[dest[w]], dest[w]));
        }
    }
    for (int i = 0; i < n; ++i) ::d[source][i] = ::d[i][source] = d[i];
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d", &x, &y); --x, --y;
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w); --u, --v;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    for (int i = 0; i < n; ++i) scanf("%d%d", &t[i], &c[i]);
    for (int i = 0; i < n; ++i) dijkstra(i);

    for (int i = 0; i < n; ++i) f[i] = INF64;
    node_container q;
    f[x] = 0; q.push(node_info(0, x));
    node_info r;
    while (!q.empty()) {
        do { r = q.top(); q.pop(); } while (!q.empty() && f[r.second] != r.first);
        if (f[r.second] != r.first) break;
        for (int u = 0; u < n; ++u)
            if (d[r.second][u] <= t[r.second] && f[u] > r.first + c[r.second]) {
                f[u] = r.first + c[r.second];
                q.push(node_info(f[u], u));
            }
    }

    printf("%I64d\n", f[y] == INF64 ? -1 : f[y]);
    return 0;
}