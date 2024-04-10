#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<vector<int>> adj(MAXN);
vector<int> dist(MAXN, -1);
vector<bool> diam(MAXN);
vector<int> par(MAXN);

void dfs(int u, int p, int d, int &mD, int &mN)
{
    if (d > mD)
        mD = d, mN = u;
    par[u] = p;
    for (auto &x : adj[u])
        if (x != p)
            dfs(x, u, d+1, mD, mN);
}

void dfs2(int u, int p)
{
    dist[u] = dist[p]+1;
    for (auto &x : adj[u])
        if (x != p && !diam[x])
            dfs2(x, u);
}

int main()
{
    int n, a, b;
    scanf("%i", &n);
    for (int x = 1; x < n; x++)
    {
        scanf("%i%i", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mD = 0, mN1 = 0, mN2 = 0;
    dfs(1, 1, 0, mD, mN1);
    dfs(mN1, mN1, 0, mD=0, mN2);
    for (int x = mN2; x != mN1; x = par[x])
        diam[x] = 1;
    diam[mN1] = 1;
    for (int x = mN2; x != mN1; x = par[x])
        dfs2(x, x);
    dfs2(mN1, mN1);
    int mai = 1;
    for (int x = 1; x <= n; x++)
        if (dist[x] > dist[mai])
            mai = x;
    while (mai == mN1 || mai == mN2)
    {
        mai++;
        mai %= n;
        if (mai == 0)
            mai = n;
    }
    printf("%i\n", dist[mai] + mD);
    printf("%i %i %i\n", mN1, mN2, mai);
}