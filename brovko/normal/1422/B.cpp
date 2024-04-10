#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 goerohgerigegoihr
#define y0 peowjfefwepojfewe

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n + 5][m + 5];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int ans = 0;

        for(int i = 0; i < (n + 1) / 2; i++)
            for(int j = 0; j < (m + 1) / 2; j++)
        {
            vector <int> v;

            v.push_back(a[i][j]);

            if(i < n / 2)
                v.push_back(a[n - 1 - i][j]);

            if(j < m / 2)
                v.push_back(a[i][m - 1 - j]);

            if(i < n / 2 && j < m / 2)
                v.push_back(a[n - 1 - i][m - 1 - j]);

            sort(v.begin(), v.end());

            int x = v[0];

            if(v.size() >= 2)
                x = v[1];

            for(auto to:v)
                ans += abs(to - x);
        }

        cout << ans << "\n";
    }
}