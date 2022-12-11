#include <cstdio>
#include <cstdlib>
static const int MAXN = 3004;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline void swap(T &a, T &b) { static T t; t = a, a = b, b = t; }

int n, k, p[MAXN], q[MAXN];
bool vis[MAXN] = { false };
int cyc_ct = 0;

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u ? u : (p[u] = root(p[u]))); }
    inline void unite(int u, int v) { u = root(u), v = root(v); (rand() & 1) ? (p[u] = v) : (p[v] = u); }
}

int main()
{
    srand(114514);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]); --p[i];
        q[p[i]] = i;
    }
    scanf("%d", &k);

    dsu::init(n);
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        for (int j = p[i]; j != i; j = p[j]) vis[j] = true, dsu::unite(j, i);
        ++cyc_ct;
    }
    int swaps = n - cyc_ct;
    printf("%d\n", std::abs(swaps - k));
    if (swaps == k) return 0;

    int w = 0;
    if (swaps > k) {
        // Break cycles
        for (int twt = 0; twt < swaps - k; ++twt) {
            while (p[w] == w) ++w;
            int v_imperial_order = n + 88;
            for (int v = p[w]; v != w; v = p[v])
                v_imperial_order = min(v_imperial_order, v);
            swap(p[w], p[v_imperial_order]);
            printf("%d %d ", w + 1, v_imperial_order + 1);
        }
    } else {
        // Connect cycles
        for (int v = 1; swaps != k && v < n; ++v) if (dsu::root(v) != dsu::root(w)) {
            printf("%d %d ", w + 1, v + 1);
            dsu::unite(v, w);
            --k;
        }
    }
    putchar('\n');

    return 0;
}