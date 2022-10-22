#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[505][505], used[505], c[505];
vector <int> g[505];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
    {
        c[to] = 4 - c[v];
        dfs(to);
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

        a[u][v] = 1;
        a[v][u] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j && a[i][j] == 0)
            {
                g[i].push_back(j);
            }

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            if(g[i].size() > 0)
            {
                c[i] = 1;
                dfs(i);
            }
            else
            {
                c[i] = 2;
                dfs(i);
            }
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        if(i != j)
    {
        if(a[i][j] == 0 && !(c[i] == 1 && c[j] == 3 || c[i] == 3 && c[j] == 1))
        {
            cout << "No";
            return 0;
        }

        if(a[i][j] == 1 && (c[i] == 1 && c[j] == 3 || c[i] == 3 && c[j] == 1))
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n";

    for(int i = 0; i < n; i++)
        cout << char('a' + c[i] - 1);
}