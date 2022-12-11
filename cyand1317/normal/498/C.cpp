#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
// With reference and thanks to submission #9252043

static const int MAXN = 104;
static const int MAXM = 104;
static const int INF32 = 0x3fffffff;

int n, m;
int a[MAXN];
int x[MAXM], y[MAXM];
typedef std::map<int, short> factorization;
factorization f[MAXN];
std::set<int> factors;

namespace nwf {
// Dinic doesn't seem to work fast enough here...? (_ _)

int n, source, sink;
int g[MAXN][MAXN];

inline void clear_graph() {
    std::fill(&g[0][0], &g[0][0] + (sizeof g / sizeof g[0][0]), 0);
}

bool vis[MAXN];
int augment(int u, int cap = INF32) {
    if (u == sink) return cap;
    if (vis[u]) return 0;

    vis[u] = true;
    int aug;
    for (int i = 0; i < n; ++i)
        if (g[u][i] > 0 &&
            (aug = augment(i, std::min(cap, g[u][i]))) > 0)
        {
            g[u][i] -= aug;
            g[i][u] += aug;
            return aug;
        }
    return 0;
}

inline int deluge() {
    int kotae = 0, aug;
    do {
        std::fill(&vis[0], &vis[0] + n, false);
        kotae += (aug = augment(source));
    } while (aug > 0);
    return kotae;
}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int t = a[i], ct;
        for (int j = 2; j * j <= t; ++j) if (t % j == 0) {
            ct = 0;
            do {
                ++ct; t /= j;
            } while (t % j == 0);
            f[i][j] = ct;
            factors.insert(j);
        }
        if (t > 1) {
            f[i][t] = 1;
            factors.insert(t);
        }
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x[i], &y[i]); --x[i], --y[i];
        if (x[i] % 2 != 0) std::swap(x[i], y[i]);
    }

    nwf::source = n;
    nwf::sink = n + 1;
    nwf::n = n + 2;
    int kotae = 0;
    for (std::set<int>::iterator w = factors.begin(); w != factors.end(); ++w) {
        nwf::clear_graph();
        for (int i = 0; i < m; ++i) nwf::g[x[i]][y[i]] = INF32;
        for (int i = 0; i < n; ++i)
            if (i % 2 == 0) nwf::g[nwf::source][i] = f[i][*w];
            else nwf::g[i][nwf::sink] = f[i][*w];
        kotae += nwf::deluge();
    }

    printf("%d\n", kotae);
    return 0;
}