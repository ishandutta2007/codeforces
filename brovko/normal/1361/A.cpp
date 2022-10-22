#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[500005], u, v, used[500005];
vector <int> g[500005];
vector <pair <int, int> > ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=a[i]; j++)
            used[j] = 0;

        for(auto to:g[i])
            used[a[to]] = 1;

        for(int j=1; j<a[i]; j++)
            if(used[j] == 0)
        {
            cout << -1;
            return 0;
        }

        if(used[a[i]] == 1)
        {
            cout << -1;
            return 0;
        }
    }

    for(int i=0; i<n; i++)
        ans.push_back({a[i], i});

    sort(ans.begin(), ans.end());

    for(auto to:ans)
        cout << to.second + 1 << ' ';
}