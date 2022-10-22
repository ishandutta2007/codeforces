#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, u[1000005], v[1000005], used[1000005], p[1000005], kp;
vector <int> g[1000005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
            dfs(to);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;

        g[u[i]].push_back(v[i]);

        if(v[i] != u[i])
            g[v[i]].push_back(u[i]);
        else
        {
            p[v[i]]++;
            kp++;
        }
    }

    dfs(v[0]);

    for(int i = 0; i < m; i++)
    {
        if(used[v[i]] == 0)
        {
            cout << 0;
            return 0;
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        if(v[i] == u[i])
            ans += m - 1;
        else
            ans += g[u[i]].size() + g[v[i]].size() - 2 + kp - p[v[i]] - p[u[i]];

        //cout << v[i] << ' ' << u[i] << ' ' << g[v[i]].size() << ' ' << g[u[i]].size() << "\n";
    }

    cout << ans / 2;
}