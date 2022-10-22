#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, m;
vector <int> g[200005], gr[200005];

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
        gr[v].pb(u);
    }

    vector <int> sz(n);

    for(int i = 0; i < n; i++)
        sz[i] = g[i].size();

    vector <int> dp(n);

    dp[n - 1] = 0;

    for(int i = 0; i < n - 1; i++)
        dp[i] = 1e9;

    set <pair <int, int> > st;

    for(int i = 0; i < n; i++)
        st.insert({dp[i], i});

    vector <int> used(n);

    while(!st.empty())
    {
        pair <int, int> p = (*st.begin());
        st.erase(p);

        int v = p.y;
        used[v] = 1;

        for(auto to:gr[v])
            if(used[to] == 0)
            {
                sz[to]--;

                st.erase({dp[to], to});
                dp[to] = min(dp[to], dp[v] + sz[to] + 1);
                st.insert({dp[to], to});
            }
    }

    cout << dp[0];
}