#include <cstdio>
#include <set>
typedef long long int64;
static const int64 INF64 = 1LL << 61;
static const int MAXN = 2e5 + 8;
static const int MAXM = 4e5 + 8;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, a[MAXN];
int64 subt[MAXN];
int head[MAXN], dest[MAXM], next[MAXM];
std::multiset<int64> subt_colle;
int64 ans = -INF64;

inline void add_edge(int u, int v) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; head[u] = w++;
}

void dfs_calc_subt(int u, int p = -1)
{
    subt[u] = a[u];
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        dfs_calc_subt(dest[w], u);
        subt[u] += subt[dest[w]];
    }
    subt_colle.insert(subt[u]);
}

void dfs_update_ans(int u, int p = -1)
{
    subt_colle.erase(subt_colle.find(subt[u]));
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        dfs_update_ans(dest[w], u);
    }
    if (!subt_colle.empty()) upd_max(ans, subt[u] + *subt_colle.rbegin());
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int u_i, v_i;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u_i, &v_i); --u_i, --v_i;
        add_edge(u_i, v_i);
        add_edge(v_i, u_i);
    }

    dfs_calc_subt(0);
    dfs_update_ans(0);

    if (ans == -INF64) puts("Impossible"); else printf("%I64d\n", ans);
    return 0;
}