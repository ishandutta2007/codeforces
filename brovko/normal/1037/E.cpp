#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long
#define pii pair <int, int>

using namespace std;

int n, m, k, used[200005], ans, u[200005], v[200005];
set <int> g[200005];

void dfs(int v)
{
//    cout << "+" << v << endl;

    used[v] = 0;
    ans--;

    for(auto to:g[v])
        g[to].erase(v);

    for(auto to:g[v])
        if(used[to] && g[to].size() < k)
            dfs(to);

//    cout << "-" << v << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i];

        u[i]--;
        v[i]--;

        g[u[i]].insert(v[i]);
        g[v[i]].insert(u[i]);
    }

    for(int i = 0; i < n; i++)
        used[i] = 1;

    ans = n;

    for(int i = 0; i < n; i++)
        if(used[i] && g[i].size() < k)
            dfs(i);

    vector <int> ans2;

    for(int i = m - 1; i >= 0; i--)
    {
//        cout << i << endl;

        ans2.pb(ans);

        g[u[i]].erase(v[i]);
        g[v[i]].erase(u[i]);

        if(used[u[i]] && g[u[i]].size() < k)
            dfs(u[i]);

        if(used[v[i]] && g[v[i]].size() < k)
            dfs(v[i]);
    }

    reverse(ans2.begin(), ans2.end());

    for(auto x:ans2)
        cout << x << "\n";
}