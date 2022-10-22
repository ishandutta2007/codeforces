#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, dp[200005][2], sum[200005][2], used[200005], used2[200005], ans[200005];
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            dfs(to);

            if(dp[to][1] > dp[to][0] || dp[to][1] == dp[to][0] && sum[to][1] < sum[to][0])
            {
                dp[v][0] += dp[to][1];
                sum[v][0] += sum[to][1];
            }
            else
            {
                dp[v][0] += dp[to][0];
                sum[v][0] += sum[to][0];
            }

            dp[v][1] += dp[to][0];
            sum[v][1] += sum[to][0];
        }

    dp[v][1]++;
    sum[v][1] += g[v].size();

    sum[v][0]++;
}

void dfs2(int v, int f)
{
    used2[v] = 1;
    ans[v] = (f == 0 ? 1 : g[v].size());

    for(auto to:g[v])
        if(used2[to] == 0)
        {
            if(f == 0 && (dp[to][1] > dp[to][0] || dp[to][1] == dp[to][0] && sum[to][1] < sum[to][0]))
                dfs2(to, 1);
            else dfs2(to, 0);
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    if(n == 2)
    {
        cout << "2 2\n1 1";
        return 0;
    }

    dfs(0);

    int k = max(dp[0][0], dp[0][1]);
    int s = 1e9;

    if(dp[0][0] == k && sum[0][0] < s)
        s = sum[0][0];

    if(dp[0][1] == k && sum[0][1] < s)
        s = sum[0][1];

//    for(int i = 0; i < n; i++)
//        cout << sum[i][0] << ' ' << sum[i][1] << endl;
//
//    cout << endl;

    cout << k << ' ' << s << "\n";

    if(dp[0][0] == k && sum[0][0] == s)
        dfs2(0, 0);
    else dfs2(0, 1);

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}