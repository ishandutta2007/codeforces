#include <cstdio>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

inline int64 qpow(int64 base, int exp)
{
    int64 ans = 1;
    for (; exp; exp >>= 1, (base *= base)__) if (exp & 1) (ans *= base)__;
    return ans;
}

int n;
struct edge {
    int v, w, t;
    edge(int v = 0, int w = 0, int t = 0) : v(v), w(w), t(t) { }
};
std::vector<edge> e[MAXN];

int64 ans = 1;

bool marked[MAXN] = { false };
int sts[MAXN];

inline void dfs_sts(int u, int p = -1)
{
    sts[u] = 1;
    for (edge &w : e[u]) if (w.v != p && !marked[w.v]) {
        dfs_sts(w.v, u);
        sts[u] += sts[w.v];
    }
}

inline int centroid(int u, int sz)
{
    for (edge &w : e[u]) if (!marked[w.v]) {
        if (sts[w.v] < sts[u] && 2 * sts[w.v] > sz) return centroid(w.v, sz);
    }
    return u;
}

struct path {
    int r, b, prod;
    path(int r = 0, int b = 0, int prod = 1) : r(r), b(b), prod(prod) { }
};

inline void dfs_collect(int u, int p, path dep, std::vector<path> &v)
{
    v.push_back(dep);
    for (edge &w : e[u]) if (w.v != p && !marked[w.v]) {
        dfs_collect(w.v, u, path(dep.r + (w.t == 0), dep.b + (w.t == 1), (int64)dep.prod * w.w _), v);
    }
}

namespace fwk {
    static const int MAXN = ::MAXN * 4;
    int f[MAXN] = { 0 };
    inline void add(int pos, int inc) { for (; pos < MAXN; pos += (pos & -pos)) f[pos] += inc; }
    inline int query(int rg) { int ans = 0; for (; rg; rg -= (rg & -rg)) ans += f[rg]; return ans; }
    inline int query(int lf, int rg) { return query(rg) - query(lf - 1); }
}

inline int64 count_pairs(std::vector<path> &v)
{
    int64 ans = 1;

    for (path &p : v) fwk::add(-(p.r - p.b * 2) + MAXN * 2, +1);
    for (path &p : v) (ans *= qpow(p.prod, fwk::query(p.r - p.b * 2 + MAXN * 2 - 1)))__;
    for (path &p : v) fwk::add(-(p.r - p.b * 2) + MAXN * 2, -1);

    for (path &p : v) fwk::add(-(p.b - p.r * 2) + MAXN * 2, +1);
    for (path &p : v) (ans *= qpow(p.prod, fwk::query(p.b - p.r * 2 + MAXN * 2 - 1)))__;
    for (path &p : v) fwk::add(-(p.b - p.r * 2) + MAXN * 2, -1);

    ans = qpow(ans, MODULUS - 2);
    for (path &p : v) (ans *= qpow(p.prod, v.size()))__;
    return ans;
}

inline void decompose(int u)
{
    dfs_sts(u);
    int c = centroid(u, sts[u]);
    marked[c] = true;

    for (edge &w : e[c]) if (!marked[w.v]) decompose(w.v);

    std::vector<path> q;
    int64 _x = ans;
    for (edge &w : e[c]) if (!marked[w.v]) {
        std::vector<path> quq;
        dfs_collect(w.v, -1, path(w.t == 0, w.t == 1, w.w), quq);
        (ans *= qpow(count_pairs(quq), MODULUS - 2))__;
        for (path &p : quq) q.push_back(p);
    }
    q.push_back(path(0, 0, 1));
    (ans *= count_pairs(q))__;

    marked[c] = false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0, u, v, w, t; i < n - 1; ++i) {
        scanf("%d%d%d%d", &u, &v, &w, &t); --u, --v;
        e[u].push_back(edge(v, w, t));
        e[v].push_back(edge(u, w, t));
    }

    decompose(0);
    printf("%I64d\n", ans);

    return 0;
}