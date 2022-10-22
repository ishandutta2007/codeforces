#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int N = 2e5 + 5;

int n, k, dp[N], nxt[N], s[N];
vector <int> g[N];

void dfs(int v, int k)
{
    int m = g[v].size();

    if(m == 0)
    {
        dp[v] = k * s[v];
        nxt[v] = s[v];
        return;
    }

    for(auto to:g[v])
        dfs(to, k / m);

    vector <int> u;

    for(auto to:g[v])
    {
        u.pb(nxt[to]);
    }

    sort(u.rbegin(), u.rend());

    for(int i = 0; i < k % m; i++)
        dp[v] += u[i];

    for(auto to:g[v])
        dp[v] += dp[to];

    dp[v] += k * s[v];
    nxt[v] = s[v] + u[k % m];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            dp[i] = nxt[i] = 0;
        }

        vector <int> p(n);

        for(int i = 1; i < n; i++)
            cin >> p[i], p[i]--;

        for(int i = 1; i < n; i++)
            g[p[i]].pb(i);

        for(int i = 0; i < n; i++)
            cin >> s[i];

        dfs(0, k);

        cout << dp[0] << "\n";
    }
}

/*
1
5 4
1 2 1 3
6 2 1 5 7

*/