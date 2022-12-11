#include <cstdio>
#include <vector>
typedef long long int64;
static const int64 INF64 = (1LL << 62);
static const int MAXN = 1e5 + 6;
struct edge {
    int v, w;
    edge() : v(-1), w(0) { }
    edge(int v, int w) : v(v), w(w) { }
};
typedef std::vector<edge> edgelist;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n;
edgelist e[MAXN];
int64 f[MAXN], g[MAXN];

void dfs_calc(int u, int p = -1)
{
    f[u] = g[u] = INF64;
    int64 max_save = 0, sum = 0;
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (i->v != p) {
        dfs_calc(i->v, u);
        sum += (g[i->v] + 2 * i->w);
        max_save = max(max_save, g[i->v] - f[i->v] + i->w);
    }
    g[u] = sum;
    f[u] = g[u] - max_save;
}

int main()
{
    scanf("%d", &n);
    int u, v, w;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d", &u, &v, &w); --u, --v;
        e[u].push_back(edge(v, w));
        e[v].push_back(edge(u, w));
    }

    dfs_calc(0);
    printf("%I64d\n", min(f[0], g[0]));

    return 0;
}