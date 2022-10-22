#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], used[200005], d[200005], Max[200005], dp[200005], Max2[200005];
vector <int> g[200005], u[200005];

void dfs(int v)
{
    used[v] = 1;

    int m = -1e18;
    dp[v] = a[v];

    for(auto to:g[v])
    {
        if(used[to] == 0)
            {
                d[to] = d[v] + 1;
                dfs(to);

                dp[v] += dp[to];
                m = max(m, Max[to]);
            }
    }

    Max[v] = max(dp[v], m);
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

    for(int i = 0; i < n; i++)
    {
        u[d[i]].push_back(i);
    }

    for(int i = 0; i < n; i++)
    {
        int M = -1e18;

        for(auto to:u[i])
            M = max(M, Max[to]);

        int k = 0;
        int M2 = -1e18;

        for(auto to:u[i])
        {
            if(k == 0 && Max[to] == M)
                k = 1;
            else M2 = max(M2, Max[to]);
        }

        for(auto to:u[i])
        {
            if(Max[to] == M)
                Max2[to] = M2;
            else Max2[to] = M;
        }
    }

    /*for(int i = 0; i < n; i++)
        cout << Max2[i] << ' ';
    cout << "\n";*/

    int ans = -1e18;

    for(int i = 0; i < n; i++)
        ans = max(ans, Max[i] + Max2[i]);

    if(ans < -1e10)
        cout << "Impossible";
    else cout << ans;
}