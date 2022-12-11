#include <cstdio>
#include <cstring>
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
static const int MAXN = 2005;
static const int MAXM = 2e5 + 5;

int n, m;
int head[MAXN], tail[MAXN], deg[MAXN] = { 0 }, dest[MAXM], next[MAXM];
bool vis[MAXN] = { false };
bool graph[MAXN][MAXN] = {{ false }};
int dep[MAXN], anc[MAXN];
int ans = 0;

inline void add_edge(int u, int v) {
    static int w = 0;
    if (tail[u] == -1) tail[u] = w;
    dest[w] = v; next[w] = head[u]; head[u] = w++; deg[v]++;
}

void dfs_cycles(int u, int p = -1, int d = 0)
{
    vis[u] = true; dep[u] = d; anc[u] = u;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        if (!vis[dest[w]]) {
            dfs_cycles(dest[w], u, d + 1);
            if (dep[anc[dest[w]]] < dep[anc[u]]) anc[u] = anc[dest[w]];
        } else {
            if (dep[dest[w]] < dep[anc[u]]) anc[u] = dest[w];
        }
    }
}

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u ? u : (p[u] = root(p[u]))); }
    inline void unite(int u, int v) { u = root(u), v = root(v); p[u] = v; }
}

int cc[MAXN], cc_sz;
void dfs_distance(int u, int d = 0)
{
    vis[u] = true; dep[u] = d;
    cc[cc_sz++] = u;
    for (int v = 0; v < n; ++v)
        if (!vis[v] && graph[u][v]) dfs_distance(v, d + 1);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = tail[i] = -1;
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v); add_edge(v, u);
    }

    for (int i = 0; i < n; ++i) if (!vis[i]) dfs_cycles(i);
    dsu::init(n);
    for (int i = 0; i < n; ++i) if (i != anc[i]) { ++ans; dsu::unite(i, anc[i]); }
    for (int i = 0; i < n; ++i) anc[i] = dsu::root(i);
    for (int i = 0; i < n; ++i) deg[i] = 0;
    for (int i = 0; i < n; ++i)
        for (int w = head[i]; w != -1; w = next[w]) if (anc[i] != anc[dest[w]]) {
            graph[anc[i]][anc[dest[w]]] = true;
            ++deg[anc[i]]; //++deg[anc[dest[w]]];
        }

    memset(vis, false, sizeof vis);
    for (int _i = 0, i; _i < n; ++_i) if (!vis[i = anc[_i]]) {
        cc_sz = 0; dfs_distance(i);
        int max_dist = -1, max_u = -1;
        for (int j = 0; j < cc_sz; ++j) {
            if (max_dist < dep[cc[j]] && deg[cc[j]] != 1) {
                max_dist = dep[cc[j]]; max_u = cc[j];
            }
            vis[cc[j]] = false;
        }
        if (cc_sz == 1 || max_u == -1) {
            for (int j = 0; j < cc_sz; ++j) vis[cc[j]] = true;
            ans += 1;   // +1 for each CC
            continue;
        }
        if (max_u == -1) {
            for (int j = 0; j < cc_sz; ++j) vis[cc[j]] = true;
            ans += 3;   // +1 for each CC
            continue;
        }
        cc_sz = 0; dfs_distance(max_u);
        max_dist = -1;
        for (int j = 0; j < cc_sz; ++j)
            if (max_dist < dep[cc[j]] && deg[cc[j]] != 1) {
                max_dist = dep[cc[j]]; max_u = cc[j];
            }
        ++max_dist;
        ans += (cc_sz - max_dist + 1); // +1 for each CC
        for (int j = 0; j < cc_sz; ++j)
            if (deg[cc[j]] == 1) --ans;
    }

    --ans;  // The last CC is excluded
    printf("%d\n", ans);

    return 0;
}