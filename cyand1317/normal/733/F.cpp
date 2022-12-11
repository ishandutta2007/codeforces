#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 2e5 + 4;
static const int LOGN = 20;
static const int MAXM = 4e5 + 4;
template <typename T> inline bool update_min(T &var, const T val) { if (var > val) { var = val; return true; } else return false; }

int n, m, s;
struct edge {
    int src, dst, w, c;
    int id, next;
} e[MAXM];
inline bool operator < (const edge &lhs, const edge &rhs) {
    if (lhs.w != rhs.w) return lhs.w < rhs.w;
    else if (lhs.c != rhs.c) return lhs.c < rhs.c;
    else return lhs.id < rhs.id;
}
int head[MAXN];

bool k_slc[MAXM] = { false };
int64 k_ans = 0;
namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline bool unite(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return false;
        if (rand() & 1) p[u] = v; else p[v] = u;
        return true;
    }
};
void kruskal()
{
    dsu::init(n);
    for (int i = 0; i < m; ++i) if (dsu::unite(e[i * 2].src, e[i * 2].dst)) {
        k_slc[i * 2] = true;
        k_ans += e[i * 2].w;
    }
}

int dep[MAXN], anc[MAXN][LOGN];
std::pair<int, int> pat[MAXN][LOGN];
void dfs_mst(int u, int p = -1, int d = 0)
{
    //for (int i = 0; i < d; ++i) printf("  "); printf("%d\n", u + 1);
    dep[u] = d;
    anc[u][0] = p;
    for (int i = 1; i < LOGN; ++i) {
        anc[u][i] = (anc[u][i - 1] == -1) ? -1 : anc[anc[u][i - 1]][i - 1];
        pat[u][i] = (anc[u][i - 1] == -1) ? pat[u][i - 1] : std::max(pat[u][i - 1], pat[anc[u][i - 1]][i - 1]); // mdzz... mdzz... (_)
    }
    for (int w = head[u]; w != -1; w = e[w].next) if (e[w].dst != p) {
        pat[e[w].dst][0] = std::make_pair(e[w].w, w - w % 2);
        dfs_mst(e[w].dst, u, d + 1);
    }
}
inline std::pair<int, int> mst_path_max(int u, int v)
{
    if (dep[u] < dep[v]) std::swap(u, v);
    std::pair<int, int> ans = std::make_pair(0x80000000, -1);
    for (int i = 0; i < LOGN; ++i)
        if ((dep[u] - dep[v]) & (1 << i)) {
            ans = std::max(ans, pat[u][i]); u = anc[u][i];
        }
    if (u == v) return ans;
    for (int i = LOGN - 1; i >= 0; --i) if (anc[u][i] != anc[v][i]) {
        ans = std::max(ans, pat[u][i]);
        ans = std::max(ans, pat[v][i]);
        u = anc[u][i]; v = anc[v][i];
    }
    ans = std::max(ans, pat[u][0]);
    return ans;
}

int main()
{
    srand(1317111u);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) scanf("%d", &e[i + i].w);
    for (int i = 0; i < m; ++i) scanf("%d", &e[i + i].c);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &e[i + i].src, &e[i + i].dst);
        --e[i + i].src, --e[i + i].dst;
        e[i + i].id = i + 1;
        e[i + i + 1] = e[i + i];
        std::swap(e[i + i + 1].src, e[i + i + 1].dst);
    }
    scanf("%d", &s);
    for (int i = 0; i < m * 2; ++i) e[i].c = e[i].w - s / e[i].c;
    std::sort(e, e + m * 2);

    kruskal();
    //int r = dsu::root(0);
    //for (int i = 1; i < n; ++i) if (dsu::root(i) != r) { puts("Nah > <"); break; }
    int64 ans = (1LL << 62);
    int mst_remove = -1, edge_dec = -1;
    for (int i = 0; i < m; ++i) if (k_slc[i * 2])
        if (update_min(ans, k_ans - e[i * 2].w + e[i * 2].c)) {
            mst_remove = -1; edge_dec = i * 2;
        }

    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0; i < m * 2; ++i) if (k_slc[i - i % 2]) {
        e[i].next = head[e[i].src];
        head[e[i].src] = i;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < LOGN; ++j) pat[i][j] = std::make_pair(0x80000000, -1);
    //for (int i = 0; i < m; ++i) if (e[i * 2].w != e[i * 2 + 1].w) puts("Nah > <");
    dfs_mst(0);
    std::pair<int, int> t;
    for (int i = 0; i < m; ++i) if (!k_slc[i * 2])
        if (update_min(ans, k_ans - (t = mst_path_max(e[i * 2].src, e[i * 2].dst)).first + e[i * 2].c)) {
            mst_remove = t.second; edge_dec = i * 2;
        }

    printf("%I64d\n", ans);
    if (mst_remove != -1) {
        k_slc[mst_remove] = false;
        k_slc[edge_dec] = true;
    }
    e[edge_dec].w = e[edge_dec].c;
    for (int i = 0; i < m; ++i) if (k_slc[i * 2])
        printf("%d %d\n", e[i * 2].id, e[i * 2].w);

    return 0;
}