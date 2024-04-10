#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
static const int MAXN = 100006;
typedef std::pair<int, int> edge;
typedef std::vector<edge> edgelist;

int n;
int a[MAXN];
edgelist e[MAXN];

int happy_ct = 0;
void dfs(int u, long long len = 0)
{
    if (len > a[u]) return;
    ++happy_ct;
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) {
        dfs(i->first, std::max(0LL, len + i->second));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int p, c;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &p, &c);
        e[p - 1].push_back(edge(i, c));
    }
    dfs(0);
    printf("%d\n", n - happy_ct);
    return 0;
}