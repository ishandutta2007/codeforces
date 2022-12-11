#include <cstdio>
#include <vector>
static const int INF = 0x3fffffff;
static const int MAXN = 5e5 + 6;
static const int ALPHA = 22;
static const int MASK_SZ = 1 << ALPHA;
typedef std::vector<int> childlist;
template <typename T> inline bool upd_max(T &var, const T val) { if (var < val) { var = val; return true; } else return false; }

int n;
childlist e[MAXN];
int dep[MAXN], sts[MAXN], pfc[MAXN];
int mask[MAXN];
int bucket[MASK_SZ] = { 0 };
int ans[MAXN];

void dfs_calc_sts(int u)
{
    sts[u] = 1;
    int max_sts = -1; pfc[u] = -1;
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) {
        dep[*i] = dep[u] + 1;
        dfs_calc_sts(*i);
        sts[u] += sts[*i];
        if (upd_max(max_sts, sts[*i])) pfc[u] = *i;
    }
}

void dfs_throwin_buckets(int u)
{
    upd_max(bucket[mask[u]], dep[u]);
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) dfs_throwin_buckets(*i);
}
void dfs_clear_buckets(int u)
{
    bucket[mask[u]] = -INF;
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) dfs_clear_buckets(*i);
}
void dfs_update_answer(int r, int u)
{
    upd_max(ans[r], bucket[mask[u]] + dep[u] - 2 * dep[r]);
    for (int k = 0; k < ALPHA; ++k)
        upd_max(ans[r], bucket[mask[u] ^ (1 << k)] + dep[u] - 2 * dep[r]);
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) dfs_update_answer(r, *i);
}
void dfs_calc_ans(int u)
{
    ans[u] = 0;
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (*i != pfc[u]) {
        dfs_calc_ans(*i);
        dfs_clear_buckets(*i);
        upd_max(ans[u], ans[*i]);
    }
    if (pfc[u] != -1) { dfs_calc_ans(pfc[u]); upd_max(ans[u], ans[pfc[u]]); }
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (*i != pfc[u]) {
        dfs_update_answer(u, *i);
        dfs_throwin_buckets(*i);
    }
    upd_max(ans[u], bucket[mask[u]] + dep[u] - 2 * dep[u]);
    for (int k = 0; k < ALPHA; ++k)
        upd_max(ans[u], bucket[mask[u] ^ (1 << k)] + dep[u] - 2 * dep[u]);
    upd_max(bucket[mask[u]], dep[u]);
    //printf("%d: %d | %d |", u, mask[u], ans[u]); for (int i = 0; i < MASK_SZ; ++i) if (bucket[i] >= 0) printf(" %d(%d)", i, bucket[i]); putchar('\n');
}

int main()
{
    scanf("%d", &n);
    mask[0] = 0;
    int p_i; char c_i;
    for (int i = 1; i < n; ++i) {
        scanf("%d %c", &p_i, &c_i); --p_i; c_i -= 'a';
        e[p_i].push_back(i);
        mask[i] = mask[p_i] ^ (1 << c_i);
    }

    for (int i = 0; i < MASK_SZ; ++i) bucket[i] = -INF;
    dep[0] = 0;
    dfs_calc_sts(0);
    dfs_calc_ans(0);

    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    return 0;
}