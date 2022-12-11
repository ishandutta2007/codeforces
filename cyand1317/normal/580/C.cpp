#include <cstdio>
#include <vector>
static const int MAXN = 100004;
typedef std::vector<int> edgelist;

int n, m, ans = 0;
bool cat[MAXN];
edgelist e[MAXN];

void dfs(int u, int consec_cats, int p = -1)
{
    if (u != 0 && e[u].size() == 1) { ++ans; return; }
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (*i != p) {
        if (cat[*i]) { if (consec_cats + 1 <= m) dfs(*i, consec_cats + 1, u); }
        else dfs(*i, 0, u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &cat[i]);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(0, cat[0]);
    printf("%d\n", ans);
    return 0;
}