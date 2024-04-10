#include <cstdio>
#include <algorithm>
#include <vector>
static const int MAXN = 1e5 + 4;
static const int LOGN = 18;

int n, q;
int p[MAXN];
std::vector<int> e[MAXN];

int dep[MAXN], anc[MAXN][LOGN];

void dfs(int u, int d = 0)
{
    dep[u] = d;
    anc[u][0] = p[u];
    for (int i = 1; i < LOGN; ++i)
        anc[u][i] = (anc[u][i - 1] == -1) ? -1 : anc[anc[u][i - 1]][i - 1];
    for (int v : e[u]) if (v != p[u]) dfs(v, d + 1);
}

inline int lca(int u, int v)
{
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = LOGN - 1; i >= 0; --i)
        if (dep[u] - (1 << i) >= dep[v]) u = anc[u][i];
    if (u == v) return v;
    for (int i = LOGN - 1; i >= 0; --i)
        if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}

inline int dist(int u, int v)
{
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main()
{
    scanf("%d%d", &n, &q);
    p[0] = -1;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &p[i]); --p[i];
        e[p[i]].push_back(i);
    }

    dfs(0);

    for (int i = 0, a, b, c; i < q; ++i) {
        scanf("%d%d%d", &a, &b, &c); --a, --b, --c;
        int ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
        int s = (ab + bc + ca) / 2;
        int x = s - ab, y = s - bc, z = s - ca;
        printf("%d\n", std::max(std::max(x, y), z) + 1);
    }

    return 0;
}