#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN);

bool dfs(int u, int p, int st)
{
    if (u == st && p != st)
        return true;
    vis[u] = 1;
    bool cycle = adj[u].size() == 2;
    for (auto &x : adj[u])
        if (!vis[x])
            cycle &= dfs(x, u, st);
    return cycle;
}

int main()
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    while (m--)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for (int x = 1; x <= n; x++)
    {
        if (!vis[x])
            ans += dfs(x, x, x);
    }
    printf("%i\n", ans);
}