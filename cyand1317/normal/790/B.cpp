#include <cstdio>
#include <vector>
typedef long long int64;
static const int MAXN = 200004;
static const int MAXK = 6;

int n, k;
std::vector<int> e[MAXN];

int count[MAXN][MAXK] = {{ 0 }}, sz[MAXN] = { 0 };
int64 dist_sum[MAXN] = { 0 };
int64 tot_dist = 0;
int64 pairs[MAXK] = { 0 };
void dfs(int u, int p = -1)
{
    sz[u] = 1; count[u][0] = 1;
    for (int v : e[u]) if (v != p) {
        dfs(v, u);
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                pairs[(i + 1 + j) % k] += (int64)count[u][i] * count[v][j];
        for (int i = 0; i < k; ++i)
            count[u][(i + 1) % k] += count[v][i];
        tot_dist += dist_sum[u] * sz[v] + (dist_sum[v] + sz[v]) * sz[u];
        sz[u] += sz[v];
        dist_sum[u] += (dist_sum[v] + sz[v]);
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(0);
    int64 ans = tot_dist;
    for (int j = 0; j < k; ++j) ans += pairs[j] * (j == 0 ? 0 : (k - j));
    printf("%I64d\n", ans / k);
    return 0;
}