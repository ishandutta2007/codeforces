#include <cstdio>
#include <vector>
static const int MAXN = 1008;
static const int MAXM = 200006;
static const int MAXQ = 200006;

int n, m, q;
int u[MAXM], v[MAXM];
int l[MAXQ], r[MAXQ], s[MAXQ], t[MAXQ];
bool ans[MAXQ];
std::vector<int> queries_with_l[MAXM];

int f[MAXN][MAXN];  // f[u][v] = Min. R to go from u to v in current graph

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        --u[i]; --v[i];
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%d%d", &l[i], &r[i], &s[i], &t[i]);
        --l[i]; --r[i]; --s[i]; --t[i];
        queries_with_l[l[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) f[i][j] = MAXM;  // Disconnected
    for (int i = m - 1; i >= 0; --i) {
        f[u[i]][v[i]] = f[v[i]][u[i]] = i;
        for (int w = 0; w < n; ++w)
            if (f[u[i]][w] > f[v[i]][w]) f[u[i]][w] = f[v[i]][w];
        for (int w = 0; w < n; ++w)
            if (f[v[i]][w] > f[u[i]][w]) f[v[i]][w] = f[u[i]][w];
        for (std::vector<int>::iterator p = queries_with_l[i].begin();
            p != queries_with_l[i].end(); ++p)
        {
            ans[*p] = (f[s[*p]][t[*p]] <= r[*p]);
        }
    }

    for (int i = 0; i < q; ++i) puts(ans[i] ? "Yes" : "No");
    return 0;
}