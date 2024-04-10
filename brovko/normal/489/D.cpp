#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int n, m, a[3005][3005];
vector <int> g[3005];

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
    }

    for(int i = 0; i < n; i++)
        for(auto j:g[i])
            for(auto k:g[j])
                a[i][k]++;

    li ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(j != i)
                ans += a[i][j] * 1ll * (a[i][j] - 1) / 2;

    cout << ans;
}