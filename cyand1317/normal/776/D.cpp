#include <cstdio>
#include <vector>
static const int MAXN = 1e5 + 4;

int n, m;
bool initial[MAXN];
std::vector<int> sw[MAXN];

namespace dsu {
    int p[MAXN * 2];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return p[u] == u ? u : (p[u] = root(p[u])); }
    inline void unite(int u, int v) { u = root(u), v = root(v); if (u != v) p[u] = v; }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &initial[i]);
    int x_i, y_i;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x_i);
        for (int j = 0; j < x_i; ++j) {
            scanf("%d", &y_i); --y_i;
            sw[y_i].push_back(i);
        }
    }

    dsu::init(m * 2);
    for (int i = 0; i < n; ++i) {
        if (initial[i]) {
            dsu::unite(sw[i][0] * 2, sw[i][1] * 2);
            dsu::unite(sw[i][0] * 2 + 1, sw[i][1] * 2 + 1);
        } else {
            dsu::unite(sw[i][0] * 2, sw[i][1] * 2 + 1);
            dsu::unite(sw[i][1] * 2, sw[i][0] * 2 + 1);
        }
        if (dsu::root(sw[i][0] * 2) == dsu::root(sw[i][0] * 2 + 1)) {
            puts("NO"); return 0;
        }
    }

    puts("YES"); return 0;
}