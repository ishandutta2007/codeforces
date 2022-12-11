#include <cstdio>
#include <map>
static const int MAXN = 1e5 + 4;
static const int MAXLEN = 24;
static const int HASH_BASE = 1000007;
static const int HASH_OFFSET = -'a' + 9;
typedef unsigned long long hash_t;

inline hash_t hash(const char *s) {
    hash_t ans = 0;
    for (; *s; ++s) ans = ans * HASH_BASE + *s + HASH_OFFSET;
    return ans;
}

namespace dsu {
    int p[MAXN * 2];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void unite(int u, int v) { u = root(u), v = root(v); if (u != v) p[u] = v; }
}

int n, m, q;
std::map<hash_t, int> w_idx;

int main()
{
    char w[MAXLEN], u[MAXLEN];

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%s", w); w_idx[hash(w)] = i;
    }

    // Relations
    dsu::init(n * 2);
    int ty;
    for (int i = 0; i < m; ++i) {
        scanf("%d%s%s", &ty, w, u);
        int x = w_idx[hash(w)], y = w_idx[hash(u)];
        // a1-a2 and b1-b2 are to be connected
        int a1 = x * 2, a2 = y * 2 + (ty - 1),
            b1 = x * 2 + 1, b2 = y * 2 + (2 - ty);
        a1 = dsu::root(a1), a2 = dsu::root(a2), b1 = dsu::root(b1), b2 = dsu::root(b2);
        if (b1 == a2) puts("NO");
        else { dsu::unite(a1, a2); dsu::unite(b1, b2); puts("YES"); }
    }

    // Queries
    for (int i = 0; i < q; ++i) {
        scanf("%s%s", w, u);
        int x = w_idx[hash(w)], y = w_idx[hash(u)];
        if (dsu::root(x * 2) == dsu::root(y * 2)) puts("1");
        else if (dsu::root(x * 2) == dsu::root(y * 2 + 1)) puts("2");
        else puts("3");
    }

    return 0;
}