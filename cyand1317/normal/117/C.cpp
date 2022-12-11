#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
static const int MAXN = 5004;

int n;
bool g[MAXN][MAXN];
int in_deg[MAXN] = { 0 };
int vis[MAXN] = { 0 };
int ans[3] = { -1, -1, -1 };
int route[MAXN], route_ptr = 0;

void dfs(int u)
{
    vis[u] = 1;
    route[route_ptr++] = u;
    for (int v = 0; v < n; ++v) if (g[u][v]) {
        if (vis[v] == 0) {
            dfs(v);
            if (ans[0] != -1) break;
        } else if (vis[v] == 1) {
            // Found!
            std::vector<int> cycle;
            for (int i = route_ptr - 1; route[i] != v; --i) cycle.push_back(route[i]);
            cycle.push_back(v);
            std::reverse(cycle.begin(), cycle.end());
            for (int i = 2; i <= (int)cycle.size() - 2; ++i) {
                if (g[cycle[i]][cycle[0]]) { ans[0] = cycle[0]; ans[1] = cycle[i - 1]; ans[2] = cycle[i]; break; }
            }
            if (ans[0] == -1) { ans[0] = cycle[0]; ans[1] = cycle[(int)cycle.size() - 2]; ans[2] = cycle.back(); }
            break;
        }
    }
    vis[u] = 2;
    --route_ptr;
}

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            if ((g[i][j] = (getchar() == '1')) == true) ++in_deg[j];

    std::queue<int> zero_ins;
    int count = 0;
    for (int i = 0; i < n; ++i) if (in_deg[i] == 0) zero_ins.push(i);
    while (!zero_ins.empty()) {
        int u = zero_ins.front(); zero_ins.pop(); ++count;
        for (int v = 0; v < n; ++v) if (g[u][v] && --in_deg[v] == 0) zero_ins.push(v);
    }
    if (count == n) { puts("-1"); return 0; }

    for (int i = 0; i < n; ++i) if (vis[i] == 0) dfs(i);
    printf("%d %d %d\n", ans[0] + 1, ans[1] + 1, ans[2] + 1);

    return 0;
}