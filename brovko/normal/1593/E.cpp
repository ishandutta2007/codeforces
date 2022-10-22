#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, k, d[400005], used[400005];
vector <int> g[400005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            used[i] = 0;
            d[i] = 0;
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
            g[v].pb(u);
        }

        queue <int> q;

        for(int i = 0; i < n; i++)
        {
            if(g[i].size() <= 1)
            {
                q.push(i);
                used[i] = -1e9;
                d[i] = 0;
            }
        }

        while(!q.empty())
        {
            int v = q.front();
//            cout << v << ' ';
            q.pop();

            for(auto to:g[v])
                if(used[to] >= 0)
                {
                    used[to]++;

                    if(g[to].size() - used[to] <= 1)
                    {
                        used[to] = -1e9;
                        d[to] = d[v] + 1;
                        q.push(to);
                    }
                }
        }

//        for(int i = 0; i < n; i++)
//            cout << d[i] << ' ';

//        cout << endl;

        int ans = 0;

        for(int i = 0; i < n; i++)
            if(d[i] >= k)
                ans++;

        cout << ans << "\n";
    }
}