#include <climits>
#include <cstdio>
#include <algorithm>
#include <vector>

static const int MAXN = 1e5 + 4;
static const int LOGN = 20;
static const int MAXM = 1e6 + 5;

static int n, r, m;
static int a[MAXN];
static std::vector<int> e[MAXN];

static int epoch = 0, dfn[MAXN], ste[MAXN];
static int max_d = -1, dep[MAXN];
static std::vector<int> lv[MAXN];

void dfs(int u, int p, int d)
{
    dfn[u] = epoch++;
    max_d = std::max(max_d, d);
    dep[u] = d;
    lv[d].push_back(u);
    for (int v : e[u]) if (v != p) dfs(v, u, d + 1);
    ste[u] = epoch;
}

namespace psgt {

static const int MAXN = ::MAXN * (2 + ::LOGN * 2);

struct node {
    int l, r, lch, rch;
    int min;
} t[MAXN];

int sz = 0;

inline int build(int L, int R) {
    int idx = sz++;
    t[idx].l = L, t[idx].r = R;
    t[idx].min = INT_MAX;
    if (L == R) {
        t[idx].lch = t[idx].rch = -1;
    } else {
        int M = (L + R) >> 1;
        t[idx].lch = build(L, M);
        t[idx].rch = build(M + 1, R);
    }
    return idx;
}

inline int copy_node(int idx) {
    int nw = sz++;
    t[nw] = t[idx];
    return nw;
}

int QL, QR;

inline int query(int idx) {
    if (t[idx].l >= QL && t[idx].r <= QR) return t[idx].min;
    int ans = INT_MAX;
    if (t[t[idx].lch].r >= QL) ans = std::min(ans, query(t[idx].lch));
    if (t[t[idx].rch].l <= QR) ans = std::min(ans, query(t[idx].rch));
    return ans;
}

inline int query(int rt, int L, int R) { if (L > R) return INT_MAX; QL = L, QR = R; return query(rt); }

inline int modify(int idx) {
    idx = copy_node(idx);
    if (t[idx].lch == -1) { t[idx].min = QR; return idx; }
    if (t[t[idx].lch].r >= QL)
        t[idx].lch = modify(t[idx].lch);
    else
        t[idx].rch = modify(t[idx].rch);
    t[idx].min = std::min(t[t[idx].lch].min, t[t[idx].rch].min);
    return idx;
}

inline int modify(int rt, int P, int V) { QL = P, QR = V; return modify(rt); }

}

static int rt[MAXN];

int main()
{
    //fprintf(stderr, "%lu\n", sizeof psgt::t / 1048576);

    scanf("%d%d", &n, &r); --r;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0, u, v; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(r, -1, 0);
    for (int i = 0; i <= max_d; ++i) {
        rt[i] = (i == 0 ? psgt::build(0, n - 1) : rt[i - 1]);
        for (int u : lv[i])
            rt[i] = psgt::modify(rt[i], dfn[u], a[u]);
    }

    scanf("%d", &m);
    int last = 0;
    for (int i = 0; i < m; ++i) {
        int u, d;
        scanf("%d%d", &u, &d);
        u = (u + last) % n;
        d = (d + last) % n;
        d = std::min(max_d, dep[u] + d);
        printf("%d\n", last = psgt::query(rt[d], dfn[u], ste[u] - 1));
    }

    return 0;
}