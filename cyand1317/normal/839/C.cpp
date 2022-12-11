#include <cstdio>
#include <vector>
static const int MAXN = 100004;

int n;
std::vector<int> e[MAXN];

double ans = 0;

void dfs(int u, int p, int d, double prob)
{
    int ct = 0;
    for (int v : e[u]) if (v != p) ++ct;
    for (int v : e[u]) if (v != p) dfs(v, u, d + 1, prob / ct);
    if (ct == 0) ans += prob * d;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(0, -1, 0, 1.0);
    printf("%.8lf\n", ans);

    return 0;
}