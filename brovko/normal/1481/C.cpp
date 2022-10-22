#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m, a[100005], b[100005], c[100005], y[100005], ans[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < m; i++)
            cin >> c[i];

        vector <int> v[n + 5], u[n + 5];

        for(int i = 0; i < n; i++)
        {
            if(a[i] == b[i])
                u[a[i]].push_back(i);
            else v[b[i]].push_back(i);
        }

        for(int i = 0; i <= n; i++)
            y[i] = 0;

        for(int i = 0; i <= m; i++)
            ans[i] = 0;

        int f = 1;

        if(v[c[m - 1]].size() > 0)
        {
            ans[m - 1] = v[c[m - 1]][0];
            y[c[m - 1]]++;
        }
        else if(u[c[m - 1]].size() > 0)
            ans[m - 1] = u[c[m - 1]][0];
        else f = 0;

        for(int i = m - 2; i >= 0; i--)
        {
            if(v[c[i]].size() > y[c[i]])
            {
                ans[i] = v[c[i]][y[c[i]]];
                y[c[i]]++;
            }
            else ans[i] = ans[m - 1];
        }

        for(int i = 0; i <= n; i++)
            if(v[i].size() > y[i])
                f = 0;

        if(f == 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            for(int i = 0; i < m; i++)
                cout << ans[i] + 1 << ' ';

            cout << "\n";
        }
    }
}