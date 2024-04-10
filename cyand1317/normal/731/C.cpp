#include <cstdio>
#include <algorithm>
#include <vector>
static const int MAXN = 200006;
static const int MAXM = 200006;
static const int MAXK = 200006;

int n, m, k;
int c[MAXN];
int l[MAXM], r[MAXM];
std::vector<int> rt[MAXN];

namespace dsu {
    int p[MAXN];
    inline void initialize(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void unite(int u, int v) { u = root(u), v = root(v); p[u] = v; }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) { scanf("%d", &c[i]); --c[i]; }
    for (int i = 0; i < m; ++i) { scanf("%d%d", &l[i], &r[i]); --l[i], --r[i]; }

    dsu::initialize(n);
    int ans = 0;
    for (int i = 0; i < m; ++i) dsu::unite(l[i], r[i]);
    for (int i = 0; i < n; ++i) rt[dsu::root(i)].push_back(c[i]);
    for (int i = 0; i < n; ++i) if (!rt[i].empty()) {
        std::sort(rt[i].begin(), rt[i].end());
        int max = 1, max_id = rt[i][0], cur = 1;
        for (int j = 1; j < (int)rt[i].size(); ++j) {
            if (rt[i][j] == rt[i][j - 1]) ++cur;
            else {
                if (cur > max) { max = cur; max_id = rt[i][j - 1]; }
                cur = 1;
            }
        }
        if (cur > max) { max = cur; max_id = rt[i].back(); }
        ans += (int)rt[i].size() - max;
    }

    printf("%d\n", ans);
    return 0;
}