#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
static const int MAXN = 20004;
static const int MAXM = 10004;
static const int LOGN = 16;
static const int INF = 0x3fffffff;

namespace nwf {

static const int MAXN = 5e5 + 4;
static const int MAXM = 2e6 + 4;

int n, m, source, sink;
int head[MAXN], dest[MAXM], cap[MAXM], next[MAXM];

inline void init(int _n) {
    n = _n; m = 0; for (int i = 0; i < n; ++i) head[i] = -1;
}
inline void add_edge(int u, int v, int w) {
    dest[m] = v; cap[m] = w; next[m] = head[u]; head[u] = m++;
    dest[m] = u; cap[m] = 0; next[m] = head[v]; head[v] = m++;
}

int q[MAXN], qhead, qtail;
int d[MAXN];
int cur[MAXN];

inline bool level_graph() {
    for (int i = 0; i < n; ++i) d[i] = -1;
    q[0] = source, qhead = 0, qtail = 1; d[source] = 0;
    while (qhead < qtail) {
        int u = q[qhead++];
        for (int w = head[u]; w != -1; w = next[w])
            if (cap[w] > 0 && d[dest[w]] == -1) {
                d[dest[w]] = d[u] + 1;
                q[qtail++] = dest[w];
            }
    }
    return (d[sink] >= 0);
}

inline int augment(int u, int cur_cap = INF) {
    if (u == sink) return cur_cap;
    int new_cap;
    for (int &w = cur[u]; w != -1; w = next[w])
        if (cap[w] > 0 && d[dest[w]] == d[u] + 1 &&
            (new_cap = augment(dest[w], std::min(cur_cap, cap[w]))) > 0)
        {
            cap[w] -= new_cap;
            cap[w ^ 1] += new_cap;
            return new_cap;
        }
    return 0;
}

inline int deluge() {
    int ans = 0, aug;
    while (level_graph()) {
        for (int i = 0; i < n; ++i) cur[i] = head[i];
        while ((aug = augment(source)) > 0) ans += aug;
    }
    return ans;

}

bool r_vis[MAXN] = { false };

inline void bfs_residual() {
    q[0] = source, qhead = 0, qtail = 1; r_vis[source] = true;
    while (qhead < qtail) {
        int u = q[qhead++];
        for (int w = head[u]; w != -1; w = next[w]) if (cap[w] > 0 && !r_vis[dest[w]]) {
            r_vis[dest[w]] = true; q[qtail++] = dest[w];
        }
    }
}

}

int n, m;
std::vector<int> e[MAXN];
std::map<std::pair<int, int>, int> e_id;

bool marked[MAXN] = { false };
int sts[MAXN];
int dep[MAXN], anc[MAXN][LOGN];

void dfs_sts(int u, int p = -1)
{
    sts[u] = 1;
    for (std::vector<int>::iterator v = e[u].begin(); v != e[u].end(); ++v) if (!marked[*v] && *v != p) {
        dfs_sts(*v, u);
        sts[u] += sts[*v];
    }
}

int centroid(int u, int cc_sz)
{
    for (std::vector<int>::iterator v = e[u].begin(); v != e[u].end(); ++v) if (!marked[*v]) {
        if (sts[*v] < sts[u] && 2 * sts[*v] > cc_sz) return centroid(*v, cc_sz);
    }
    return u;
}

int id = 0;
std::map<int, int> component[MAXN];
std::map<int, int> component_par[MAXN];

void dfs_component(int c, int u, int p)
{
    component[c][u] = id++;
    component_par[c][u] = p;
    for (std::vector<int>::iterator v = e[u].begin(); v != e[u].end(); ++v) if (!marked[*v] && *v != p) {
        dfs_component(c, *v, u);
    }
}

void decompose(int u, int p = -1, int d = 0)
{
    dfs_sts(u);
    int c = centroid(u, sts[u]);
    marked[c] = true;

    dep[c] = d;
    anc[c][0] = p;
    for (int i = 1; i < LOGN; ++i)
        anc[c][i] = (anc[c][i - 1] == -1 ? -1 : anc[anc[c][i - 1]][i - 1]);

    for (std::vector<int>::iterator v = e[c].begin(); v != e[c].end(); ++v)
        if (!marked[*v]) dfs_component(c, *v, c);

    for (std::vector<int>::iterator v = e[c].begin(); v != e[c].end(); ++v)
        if (!marked[*v]) decompose(*v, c, d + 1);
    marked[c] = false;
}

inline int decomposition_lca(int u, int v)
{
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = LOGN - 1; i >= 0; --i)
        if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; --i)
        if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
        e_id[std::make_pair(u, v)] = e_id[std::make_pair(v, u)] = i;
    }

    decompose(0);

    nwf::init(n + m + id + 2);
    nwf::source = n + m + id;
    nwf::sink = n + m + id + 1;

    for (int i = 1; i < n; ++i)
        nwf::add_edge(i, nwf::sink, 1);
    for (int i = 0; i < m; ++i)
        nwf::add_edge(nwf::source, n + i, 1);

    for (int u = 0; u < n; ++u) {
        for (std::map<int, int>::iterator i = component[u].begin(); i != component[u].end(); ++i) {
            v = component_par[u][i->first];
            nwf::add_edge(n + m + i->second, e_id[std::make_pair(i->first, v)], INF);
            if (u != v) nwf::add_edge(n + m + i->second, n + m + component[u][v], INF);
        }
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        int c = decomposition_lca(u, v);
        if (u != c) nwf::add_edge(n + i, n + m + component[c][u], INF);
        if (v != c) nwf::add_edge(n + i, n + m + component[c][v], INF);
    }

    int k = nwf::deluge();
    printf("%d\n", k);
    nwf::bfs_residual();

    std::vector<int> edges, paths;
    for (int i = 1; i < n; ++i) if (nwf::r_vis[i]) edges.push_back(i);
    for (int i = 0; i < m; ++i) if (!nwf::r_vis[n + i]) paths.push_back(i);

    printf("%u", paths.size());
    for (std::vector<int>::iterator i = paths.begin(); i != paths.end(); ++i) printf(" %d", *i + 1);
    putchar('\n');
    printf("%u", edges.size());
    for (std::vector<int>::iterator i = edges.begin(); i != edges.end(); ++i) printf(" %d", *i);
    putchar('\n');

    return 0;
}