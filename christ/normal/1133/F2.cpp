#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005, MAXM = 200005;

vector<int> ds(MAXN);
vector<vector<int>> adj(MAXN);
vector<pair<int, int>> el;
vector<bool> vis(MAXN);

int find(int u)
{
    return ds[u] == u ? u : ds[u] = find(ds[u]);
}

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (auto &x : adj[u])
        if (x != 1)
            dfs(x);
}

int main()
{
    int n, m, D;
    scanf("%i%i%i", &n, &m, &D);
    for (int x = 0; x < m; x++)
    {
        int a, b;
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        el.push_back({a, b});
    }
    for (int x = 1; x <= n; x++)
        ds[x] = x;
    int c = 0;
    for (auto &x : adj[1])
    {
        if (!vis[x])
        {
            dfs(x);
            ds[x] = 1;
            c++;
        }
    }
    if(c > D || D > adj[1].size())
    {
        printf("NO\n");
        return 0;
    }
    c = D - c;
    if (c)
    {
        for (auto &x : adj[1])
        {
            if (ds[x] != 1)
            {
                ds[x] = 1;
                if (!--c)
                    break;
            }
        }
    }
    printf("YES\n");
    for (int x = 2; x <= n; x++)
        if (ds[x] == 1)
            printf("%i %i\n", 1, x);
    for (int x = 0; x < m; x++)
    {
        int a = el[x].first, b = el[x].second;
        if (a != 1 && b != 1)
        {
            int ra = find(a), rb = find(b);
            if (ra != rb)
            {
                printf("%i %i\n", a, b);
                ds[ra] = rb;
            }
        }
    }
}