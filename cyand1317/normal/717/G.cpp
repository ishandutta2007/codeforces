#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int64 INF64 = (1LL << 61);
static const int INF32 = 0x7fffffff;
static const int MAXN = 504;
static const int MAXM = 104;
static const int MAXX = 104;

namespace mcf {

static const int MAXN = ::MAXN + 10;
static const int MAXM = ::MAXN * 5;

int n, m = 0, source, sink;
int dest[MAXM], cap[MAXM], cost[MAXM];
int head[MAXN], next[MAXM];

inline void initialize() { memset(head, -1, sizeof head); }
inline void add_edge(int u, int v, int _cap, int _cost) {
    dest[m] = v; cap[m] = _cap; cost[m] = _cost; next[m] = head[u]; head[u] = m++;
    dest[m] = u; cap[m] = 0; cost[m] = -_cost; next[m] = head[v]; head[v] = m++;
}

std::pair<int64, int64> deluge()
{
    int64 ans = 0, flow = 0;
    static int64 d[MAXN];
    static int pv[MAXN], pe[MAXN];
    while (true) {
        std::fill(d, d + n, INF64);
        d[source] = 0;
        bool updated;
        do {
            updated = false;
            for (int i = 0; i < n; ++i) if (d[i] != INF64) {
                for (int w = head[i]; w != -1; w = next[w])
                    if (cap[w] > 0 && d[dest[w]] > d[i] + cost[w]) {
                        d[dest[w]] = d[i] + cost[w];
                        pv[dest[w]] = i;
                        pe[dest[w]] = w;
                        updated = true;
                    }
            }
        } while (updated);
        if (d[sink] == INF64) break;

        int aug = INF32;
        for (int i = sink; i != source; i = pv[i])
            aug = std::min(aug, cap[pe[i]]);
        flow += aug;
        ans += d[sink] * aug;
        for (int i = sink; i != source; i = pv[i]) {
            cap[pe[i]] -= aug;
            cap[pe[i] ^ 1] += aug;
        }
    }
    return std::make_pair(flow, ans);
}

}

int n, m, x;
char s[MAXN];
char w[MAXM][MAXN];
int len[MAXN], q[MAXM];

int ct = 0;
int u[MAXM * MAXN], v[MAXM * MAXN], p[MAXM * MAXN];
bool used[MAXM * MAXN];

inline bool substr_equal(int sstart, int wlen, char *word) {
    for (int i = 0; i < wlen; ++i)
        if (s[sstart + i] != word[i]) return false;
    return true;
}

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar();
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%s%d", w[i], &q[i]);
    scanf("%d", &x);

    for (int i = 0; i < m; ++i) {
        len[i] = strlen(w[i]);
        for (int j = 0; j <= n - len[i]; ++j)
            if (substr_equal(j, len[i], w[i])) {
                u[ct] = j; v[ct] = j + len[i]; p[ct++] = q[i];
            }
    }

    mcf::n = (n + 1) + 2;
    mcf::source = mcf::n - 2;
    mcf::sink = mcf::n - 1;
    mcf::initialize();
    static const int OvO = 1000;
    for (int i = 0; i < ct; ++i)
        mcf::add_edge(v[i], u[i], 1, -p[i]);
    mcf::add_edge(mcf::source, n, x, 0);
    mcf::add_edge(0, mcf::sink, x, 0);
    for (int i = 0; i < n; ++i)
        mcf::add_edge(i + 1, i, INF32, 0);

    std::pair<int64, int64> flow = mcf::deluge();
    printf("%I64d\n", -flow.second);
    return 0;
}