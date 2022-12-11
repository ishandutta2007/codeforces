#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
static const int MAXN = 3002;
static const int INF = 0x3fffffff;

namespace mcf {

static const int MAXN = 12018;
static const int MAXM = 2000004;

int n, m, source, sink;
int head[MAXN], dest[MAXM], cap[MAXM], cost[MAXM], next[MAXM];
inline void init(int _n) { n = _n, m = 0; memset(head, -1, sizeof head); }
inline int add_edge(int u, int v, int c, int w) {
    static int e = 0;
    dest[e] = v; cap[e] = c; cost[e] = +w; next[e] = head[u]; head[u] = e++;
    dest[e] = u; cap[e] = 0; cost[e] = -w; next[e] = head[v]; head[v] = e++;
    return e - 1;
}

std::pair<int, int> plunge(int cutoff)
{
    int flow = 0, tot_cost = 0;
    static int d[MAXN], pred_v[MAXN], pred_e[MAXN];
    std::deque<int> q;
    static bool in_q[MAXN] = { false };
    while (flow < cutoff) {
        for (int i = 0; i < n; ++i) d[i] = INF;
        d[source] = 0; q.push_back(source); in_q[source] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop_front(); in_q[u] = false;
            for (int w = head[u]; w != -1; w = next[w])
                if (cap[w] > 0 && d[dest[w]] > d[u] + cost[w]) {
                    d[dest[w]] = d[u] + cost[w];
                    pred_v[dest[w]] = u;
                    pred_e[dest[w]] = w;
                    if (!in_q[dest[w]]) {
                        if (!q.empty() && d[dest[w]] <= d[q.front()]) q.push_front(dest[w]);
                        else q.push_back(dest[w]);
                        in_q[dest[w]] = true;
                    }
                }
        }
        if (d[sink] == INF) break;

        int aug = INF;
        for (int u = sink; u != source; u = pred_v[u]) aug = std::min(aug, cap[pred_e[u]]);
        aug = std::min(aug, cutoff - flow);
        flow += aug; tot_cost += aug * d[sink];
        for (int u = sink; u != source; u = pred_v[u]) {
            cap[pred_e[u]] -= aug;
            cap[pred_e[u] ^ 1] += aug;
        }
    }
    return std::make_pair(flow, tot_cost);
}

}

int n, a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    mcf::init(n * 4 + 2);
    mcf::source = n * 4;
    mcf::sink = n * 4 + 1;
    for (int i = 0; i < n; ++i) {
        mcf::add_edge(mcf::source, i * 4, INF, 0);
        mcf::add_edge(i * 4, i * 4 + 1, 1, -1);
        mcf::add_edge(i * 4 + 1, mcf::sink, INF, 0);
        mcf::add_edge(i * 4 + 2, i * 4, INF, 0);
        mcf::add_edge(i * 4 + 3, i * 4, INF, 0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) if (a[j] == a[i]) {
            mcf::add_edge(i * 4 + 2, j * 4 + 2, INF, 0); break;
        }
        for (int j = i + 1; j < n; ++j) if ((a[j] - a[i]) % 7 == 0) {
            mcf::add_edge(i * 4 + 1, j * 4 + 3, INF, 0);
            mcf::add_edge(i * 4 + 3, j * 4 + 3, INF, 0); break;
        }
        for (int j = i + 1; j < n; ++j) if (a[j] == a[i] - 1) {
            mcf::add_edge(i * 4 + 1, j * 4 + 2, INF, 0); break;
        }
        for (int j = i + 1; j < n; ++j) if (a[j] == a[i] + 1) {
            mcf::add_edge(i * 4 + 1, j * 4 + 2, INF, 0); break;
        }
    }

    std::pair<int, int> res = mcf::plunge(4);
    printf("%d\n", -res.second);

    return 0;
}