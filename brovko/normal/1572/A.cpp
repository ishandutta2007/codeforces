#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, used[200005], dp[200005], ans;
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;
    dp[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 1)
            ans = 1e18;
        else
        if(used[to] == 0)
        {
            dfs(to);
            dp[v] = max(dp[v], dp[to] + (int)(v < to));
        }
        else dp[v] = max(dp[v], dp[to] + (int)(v < to));
    }

    used[v] = 2;
    ans = max(ans, dp[v]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            int k;
            cin >> k;

            while(k--)
            {
                int x;
                cin >> x;
                x--;

                g[i].pb(x);
            }
        }

        ans = 0;

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                dfs(i);

        if(ans < 1e18)
            cout << ans << "\n";
        else cout << "-1\n";

        for(int i = 0; i < n; i++)
        {
            dp[i] = 0;
            used[i] = 0;
            g[i].clear();
        }
    }
}