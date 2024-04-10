#include <cstdio>
#include <cstdlib>
#include <algorithm>

static const int MAXN = 1e5 + 4;

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void merge(int u, int v) { u = root(u), v = root(v); if (rand() & 1) p[u] = v; else p[v] = u; }
}

static int n, m;
static int c[MAXN];
static int r[MAXN];

int main()
{
    srand(893);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

    dsu::init(n);
    for (int i = 0, u, v; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        dsu::merge(u, v);
    }

    for (int i = 0; i < n; ++i) if (dsu::root(i) == i) r[i] = 0x7fffffff;
    for (int i = 0; i < n; ++i) {
        int u = dsu::root(i);
        r[u] = std::min(r[u], c[i]);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) if (dsu::root(i) == i) ans += r[i];

    printf("%I64d\n", ans);

    return 0;
}