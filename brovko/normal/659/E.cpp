#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, used[200005], p[200005], x, ans;
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            p[to] = v;
            dfs(to);
        }
        else if(to != p[v])
            x = 0;
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
        p[i] = -1;

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            x = 1;
            dfs(i);
            ans += x;
        }
    }

    cout << ans;
}