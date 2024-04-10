#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 105;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }

int n, m;
bool type[MAXN]; int val[MAXN];
int ciel[MAXN];

namespace mcf {
static const int MAXN = ::MAXN * 2;
static const int MAXM = MAXN * MAXN;

int n, m = 0;
int source, sink;
int head[MAXN], dest[MAXM], cap[MAXM], cost[MAXM], next[MAXM];

inline void init_head() { for (int i = 0; i < n; ++i) head[i] = -1; }
inline void add_edge(int u, int v, int w, int c) {
    dest[m] = v; cap[m] = w; cost[m] = c; next[m] = head[u]; head[u] = m++;
    dest[m] = u; cap[m] = 0; cost[m] = -c; next[m] = head[v]; head[v] = m++;
}

inline int deluge(int flow_req)
{
    int flow = 0, ans = 0;
    static int d[MAXN];
    static int pv[MAXN], pe[MAXN];
    while (true) {
        for (int i = 0; i < n; ++i) d[i] = INF;
        d[source] = 0;
        bool updated;
        do {
            updated = false;
            for (int i = 0; i < n; ++i) if (d[i] != INF) {
                 for (int w = head[i]; w != -1; w = next[w])
                     if (cap[w] > 0 && d[dest[w]] > d[i] + cost[w]) {
                         d[dest[w]] = d[i] + cost[w];
                         pv[dest[w]] = i; pe[dest[w]] = w; updated = true;
                     }
            }
        } while (updated);
        if (d[sink] == INF) break;

        int aug = INF;
        for (int i = sink; i != source; i = pv[i]) aug = min(aug, cap[pe[i]]);
        flow += aug; ans += d[sink] * aug;
        for (int i = sink; i != source; i = pv[i]) {
            cap[pe[i]] -= aug;
            cap[pe[i] ^ 1] += aug;
        }
    }
    return (flow >= flow_req ? ans : INF);
}

}

int main()
{
    scanf("%d%d", &n, &m);
    char s[6];
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", s, &val[i]);
        type[i] = (s[0] == 'A' ? 1 : 0);
    }
    for (int i = 0; i < m; ++i) scanf("%d", &ciel[i]);

    int ans = 0, cur;

    // Defeat all Jiro's cards and attack on Jiro
    mcf::n = m + n + 3;
    mcf::source = mcf::n - 2;
    mcf::sink = mcf::n - 1;
    mcf::init_head();
    int extra = m + n;
    for (int i = 0; i < n; ++i) mcf::add_edge(mcf::source, i, 1, 0);
    for (int i = 0; i < m; ++i) mcf::add_edge(i + n, mcf::sink, 1, 0);
    for (int i = 0; i < n; ++i)
        if (type[i] == 1) for (int j = 0; j < m; ++j) { // Attack
            if (val[i] <= ciel[j]) mcf::add_edge(i, n + j, 1, val[i] - ciel[j]);
        } else for (int j = 0; j < m; ++j) {            // Defense
            if (val[i] < ciel[j]) mcf::add_edge(i, n + j, 1, 0);
        }
    if (m > n) {
        mcf::add_edge(mcf::source, extra, m - n, 0);
        for (int i = 0; i < m; ++i) mcf::add_edge(extra, n + i, 1, -ciel[i]);
    }
    if ((cur = -mcf::deluge(m)) > ans) ans = cur;

    // Defeat some of Jiro's cards
    mcf::n = m + n + 2;
    mcf::source = mcf::n - 2;
    mcf::sink = mcf::n - 1;
    mcf::init_head();
    for (int i = 0; i < n; ++i) mcf::add_edge(mcf::source, i, 1, 0);
    for (int i = 0; i < m; ++i) mcf::add_edge(i + n, mcf::sink, 1, 0);
    for (int i = 0; i < n; ++i)
        if (type[i] == 1) for (int j = 0; j < m; ++j) { // Attack
            if (val[i] <= ciel[j]) mcf::add_edge(i, n + j, 1, val[i] - ciel[j]);
            else mcf::add_edge(i, n + j, 1, 0);
        } else for (int j = 0; j < m; ++j) {            // Defense
            mcf::add_edge(i, n + j, 1, 0);
        }
    if ((cur = -mcf::deluge(0)) > ans) ans = cur;

    printf("%d\n", ans);

    return 0;
}