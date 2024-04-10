#include <cstdio>
//#include <set>
#include <vector>
static const int MAXN = 2e5 + 4;
static const int MAXM = 4e5 + 4;

int n, m, k;
std::vector<int> e[MAXN];
//std::set<int> e_checker[MAXN];

int euler_tour[MAXN * 2], euler_tour_len = 0;
bool vis[MAXN] = { false };
void dfs(int u)
{
    vis[u] = true;
    euler_tour[euler_tour_len++] = u;
    for (std::vector<int>::iterator i = e[u].begin(); i != e[u].end(); ++i) if (!vis[*i]) {
        dfs(*i);
        euler_tour[euler_tour_len++] = u;
    }
}

int route_len[MAXN];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
        //e_checker[u].insert(v);
        //e_checker[v].insert(u);
    }

    dfs(0);

    for (int i = 0; i < k; ++i) route_len[i] = euler_tour_len / k;
    for (int i = 0; i < euler_tour_len % k; ++i) route_len[i]++;
    int accum = 0;
    for (int i = 0; i < k; ++i) {
        printf("%d", route_len[i]);
        for (int j = 0; j < route_len[i]; ++j) printf(" %d", euler_tour[accum + j] + 1);
        accum += route_len[i];
        putchar('\n');
    }

    return 0;
}