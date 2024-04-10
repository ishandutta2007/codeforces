#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n, dp[200005], used[200005], ans, p[200005], f;
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;

//    if(g[v].size() == 1 && v != 0)
//        ans++;

    int x = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            p[to] = v;
            dfs(to);

            if(dp[to] == 1)
                x = 2;
        }

    dp[v] = x;
    used[v] = 0;

    if(v > 0 && p[v] == 0 && dp[v] == 1)
        f = 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        f = 0;

        cin >> n;

        for(int i = 0; i < n; i++)
            g[i].clear();

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(0);

//        for(int i = 0; i < n; i++)
//            cout << dp[i] << ' ';
//
//        cout << endl;

//        if(dp[0] == 1)
//        {
//            ans++;
//            dp[0] = 2;
//        }
//
//        for(int i = 0; i < n; i++)
//            for(auto to:g[i])
//                if(to < i && dp[to] == 2 && dp[i] == 2)
//                    ans--;

        ans = 0;

        for(int i = 1; i < n; i++)
            if(dp[i] == 2)
                ans--;
            else ans++;

        ans += 1 - f;

        cout << ans << "\n";
    }
}