#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int t, n, a[2005], b[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        vector <pair <int, int> > u;
        cin >> n;

        for(int i = 0; i < 2 * n; i++)
            cin >> a[i];

        sort(a, a + 2 * n);

        for(int i = 0; i < 2 * n - 1; i++)
        {
            int f = 1;

            vector <pair <int, int> > v;

            for(int j = 0; j < 2 * n; j++)
                b[a[j]] = 0;

            for(int j = 0; j < 2 * n; j++)
                b[a[j]]++;

            b[a[2 * n - 1]]--;
            b[a[i]]--;

            int x = a[2 * n - 1];
            v.push_back({a[i], a[2 * n - 1]});

            for(int j = 2 * n - 1; j >= 0; j--)
                if(b[a[j]])
                {
                    if(b[x - a[j]] >= 2 || b[x - a[j]] >= 1 && x - a[j] != a[j])
                    {
                        b[x - a[j]]--;
                        b[a[j]]--;

                        v.push_back({x - a[j], a[j]});
                        x = a[j];
                    }
                    else f = 0;
                }

            if(f)
                u = v;
        }

        if(u.size())
        {
            cout << "YES\n";
            cout << u[0].first + u[0].second << "\n";

            for(auto to:u)
                cout << to.first << ' ' << to.second << "\n";
        }
        else cout << "NO\n";

        for(int i = 0; i < 2 * n; i++)
            b[a[i]] = 0;

    }
}