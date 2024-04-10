#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[1005], used[1005];
vector <int> g[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
        v.pb(make_pair(a[i], i));

    sort(v.rbegin(), v.rend());

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        used[v[i].y] = 1;

        for(auto to:g[v[i].y])
            if(used[to] == 0)
                ans += a[to];
    }

    cout << ans;
}