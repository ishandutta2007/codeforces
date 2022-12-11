#include <cstdio>
#include <vector>
static const int MAXN = 100006;
typedef std::vector<int> childlist;

int n;
int par[MAXN];
childlist e[MAXN];
int sts[MAXN];  // Subtree size
double ans[MAXN];

void dfs_count(int u)
{
    sts[u] = 1;
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) {
        dfs_count(*i);
        sts[u] += sts[*i];
    }
}

void dfs_solve(int u)
{
    for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i) {
        ans[*i] = ans[u] + 0.5 * (sts[u] - 1 - sts[*i]) + 1.0;
        dfs_solve(*i);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &par[i]); --par[i];
        e[par[i]].push_back(i);
    }
    dfs_count(0);
    ans[0] = 1.0;
    dfs_solve(0);
    for (int i = 0; i < n; ++i)
        printf("%.2lf%c", ans[i], i == n - 1 ? '\n' : ' ');
    return 0;
}