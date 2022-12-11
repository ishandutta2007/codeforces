#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXN = 100008;
static const int MAXM = 400008;
static const int MODULUS = 1e9 + 7;
#define _ % MODULUS
static const int BITS = 62;

int n, m, head[MAXN], dest[MAXM], next[MAXM];
int64 val[MAXM];
inline void add_edge(int u, int v, int64 w) {
    static int e = 0;
    dest[e] = v; val[e] = w; next[e] = head[u]; head[u] = e++;
}

int par[MAXN]; int64 path[MAXN]; bool vis[MAXN] = { false };
int cc[MAXN], cc_sz;
int64 cyc[MAXM]; int cyc_ct;
void dfs(int u)
{
    vis[u] = true;
    cc[cc_sz++] = u;
    for (int w = head[u]; w != -1; w = next[w]) if (dest[w] != par[u]) {
        if (!vis[dest[w]]) {
            par[dest[w]] = u;
            path[dest[w]] = path[u] ^ val[w];
            dfs(dest[w]);
        } else {
            cyc[cyc_ct++] = path[u] ^ path[dest[w]] ^ val[w];
        }
    }
}

int pow2[MAXN * 2];
int ans = 0;
int ct[BITS][2];
inline void process_cc(int root)
{
    cc_sz = cyc_ct = 0;
    par[root] = -1; path[root] = 0; dfs(root);
    // Gaussian Elimination
    int rank = 0;
    for (int i = 0; i < BITS; ++i) {
        int pvt;
        for (pvt = rank; pvt < cyc_ct; ++pvt)
            if (cyc[pvt] & (1LL << i)) break;
        if (pvt == cyc_ct) continue;
        std::swap(cyc[rank], cyc[pvt]);
        for (int j = rank + 1; j < cyc_ct; ++j)
            if (cyc[j] & (1LL << i)) cyc[j] ^= cyc[rank];
        ++rank;
    }
    int64 or_sum = 0;
    for (int i = 0; i < cyc_ct; ++i) or_sum |= cyc[i];
    // Fix an endpoint and count into answer
    std::fill(&ct[0][0], &ct[0][0] + BITS * 2, 0);
    for (int i = 0; i < cc_sz; ++i) {
        for (int bit = 0; bit < BITS; ++bit)
            ++ct[bit][(path[cc[i]] >> bit) & 1];
    }
    for (int bit = 0; bit < BITS; ++bit)
        if (or_sum & (1LL << bit))
            ans = ((int64)ans + (int64)pow2[bit + rank - 1] * (((int64)cc_sz * (cc_sz - 1) / 2)_))_;
        else
            ans = ((int64)ans + (int64)pow2[bit + rank] * ct[bit][0]_ * ct[bit][1])_;
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v; int64 w;
    for (int i = 0; i < n; ++i) head[i] = -1;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%I64d", &u, &v, &w); --u, --v;
        add_edge(u, v, w); add_edge(v, u, w);
    }

    pow2[0] = 1;
    for (int i = 1; i < MAXN * 2; ++i) pow2[i] = (pow2[i - 1] * 2)_;

    for (int i = 0; i < n; ++i) if (!vis[i]) process_cc(i);
    printf("%d\n", ans);
    return 0;
}