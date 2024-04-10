#include<bits/stdc++.h>

using namespace std;

const int N = 6043;
vector<int> g[N];
int a[N];
int u[2 * N];
int v[2 * N];
int d[2 * N];

int calc(int i);

int dfs(int x, int y, int c)
{
    int ans = -1;
    for(auto e : g[x])
    {
        int to = v[e];
        if(to == y)
            continue;
        ans = max(ans, dfs(to, x, c));
        if(a[x] < c)
            ans = max(ans, calc(e ^ 1));
    }
    if(a[x] < c)
        ans = max(ans, 1);
    return ans;
}

int calc(int i)
{
    if(d[i] != -1)
        return d[i];
    d[i] = 1;
    if(a[u[i]] < a[v[i]])
        d[i] = 2;
    d[i] = max(d[i], dfs(u[i], v[i], a[v[i]]) + 1);
    return d[i];    
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];   
    }
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(i * 2);
        g[y].push_back(i * 2 + 1);
        u[i * 2] = x;
        v[i * 2] = y;
        u[i * 2 + 1] = y;
        v[i * 2 + 1] = x;
    }
    for(int i = 0; i < 2 * n - 2; i++)
        d[i] = -1;
    int ans = 0;
    for(int i = 0; i < 2 * n - 2; i++)
    {
        //cout << calc(i) << " ";
        ans = max(ans, calc(i));
    }
    //cout << endl;
    cout << ans;
}