#include <cstdio>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int BITS = 22;

int n;
int a[MAXN], d[MAXN];
int head[MAXN], dest[MAXN * 2], next[MAXN * 2];
inline void add_edge(int u, int v) {
    static int w = 0; dest[w] = v; next[w] = head[u]; head[u] = w++;
}

int par[MAXN], ct[MAXN][BITS][2] = {{{ 0 }}};
void dfs(int u, int p = -1)
{
    par[u] = p; d[u] = (p == -1 ? 0 : d[p]) ^ a[u];
    for (int i = 0; i < BITS; ++i) ++ct[u][i][(d[u] >> i) & 1];
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        dfs(dest[w], u);
        for (int i = 0; i < BITS; ++i) {
            ct[u][i][0] += ct[dest[w]][i][0];
            ct[u][i][1] += ct[dest[w]][i][1];
        }
    }
}

int64 calc(int u, int bit)
{
    int64 ans = 0;
    int accum[2] = { 0, 0 };
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != par[u]) {
        ans += ct[dest[w]][bit][0] * accum[1 ^ ((a[u] >> bit) & 1)];
        ans += ct[dest[w]][bit][1] * accum[0 ^ ((a[u] >> bit) & 1)];
        accum[0] += ct[dest[w]][bit][0];
        accum[1] += ct[dest[w]][bit][1];
    }
    ans += ct[u][bit][1 ^ (par[u] == -1 ? 0 : ((d[par[u]] >> bit) & 1))];
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int u, v;
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v); add_edge(v, u);
    }

    dfs(0);
    int64 ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < BITS; ++j) ans += (1LL << j) * calc(i, j);
    }

    printf("%I64d\n", ans);
    return 0;
}