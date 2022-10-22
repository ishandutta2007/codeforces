#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, u[200005], s[200005];

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
            cin >> u[i];

        for(int i = 0; i < n; i++)
            cin >> s[i];

        vector <int> g[n + 5];

        for(int i = 0; i < n; i++)
            g[u[i]].push_back(s[i]);

        int ans[n + 5];

        for(int i = 1; i <= n; i++)
            ans[i] = 0;

        for(int i = 1; i <= n; i++)
        {
            sort(g[i].begin(), g[i].end());
            int m = g[i].size();

            int ps[m + 5];

            ps[0] = 0;

            for(int j = 0; j < m; j++)
                ps[j + 1] = ps[j] + g[i][j];

            for(int j = 1; j <= m; j++)
            {
                ans[j] += ps[m] - ps[m % j];
            }
        }

        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';

        cout << "\n";
    }


}