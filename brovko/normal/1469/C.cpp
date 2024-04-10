#include <bits/stdc++.h>
#define ld long double
#define int long long

using namespace std;

int t, n, k, a[200005], b[200005];

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
            cin >> a[i];
            b[i] = a[i];
        }

        vector <pair <int, int> > v;

        for(int i = 1; i < n; i++)
        {
            if(a[i] - a[i - 1] >= k)
                v.push_back({i - 1, i});

            if(a[i - 1] - a[i] >= k)
                v.push_back({i, i - 1});
        }

            for(int i = 0; i < v.size(); i++)
                if(a[v[i].second] - a[v[i].first] >= k)
            {
                int x = v[i].first, y = v[i].second;
                a[x] = a[y] - k + 1;

                if(x > 0 && a[x] - a[x - 1] >= k)
                    v.push_back({x - 1, x});

                if(x < n - 1 && a[x] - a[x + 1] >= k)
                    v.push_back({x + 1, x});
            }

            int f = 1;

            for(int i = 0; i < n; i++)
                if(a[i] - b[i] >= k)
                    f = 0;
                    
            if(a[0] > b[0] || a[n - 1] > b[n - 1])
                f = 0;

            if(f)
                cout << "YES\n";
            else cout << "NO\n";
    }
}