#include <cstdio>
#include <utility>
static const int MAXN = 1e5 + 4;
template <typename T> inline void swap(T &a, T &b) { static T t; t = a, a = b, b = t; }

int n, m;
int head[MAXN], dest[MAXN * 2], next[MAXN * 2];
inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

int route[MAXN], route_e[MAXN], d = 0;
int vis[MAXN] = { 0 };
int cycle[MAXN], cycle_sz = -1;
int in_cycle[MAXN];
void dfs_find_cycle(int u, int p = -1) {
    vis[u] = 1; route[d++] = u;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        if (vis[dest[w]] == 0) {
            dfs_find_cycle(dest[w], u);
            if (cycle_sz != -1) break;
        } else if (vis[dest[w]] == 1) {
            // Cycle found!
            cycle_sz = 0;
            for (int i = d - 1; i >= 0 && route[i] != dest[w]; --i) {
                cycle[cycle_sz++] = route[i];
            }
            cycle[cycle_sz++] = dest[w];
            for (int i = 0; i < cycle_sz; ++i) in_cycle[cycle[i]] = i;
        }
    }
    vis[u] = 2; --d;
}

int root[MAXN], par[MAXN], dep[MAXN], sts[MAXN], pfc[MAXN];
int dfn[MAXN], hct[MAXN];
void dfs_first(int r, int u, int p = -1, int d = 0) {
    root[u] = r; par[u] = p; dep[u] = d; sts[u] = 1; pfc[u] = -1;
    int max_sts = -1;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p && in_cycle[dest[w]] == -1) {
        dfs_first(r, dest[w], u, d + 1);
        sts[u] += sts[dest[w]];
        if (max_sts < sts[dest[w]]) {
            max_sts = sts[dest[w]]; pfc[u] = dest[w];
        }
    }
}
void dfs_second(int u, int top) {
    static int epoch = 0;
    dfn[u] = epoch++; hct[u] = top;
    if (pfc[u] != -1) dfs_second(pfc[u], top);
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != par[u] && in_cycle[dest[w]] == -1 && dest[w] != pfc[u]) {
        dfs_second(dest[w], dest[w]);
    }
}

struct sgt {

static const int MAXN = ::MAXN * 2;

int sz;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN], sum[MAXN]; bool tag[MAXN];

inline void push(int idx) {
    if (lch[idx] == -1 || !tag[idx]) return;
    tag[lch[idx]] ^= 1; sum[lch[idx]] = r[lch[idx]] - l[lch[idx]] + 1 - sum[lch[idx]];
    tag[rch[idx]] ^= 1; sum[rch[idx]] = r[rch[idx]] - l[rch[idx]] + 1 - sum[rch[idx]];
    tag[idx] = false;
}
inline void update(int idx) {
    if (lch[idx] == -1) return;
    sum[idx] = sum[lch[idx]] + sum[rch[idx]];
}
int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R; sum[idx] = 0; tag[idx] = false;
    if (L == R) {
        lch[idx] = rch[idx] = -1;
    } else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
    }
    return idx;
}
inline void build(int RG) { sz = 0; build(0, RG - 1); }

int QL, QR;
int toggle(int idx) {
    push(idx);
    if (l[idx] >= QL && r[idx] <= QR) {
        sum[idx] = r[idx] - l[idx] + 1 - sum[idx];
        tag[idx] ^= 1;
        return sum[idx] - (r[idx] - l[idx] + 1 - sum[idx]);
    }
    int ans = 0;
    if (r[lch[idx]] >= QL) ans += toggle(lch[idx]);
    if (l[rch[idx]] <= QR) ans += toggle(rch[idx]);
    update(idx);
    return ans;
}
// Returns: delta of on-edges
bool f[MAXN];
inline int toggle(int L, int R) {
    QL = L, QR = R; return toggle(0);
}

inline bool full() {
    return (sum[0] == r[0] + 1);
}

} tree_sgt, cycle_sgt = { 0 };

int ans;

inline void hld_mov_toggle(int &u) {
    ans -= tree_sgt.toggle(dfn[hct[u]], dfn[u]); u = par[hct[u]];
}
void hld_toggle(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (hct[u] != hct[v]) {
        if (dep[hct[u]] < dep[hct[v]]) hld_mov_toggle(v);
        else hld_mov_toggle(u);
    }
    if (dep[u] > dep[v]) swap(u, v);
    if (u != v) ans -= tree_sgt.toggle(dfn[u] + 1, dfn[v]);
}

void cycle_toggle(int u, int v) {
    if (u == v) return;
    int start = u;  // for correct lexicographical order
    if (u > v) swap(u, v);
    std::pair<int, int> rg, lf;
    rg = std::make_pair(v - u, cycle[(start + 1) % cycle_sz]);
    lf = std::make_pair(u - v + cycle_sz, cycle[(start - 1 + cycle_sz) % cycle_sz]);
    if (start != u) swap(lf.second, rg.second);
    if (rg < lf) {
        ans -= cycle_sgt.toggle(u + 1, v);
    } else {
        ans -= cycle_sgt.toggle(0, u);
        if (v + 1 <= cycle_sz - 1) ans -= cycle_sgt.toggle(v + 1, cycle_sz - 1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v); add_edge(v, u);
    }
    for (int i = 0; i < n; ++i) in_cycle[i] = -1;
    dfs_find_cycle(0);
    //for (int i = 0; i < cycle_sz; ++i) printf("%d%c", cycle[i] + 1, i == cycle_sz - 1 ? '\n' : ' ');
    for (int i = 0; i < cycle_sz; ++i) {
        dfs_first(cycle[i], cycle[i]);
        dfs_second(cycle[i], cycle[i]);
    }
    tree_sgt.build(n);
    cycle_sgt.build(cycle_sz);

    ans = n;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        int root_u = root[u], root_v = root[v];
        if (root_u == root_v) {
            hld_toggle(u, v);
        } else {
            hld_toggle(u, root[u]);
            hld_toggle(v, root[v]);
            cycle_toggle(in_cycle[root[u]], in_cycle[root[v]]);
        }
        printf("%d\n", ans + cycle_sgt.full());
    }

    return 0;
}