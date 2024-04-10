#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, m, c[100005];
vector <int> g[100005];

void dfs(int v)
{
    for(auto to:g[v])
    {
        if(c[to] == c[v])
        {
            cout << -1;
            exit(0);
        }

        if(c[to] == 0)
        {
            c[to] = 3 - c[v];
            dfs(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
    {
        if(c[i] == 0)
        {
            c[i] = 1;
            dfs(i);
        }
    }

    vector <int> x, y;

    for(int i = 0; i < n; i++)
        {
            if(c[i] == 1)
                x.push_back(i + 1);
            else y.push_back(i + 1);
        }

    cout << x.size() << "\n";

    for(auto to:x)
        cout << to << ' ';

    cout << "\n";

    cout << y.size() << "\n";

    for(auto to:y)
        cout << to << ' ';
}