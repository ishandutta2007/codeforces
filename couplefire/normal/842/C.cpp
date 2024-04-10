#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
 
int n;
vector<int>ans;
vector<bool>vis;
vector<int>mas;
vector<int>del;
vector<int>koll;
vector<vector<int>>edges;
 
int nod(int a, int b)
{
    if (b == 0)
        return a;
    return nod(b, a % b);
}
 
void dfs1(int v)
{
    vis[v] = 1;
    for (auto u : edges[v])
        if (! vis[u])
        {
            ans[u] = nod(ans[v], mas[u]);
            dfs1(u);
        }
}
 
void dfs2(int v, int dist)
{
    vis[v] = 1;
    for (int i = 0; i < del.size(); i++)
    {
        koll[i] += (mas[v] % del[i] == 0);
        if (koll[i] >= dist)
            ans[v] = max(ans[v], del[i]);
    }
    for (auto u : edges[v])
        if (! vis[u])
            dfs2(u, dist + 1);
    for (int i = 0; i < del.size(); i++)
        koll[i] -= (mas[v] % del[i] == 0);
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    ans.resize(n);
    vis.resize(n);
    mas.resize(n);
    edges.resize(n);
    for (int i = 0; i < n; i++)
        cin>>mas[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int p = mas[0];
    mas[0] = 0;
    ans[0] = 0;
    dfs1(0);
    mas[0] = p;
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    for (int i = 1; i*i <= mas[0]; i++)
    {
        if (mas[0] % i == 0)
        {
            del.push_back(i);
            del.push_back(mas[0] / i);
            if (i*i == mas[0])
                del.pop_back();
        }
    }
    sort(del.begin(), del.end());
    koll.resize(del.size());
    dfs2(0, 0);
    for (int i = 0; i < n; i++)
        cout<<ans[i]<<' ';
    return 0;
}