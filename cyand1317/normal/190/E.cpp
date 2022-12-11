#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
#include <vector>
static const int MAXN = 5e5 + 4;
static const int MAXM = 2e6 + 4;

int n, m;
int head[MAXN], deg[MAXN] = { 0 }, dest[MAXM], next[MAXM];
inline void add_edge(int u, int v) {
    static int w = 0;
    ++deg[u]; dest[w] = v; next[w] = head[u]; head[u] = w++;
}
typedef std::pair<int, int> edge;
std::set<edge> e;
bool vis[MAXN] = { false };
std::vector<int> cc[MAXN];

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void unite(int u, int v) { u = root(u), v = root(v); p[u] = v; }
};

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v); add_edge(v, u);
        e.insert(edge(u < v ? u : v, u < v ? v : u));
    }

    int min_deg = MAXN, min_vrt = -1;
    for (int i = 0; i < n; ++i) {
        if (min_deg > deg[i]) min_deg = deg[i], min_vrt = i;
    }

    vis[min_vrt] = true;
    for (int w = head[min_vrt]; w != -1; w = next[w]) vis[dest[w]] = true;
    dsu::init(n);
    int nvis_ct = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) dsu::unite(min_vrt, i), ++nvis_ct;

    std::vector<int> vis_vrt;
    for (int i = 0; i < n; ++i) if (vis[i]) {
        vis_vrt.push_back(i);
        int ct = 0;
        for (int w = head[i]; w != -1; w = next[w]) if (!vis[dest[w]]) ++ct;
        if (ct != nvis_ct) { dsu::unite(min_vrt, i); continue; }
    }

    std::sort(vis_vrt.begin(), vis_vrt.end());
    for (int i = 0; i < (int)vis_vrt.size(); ++i)
        for (int j = i + 1; j < (int)vis_vrt.size(); ++j)
            if (e.find(edge(vis_vrt[i], vis_vrt[j])) == e.end()) {
                dsu::unite(vis_vrt[i], vis_vrt[j]);
            }

    for (int i = 0; i < n; ++i) cc[dsu::root(i)].push_back(i);
    int cc_ct = 0;
    for (int i = 0; i < n; ++i) if (dsu::root(i) == i) ++cc_ct;
    printf("%d\n", cc_ct);
    for (int i = 0; i < n; ++i) if (dsu::root(i) == i) {
        printf("%lu", cc[i].size());
        for (std::vector<int>::iterator j = cc[i].begin(); j != cc[i].end(); ++j)
            printf(" %d", *j + 1);
        putchar('\n');
    }

    return 0;
}