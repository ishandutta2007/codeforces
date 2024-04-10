#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD = 1e9 + 7;

int t, n, m, a[100005], siz[100005], used[100005];
vector <int> g[100005];

void dfs(int v)
{
    siz[v] = 1;
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            {
                dfs(to);
                siz[v] += siz[to];
            }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            siz[i] = 0;
            g[i].clear();
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

        cin >> m;

        for(int i = 0; i < m; i++)
            cin >> a[i];

        sort(a, a + m);

        vector <int> v;

        for(int i = 1; i < n; i++)
            v.push_back(siz[i] * (n - siz[i]));
            
        while(m < n - 1)
            {
                a[m] = 1;
                m++;
            }

        sort(a, a + m);

        while(m > n - 1)
        {
            a[m - 2] *= a[m - 1];
            m--;
            a[m - 1] %= MOD;
        }

        
        sort(v.begin(), v.end());

        int ans = 0;

        for(int i = 0; i < n - 1; i++)
            ans = (ans + v[i] % MOD * a[i] % MOD) % MOD;

        cout << ans << "\n";
    }
}