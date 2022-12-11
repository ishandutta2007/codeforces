#include <cstdio>
#include <algorithm>
using std::min;
static const int MAXN = 1e5 + 4;
static const int MAXC = 1e3 + 4;

int n, m;
// count[diameter][colour]
int marker_ct[MAXC][MAXC] = {{ 0 }}, cap_ct[MAXC][MAXC] = {{ 0 }};
int marker_tot[MAXC] = { 0 }, cap_tot[MAXC] = { 0 };

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &v); --u, --v; ++marker_ct[v][u], ++marker_tot[v];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v; ++cap_ct[v][u], ++cap_tot[v];
    }

    int max_closed = 0, max_bel = 0;
    for (int i = 0; i < MAXC; ++i) {
        max_closed += min(marker_tot[i], cap_tot[i]);
        for (int j = 0; j < MAXC; ++j)
            max_bel += min(marker_ct[i][j], cap_ct[i][j]);
    }

    printf("%d %d\n", max_closed, max_bel);
    return 0;
}