#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> par(MAXN);

int find(int n)
{
    if (n == par[n])
        return n;
    return par[n] = find(par[n]);
}

bool merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a == b)
        return false;
    par[a] = b;
    return true;
}

vector<vector<int>> adj(MAXN);

int main()
{
    iota(par.begin(), par.end(), 0);
    int n, m;
    scanf("%i%i", &n, &m);
    vector<pair<int, int>> ed(m);
    for (auto &x : ed)
    {
        scanf("%i%i", &x.first, &x.second);
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    int mai = 0;
    for (int x = 0; x <= n; x++)
        if (adj[x].size() > adj[mai].size())
            mai = x;
    vector<pair<int,int>> ans;
    for (auto &x : adj[mai])
        if (merge(x, mai))
            ans.push_back({mai, x});
    for (auto &x : ed)
        if (merge(x.first, x.second))
            ans.push_back(x);
    for (auto &x : ans)
        printf("%i %i\n", x.first, x.second);
}