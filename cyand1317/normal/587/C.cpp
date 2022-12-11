#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>

static const int MAXN = 1e5 + 9;
static const int LOGN = 18;

int n, m, q;
int head[MAXN * 2], dest[MAXN * 2], next[MAXN * 2];
std::vector<int> residents[MAXN];

inline void add_edge(int u, int v) {
    static int m = 0;
    dest[m] = v; next[m] = head[u]; head[u] = m++;
    dest[m] = u; next[m] = head[v]; head[v] = m++;
}

int dep[MAXN], par[MAXN][LOGN];
std::vector<int> pth[MAXN][LOGN];

inline void merge_top10(const std::vector<int> &u, const std::vector<int> &v,
    std::vector<int> &dst)
{
    std::merge(u.begin(), u.end(), v.begin(), v.end(), std::back_inserter(dst));
    if (dst.size() > 10) dst.resize(10);
}

void dfs(int u, int p = -1, int d = 0)
{
    dep[u] = d, par[u][0] = p;
    pth[u][0].insert(pth[u][0].begin(), residents[u].begin(), residents[u].end());
    for (int i = 1; i < LOGN; ++i) {
        if (par[u][i - 1] == -1) {
            par[u][i] = -1;
        } else {
            par[u][i] = par[par[u][i - 1]][i - 1];
            merge_top10(pth[u][i - 1], pth[par[u][i - 1]][i - 1], pth[u][i]);
        }
    }
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != p) {
        dfs(dest[w], u, d + 1);
    }
}

inline void update_ans(std::vector<int> &ans, const std::vector<int> &p)
{
    ans.insert(ans.begin(), p.begin(), p.end());
    std::sort(ans.begin(), ans.end());
    if (ans.size() > 10) ans.resize(10);
}
inline std::vector<int> lca(int u, int v)
{
    std::vector<int> ans;
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = LOGN - 1; i >= 0; --i) if ((dep[u] - dep[v]) & (1 << i)) {
        update_ans(ans, pth[u][i]);
        u = par[u][i];
    }
    if (u == v) {
        update_ans(ans, residents[u]);
        return ans;
    }
    for (int i = LOGN - 1; i >= 0; --i) if (par[u][i] != par[v][i]) {
        update_ans(ans, pth[u][i]); u = par[u][i];
        update_ans(ans, pth[v][i]); v = par[v][i];
    }
    update_ans(ans, pth[u][1]);
    update_ans(ans, residents[v]);
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v, a;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &u); --u;
        residents[u].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        std::sort(residents[i].begin(), residents[i].end());
        if (residents[i].size() > 10) residents[i].resize(10);
    }

    dfs(0);
    do {
        scanf("%d%d%d", &u, &v, &a); --u, --v;
        std::vector<int> ans = lca(u, v);
        if (ans.size() > a) ans.resize(a);
        printf("%lu", ans.size());
        for (std::vector<int>::iterator i = ans.begin(); i != ans.end(); ++i)
            printf(" %d", *i + 1);
        putchar('\n');
    } while (--q);

    return 0;
}