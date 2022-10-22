#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, p[200005], a[200005], ans, l[200005], r[200005];
vector <int> g[200005];

void dfs(int v)
{
    li s = 0;

    for(auto to:g[v])
    {
        dfs(to);
        s += a[to];
    }

    s = min(s, 1ll * r[v]);

    if(s >= l[v])
        a[v] = s;
    else
    {
        a[v] = r[v];
        ans++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 1; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
        }

        ans = 0;

        for(int i = 0; i < n; i++)
            cin >> l[i] >> r[i];

        for(int i = 0; i < n; i++)
            g[i].clear();

        for(int i = 1; i < n; i++)
            g[p[i]].pb(i);

        dfs(0);
        cout << ans << "\n";
    }
}