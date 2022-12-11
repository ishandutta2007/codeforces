#include <cstdio>
#include <cstring>
#include <deque>
#include <utility>
#include <vector>
using std::min;
static const int INF = 0x1fffffff;
static const int MAXN = 103;
static const int ALPHA = 26;

namespace mcf {

static const int MAXN = 2 + ALPHA * (::MAXN / 2 + 1) + ::MAXN;
static const int MAXM = 4e6 + 4;

int n, e, source, sink;
int head[MAXN], dest[MAXM], cap[MAXM], cost[MAXM], next[MAXM];
inline void init(int _n) { n = _n, e = 0; memset(head, -1, sizeof head); }
inline int add_edge(int u, int v, int c, int w) {
    dest[e] = v; cap[e] = c; cost[e] = +w; next[e] = head[u]; head[u] = e++;
    dest[e] = u; cap[e] = 0; cost[e] = -w; next[e] = head[v]; head[v] = e++;
    return e - 1;
}

std::pair<int, int> deluge()
{
    int flow = 0, tot_cost = 0;
    static int d[MAXN], pred_v[MAXN], pred_e[MAXN];
    std::deque<int> q;
    static bool in_q[MAXN] = { false };
    while (true) {
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
        for (int u = sink; u != source; u = pred_v[u]) aug = min(aug, cap[pred_e[u]]);
        flow += aug; tot_cost += aug * d[sink];
        for (int u = sink; u != source; u = pred_v[u]) {
            cap[pred_e[u]] -= aug;
            cap[pred_e[u] ^ 1] += aug;
        }
    }
    return std::make_pair(flow, tot_cost);
}

}

int n;
char s[MAXN];
int b[MAXN];
int ct[ALPHA] = { 0 };

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) {
        s[i] -= 'a';
        ++ct[s[i]];
    }

    // source - 0
    // sink - 1
    // letter total - 2 + <letter>
    // letter grouped - 2 + ALPHA * (<group> + 1) + <letter>
    // elements - 2 + ALPHA * (n/2 + 1) + <index>
    mcf::init(2 + ALPHA * (n / 2 + 1) + n);
    mcf::source = 0;
    mcf::sink = 1;
    for (int i = 0; i < ALPHA; ++i) {
        mcf::add_edge(mcf::source, 2 + i, ct[i], 0);
        for (int j = 0; j < n / 2; ++j) {
            mcf::add_edge(2 + i, 2 + ALPHA * (j + 1) + i, 1, 0);
            mcf::add_edge(2 + ALPHA * (j + 1) + i, 2 + ALPHA * (n / 2 + 1) + j, 1, s[j] == i ? -b[j] : 0);
            mcf::add_edge(2 + ALPHA * (j + 1) + i, 2 + ALPHA * (n / 2 + 1) + (n - 1 - j), 1, s[n - 1 - j] == i ? -b[n - 1 - j] : 0);
        }
    }
    for (int i = 0; i < n; ++i) {
        mcf::add_edge(2 + ALPHA * (n / 2 + 1) + i, mcf::sink, 1, 0);
    }

    std::pair<int, int> flow = mcf::deluge();
    printf("%d\n", -flow.second);

    return 0;
}