#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 3e5;

int n, m, u, v, x, y, sub_size[MAXN + 5];
bool vis[MAXN + 5], chk_sub[MAXN + 5];
vector<int> adj[MAXN + 5];

int DFS(int u)
{
    vis[u] = true; sub_size[u] = 1;
    if (u == x)
        chk_sub[u] = true;
    else chk_sub[u] = false;
    for (int v: adj[u])
        if (!vis[v])
        {
            sub_size[u] += DFS(v);
            chk_sub[u] |= chk_sub[v];
        }
    return sub_size[u];
}

int main()
{
    scanf("%d%d%d", &n, &x, &y);
    m = n - 1;
    while (m--)
    {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(y);

    long long fin;
    for (int v: adj[y])
        if (chk_sub[v])
        {
            fin = sub_size[y] - sub_size[v];
            break;
        }

    printf("%I64d", 1LL * n * (n - 1) - fin * sub_size[x]);
    return 0;
}