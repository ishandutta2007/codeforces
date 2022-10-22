#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, dp[100005];
vector <int> g[100005];

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

        g[u].pb(v);
        g[v].pb(u);
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;

        for(auto to:g[i])
            if(to < i)
                dp[i] = max(dp[i], dp[to] + 1);

        ans = max(ans, g[i].size() * dp[i]);
    }

    cout << ans;
}