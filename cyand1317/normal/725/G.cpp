#include <cstdio>
#include <algorithm>
#include <utility>
static const int INF = 0x7fffffff;
static const int MAXN = 200006;
static const int MAXM = 200004;
template <typename T> inline bool upd_max(T &var, const T val) {
    if (var < val) { var = val; return true; } else return false;
}

int n, m, p[MAXN];
int x[MAXM], t[MAXM], qid[MAXM], qans[MAXM];

int head[MAXN], dest[MAXN], next[MAXN];
inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

// Heavy-light decomposition
int dep[MAXN], sts[MAXN], pfc[MAXN], dfn[MAXN], hct[MAXN], seq[MAXN];
void dfs_first(int u, int d = 0)
{
    dep[u] = d; sts[u] = 1; pfc[u] = -1;
    int max_sts = -1;
    for (int w = head[u]; w != -1; w = next[w]) {
        dfs_first(dest[w], d + 1);
        sts[u] += sts[dest[w]];
        if (upd_max(max_sts, sts[dest[w]])) pfc[u] = dest[w];
    }
}
void dfs_second(int u, int top = 0)
{
    static int epoch = -1;
    seq[dfn[u] = ++epoch] = u; hct[u] = top;
    if (pfc[u] != -1) dfs_second(pfc[u], top);
    for (int w = head[u]; w != -1; w = next[w])
        if (dest[w] != pfc[u]) dfs_second(dest[w], dest[w]);
}

// Segment tree
namespace sgt {

static const int MAXN = ::MAXN * 2;
int sz = 0;
int l[MAXN], r[MAXN], lch[MAXN], rch[MAXN], val[MAXN], tag[MAXN];

inline void push(int idx) {
    if (lch[idx] == -1 || tag[idx] <= -INF) return;
    tag[lch[idx]] = tag[rch[idx]] = tag[idx];
    val[lch[idx]] = r[lch[idx]] * 2 + tag[idx];
    val[rch[idx]] = r[rch[idx]] * 2 + tag[idx];
    tag[idx] = -INF;
}
inline void update(int idx) {
    val[idx] = std::max(val[lch[idx]], val[rch[idx]]);
}

int build(int L, int R) {
    int idx = sz++;
    l[idx] = L, r[idx] = R; val[idx] = tag[idx] = -INF;
    if (L == R) lch[idx] = rch[idx] = -1;
    else {
        int M = (L + R) >> 1;
        lch[idx] = build(L, M);
        rch[idx] = build(M + 1, R);
    }
    return idx;
}

int QL, QR, QV;
void modify(int idx) {
    push(idx);
    if (l[idx] >= QL && r[idx] <= QR) {
        tag[idx] = QV; val[idx] = r[idx] * 2 + QV; return;
    }
    if (r[lch[idx]] >= QL) modify(lch[idx]);
    if (l[rch[idx]] <= QR) modify(rch[idx]);
    update(idx);
}
inline void modify(int L, int R, int V) {
    QL = L, QR = R, QV = V; modify(0);
}

int query(int idx) {
    if (val[idx] <= QV) return -1;
    if (lch[idx] == -1) return l[idx];
    push(idx);
    int ans = -1;
    if (l[rch[idx]] <= QR && (ans = query(rch[idx])) != -1) return ans;
    if (r[lch[idx]] >= QL && (ans = query(lch[idx])) != -1) return ans;
    update(idx);
    return -1;
}
inline int query(int L, int R, int V) {
    QL = L, QR = R, QV = V; return query(0);
}

}

inline bool qid_cmp(const int lhs, const int rhs) {
    return
        std::make_pair(t[lhs] + dep[x[lhs]], x[lhs]) <
        std::make_pair(t[rhs] + dep[x[rhs]], x[rhs]);
}

inline int process_query(int u, int time)
{
    int v = u;
    // Find out where the answer will come from (w=v)
    //printf("Process_Query %d %d\n", u, time);
    while (true) {
        int w = sgt::query(dfn[hct[v]], dfn[v], time + dfn[v]);
        if (w != -1) {
            time += (dep[v] - dep[seq[w]]); v = seq[w]; break;
        }
        if (v == 0) break;
        time += (dep[v] - dep[p[hct[v]]]);
        v = p[hct[v]];
    }
    int ret = time + dep[u] - dep[v];
    // Modify the (u  w=v) path
    while (true) {
        if (hct[u] == hct[v]) {
            if (u != v) sgt::modify(dfn[v] + 1, dfn[u], time - dfn[v]);
            break;
        }
        sgt::modify(dfn[hct[u]], dfn[u], time + dep[u] - dep[v] - dfn[u]);
        u = p[hct[u]];
    }
    //printf("Process_Query %d %d\t* Finish (%d)\n", u, time, ret);
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) head[i] = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]); add_edge(p[i], i);
    }
    dfs_first(0);
    dfs_second(0);
    sgt::build(0, n);
    //for (int i = 0; i <= n; ++i) printf("%d\tDFN=%d PFC=%d HCT=%d\n", i, dfn[i], pfc[i], hct[i]);

    for (int i = 0; i < m; ++i) { scanf("%d%d", &x[i], &t[i]); qid[i] = i; }
    std::sort(qid, qid + m, qid_cmp);
    for (int i = 0; i < m; ++i) qans[qid[i]] = process_query(x[qid[i]], t[qid[i]]);

    for (int i = 0; i < m; ++i) printf("%d%c", qans[i], i == m - 1 ? '\n' : ' ');
    return 0;
}