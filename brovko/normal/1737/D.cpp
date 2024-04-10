#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector <pair <int, int> > g[n];

        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            u--;
            v--;

            g[u].pb({v, w});
            g[v].pb({u, w});
        }

        vector <int> used(n), d(n), p(n);
        queue <int> q;

        used[0] = 1;
        d[0] = 0;
        q.push(0);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for(auto to:g[v])
            {
                if(used[to.f] == 0)
                {
                    used[to.f] = 1;
                    d[to.f] = d[v] + 1;
                    p[to.f] = v;
                    q.push(to.f);
                }
            }
        }

        vector <int> D1 = d;

        for(int i = 0; i < n; i++)
            used[i] = d[i] = 0;

        used[n - 1] = 1;
        d[n - 1] = 0;
        q.push(n - 1);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for(auto to:g[v])
            {
                if(used[to.f] == 0)
                {
                    used[to.f] = 1;
                    d[to.f] = d[v] + 1;
                    q.push(to.f);
                }
            }
        }

        vector <int> Dn = d;

        int up[n][20];

        for(int i = 0; i < n; i++)
            up[i][0] = p[i];

        for(int j = 1; j < 20; j++)
            for(int i = 0; i < n; i++)
                up[i][j] = up[up[i][j - 1]][j - 1];

        int ans = 1e18;

        for(int i = 0; i < n; i++)
            for(auto to:g[i])
            {
                int cur = (D1[i] < D1[to.f] ? i : to.f), k = 0;

                for(int j = 19; j >= 0; j--)
                    if(Dn[cur] - Dn[up[cur][j]] == (1 << j))
                        cur = up[cur][j], k += (1 << j);

                ans = min(ans, to.s * (D1[i] + 1 + Dn[to.f] - k));
//                cout << "! " << to.s << ' ' << to.s * (D1[i] + 1 + Dn[to.f]) << "\n";
            }

        cout << ans << "\n";
    }
}