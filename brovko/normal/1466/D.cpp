#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, w[100005];

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
            cin >> w[i];

        vector <int> g[n];

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.push_back({w[i], (int)g[i].size() - 1});

        sort(v.rbegin(), v.rend());

        int s = 0;
        for(int i = 0; i < n; i++)
            s += w[i];

        cout << s << ' ';

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < v[i].second; j++)
            {
                s += v[i].first;
                cout << s << ' ';
            }
        }

        cout << "\n";
    }
}