#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], used[200005], d[200005];
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            if(a[v] == a[to])
                d[to] = d[v];
            else d[to] = d[v] + 1;

            dfs(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    int Max = 0;

    for(int i = 0; i < n; i++)
        if(d[i] > d[Max])
            Max = i;

    for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            d[i] = 0;
        }

    dfs(Max);

    Max = 0;

    for(int i = 0; i < n; i++)
        Max = max(Max, d[i]);

    cout << (Max + 1) / 2;
}