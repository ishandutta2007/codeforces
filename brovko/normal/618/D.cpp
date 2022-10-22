#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, x, y, used[200005], dp[200005][2];
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;
    int k = 0;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs(to);
            dp[v][0] += dp[to][0];
            dp[v][1] += dp[to][0];

            if(dp[to][0] == dp[to][1])
            {
                if(k == 0)
                {
                    dp[v][0]++;
                    dp[v][1]++;
                }

                if(k == 1)
                    dp[v][0]++;

                k++;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);

        if(x >= y && (g[u].size() == n - 1 || g[v].size() == n - 1))
        {
            cout << x + y * (n - 2);
            return 0;
        }
    }

    if(x >= y)
    {
        cout << y * (n - 1);
        return 0;
    }

    dfs(0);

//    for(int i = 0; i < n; i++)
//        cout << dp[i][0] << ' ' << dp[i][1] << endl;

    cout << dp[0][0] * x + (n - 1 - dp[0][0]) * y;
}