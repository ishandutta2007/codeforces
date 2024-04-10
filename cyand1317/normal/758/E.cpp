#include <cstdio>
#include <algorithm>
#include <vector>
using std::min;
using std::max;
typedef long long int64;
static const int MAXN = 2e5 + 4;
static const int MAXM = 2e5 + 2;

int n;
int head[MAXN], srce[MAXM], dest[MAXM], wgh[MAXM], str[MAXM], next[MAXM];
inline void add_edge(int u, int v, int w, int p) {
    static int e = 0;
    srce[e] = u; dest[e] = v; wgh[e] = w; str[e] = p; next[e] = head[u]; head[u] = e++;
}

int64 st_sum[MAXN];
int64 delta[MAXM] = { 0 };
bool dfs_calc(int u)
{
    st_sum[u] = 0;
    for (int e = head[u]; e != -1; e = next[e]) {
        if (!dfs_calc(dest[e])) return false;
        delta[e] += min<int64>(wgh[e] - 1, -st_sum[dest[e]] + str[e]);
        if (delta[e] < 0) return false;
        st_sum[u] += (st_sum[dest[e]] + wgh[e] - delta[e]);
    }
    return true;
}

int64 dfs_distribute(int u, int64 tot)
{
    int64 used = 0;
    for (int e = head[u]; e != -1; e = next[e]) {
        int64 cur = min(tot - used, delta[e]);
        delta[e] -= cur;
        used += cur;
    }
    for (int e = head[u]; e != -1; e = next[e]) {
        used += dfs_distribute(dest[e], min(tot - used, -st_sum[dest[e]] + str[e] - delta[e]));
    }
    return used;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v, w, p;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d%d%d", &u, &v, &w, &p); --u, --v;
        add_edge(u, v, w, p);
    }

    if (!dfs_calc(0)) { puts("-1"); return 0; }
    dfs_distribute(0, 1LL << 62);

    printf("%d\n", n);
    for (int i = 0; i < n - 1; ++i)
        printf("%d %d %d %d\n", srce[i] + 1, dest[i] + 1, (int)(wgh[i] - delta[i]), (int)(str[i] - delta[i]));

    return 0;
}