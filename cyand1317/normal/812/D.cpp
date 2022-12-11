#include <cstdio>
#include <vector>
static const int MAXN = 1e5 + 4;

int n, m, k, q;
int par[MAXN];
int taken[MAXN];
std::vector<int> ch[MAXN];

int start[MAXN], end[MAXN];

inline void dfs(int u)
{
    static int epoch = 0;
    start[u] = epoch++;
    for (std::vector<int>::iterator v = ch[u].begin(); v != ch[u].end(); ++v) dfs(*v);
    end[u] = epoch;
    //printf("%d | %d %d\n", u, start[u], end[u]);
}

// Whether u's subtree contains v
inline bool subtree_contains(int u, int v)
{
    return (start[v] >= start[u] && start[v] < end[u]);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < n; ++i) par[i] = -1;
    for (int i = 0; i < m; ++i) taken[i] = -1;

    int u, v;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        if (taken[v] != -1) { par[u] = taken[v]; ch[taken[v]].push_back(u); }
        taken[v] = u;
    }
    //for (int i = 0; i < n; ++i) printf("%d | %d\n", i + 1, par[i] + 1);

    for (int i = 0; i < n; ++i) if (par[i] == -1) dfs(i);

    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        if (taken[v] == -1) puts("0");
        else {
            if (subtree_contains(u, taken[v])) printf("%d\n", end[u] - start[u]);
            else puts("0");
        }
    }

    return 0;
}