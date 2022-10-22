#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005], b[100005], d[100005], used[100005], p[100005];
vector <int> g[100005];

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

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    queue <int> q;

    q.push(0);

    int ans = 0;
    vector <int> u;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        if((a[v] ^ b[v]) != d[v])
        {
            ans++;
            u.pb(v + 1);
            d[v] ^= 1;
        }

        for(auto to:g[v])
        {
            if(used[to] == 0)
            {
                used[to] = 1;
                p[to] = v;

                if(v != 0)
                    d[to] = d[p[v]];

                q.push(to);
            }
        }
    }

    cout << ans << "\n";

    for(auto x:u)
        cout << x << "\n";
}