#include <cstdio>
#include <vector>
static const int MAXN = 1e5 + 3;
static const int MAXC = 1e5 + 3;

int n;
std::vector<int> e[MAXN];
int c[MAXN];
int c_ct[MAXC] = { 0 };

int sts[MAXN];
int subt_same[MAXN];
int ans = -1;

void dfs(int u, int p = -1)
{
    sts[u] = 1; subt_same[u] = true;
    bool valid = true;
    for (std::vector<int>::iterator i = e[u].begin(); i != e[u].end(); ++i) if (*i != p) {
        dfs(*i, u);
        sts[u] += sts[*i];
        if (!subt_same[*i] || c[*i] != c[u]) subt_same[u] = false;
        if (!subt_same[*i]) valid = false;
    }
    if (p != -1 && valid) {
        int ex_ct = c_ct[c[p]] - (c[p] == c[u]);
        for (std::vector<int>::iterator i = e[u].begin(); i != e[u].end(); ++i)
            if (*i != p && c[*i] == c[p]) ex_ct -= sts[*i];
        if (ex_ct == n - sts[u]) ans = u;
    }
}

int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
        ++c_ct[c[i]];
    }

    dfs(0);
    if (ans == -1) dfs(1);

    if (ans == -1) puts("NO"); else printf("YES\n%d\n", ans + 1);
    return 0;
}