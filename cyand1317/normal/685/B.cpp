#include <cstdio>
#include <vector>
static const int MAXN = 300007;
typedef std::vector<int> childlist;

int n, q, v_i;
int par[MAXN];
childlist e[MAXN];

int sts[MAXN], hvc[MAXN], hvcsz[MAXN];
int centroid[MAXN];

void dfs_count(int u)
{
    sts[u] = 1;
    hvc[u] = -1;
    hvcsz[u] = 0;
    for (childlist::iterator v = e[u].begin(); v != e[u].end(); ++v) {
        dfs_count(*v);
        sts[u] += sts[*v];
        if (hvcsz[u] < sts[*v]) {
            hvcsz[u] = sts[*v]; hvc[u] = *v;
        }
    }
}

inline bool is_subtree_centroid(int u, int c)
{
    return (sts[u] - sts[c] <= sts[u] / 2) && (hvcsz[c] <= sts[u] / 2);
}
void dfs_find(int u)
{
    if (e[u].size() == 0) { centroid[u] = u; return; }
    for (childlist::iterator v = e[u].begin(); v != e[u].end(); ++v) {
        dfs_find(*v);
    }
    int c = centroid[hvc[u]];
    while (c != u && !is_subtree_centroid(u, c)) c = par[c];
    centroid[u] = c;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &par[i]); --par[i];
        e[par[i]].push_back(i);
    }
    dfs_count(0);
    dfs_find(0);

    do {
        scanf("%d", &v_i);
        printf("%d\n", centroid[v_i - 1] + 1);
    } while (--q);
    return 0;
}