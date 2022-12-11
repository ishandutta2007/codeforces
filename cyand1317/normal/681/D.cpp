#include <cstdio>
#include <vector>
static const int MAXN = 100004;
typedef std::vector<int> edgelist;

int n, m;
edgelist e[MAXN];
int give[MAXN];
bool not_root[MAXN] = { false };
bool given[MAXN] = { false };
bool visited[MAXN] = { false };

bool valid = true;
std::vector<int> ans;
void dfs(int u, int sel)
{
    visited[u] = true;
    if (given[u]) ans.push_back(u);
    if (sel != -1 && give[u] != u && give[u] != sel) {
        valid = false;
        return;
    }
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) {
        dfs(*i, give[u]);
        if (!valid) return;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        e[u - 1].push_back(v - 1);
        not_root[v - 1] = true;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &give[i]);
        --give[i];
        given[give[i]] = true;
    }
    for (int i = 0; i < n; ++i) if (!not_root[i]) {
        dfs(i, -1);
        if (!valid) break;
    }
    if (valid) {
        printf("%lu\n", ans.size());
        for (std::vector<int>::reverse_iterator i = ans.rbegin();
            i != ans.rend(); ++i)
        {
            printf("%d\n", *i + 1);
        }
    } else {
        puts("-1");
    }
    return 0;
}