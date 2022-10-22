#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t, n, a[300005];

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
            cin >> a[i];

        vector <int> v[n + 1];

        for(int i = 1; i <= n; i++)
            v[i].push_back(0);

        for(int i = 0; i < n; i++)
            v[a[i]].push_back(i + 1);

        for(int i = 1; i <= n; i++)
            v[i].push_back(n + 1);

        int ans[n + 1];

        for(int i = 1; i <= n; i++)
            ans[i] = n + 1;

        for(int i = 1; i <= n; i++)
        {
            int x = 0;

            for(int j = 1; j < v[i].size(); j++)
                x = max(x, v[i][j] - v[i][j - 1]);

            ans[x] = min(ans[x], i);
        }

        for(int i = 2; i <= n; i++)
            ans[i] = min(ans[i], ans[i - 1]);

        for(int i = 1; i <= n; i++)
        {
            if(ans[i] == n + 1)
                cout << -1;
            else cout << ans[i];

            cout << ' ';
        }

        cout << "\n";
    }
}