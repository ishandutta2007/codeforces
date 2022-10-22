#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[100005], used[100005], u, v;
set <int> q;
vector <int> g[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    q.insert(1);

    for(int i=0; i<n; i++)
    {
        int x=*(q.begin());
        q.erase(x);
        used[x]++;
        cout << x << ' ';

        for(auto to:g[x])
            if(used[to]==0)
                q.insert(to);
    }
}