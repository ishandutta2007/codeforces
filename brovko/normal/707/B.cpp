#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, m, k, a[100005], used[100005];
vector <pair <int, int> > g[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i]--;
        used[a[i]]++;
    }

    int ans = 1e18;

    for(int i = 0; i < k; i++)
    {
        for(auto to:g[a[i]])
        {
            if(used[to.first] == 0)
                ans = min(ans, to.second);
        }
    }

    if(ans == 1e18)
        cout << -1;
    else cout << ans;
}