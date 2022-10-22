#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[505], b[505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];

        int f = 1;
        if(n % 2 != 0 && a[n / 2] != b[n / 2])
            f = 0;

        vector <pair <int, int> > v, u;

        for(int i=0; i < n / 2; i++)
            {
                v.push_back({min(a[i], a[n - 1 - i]), max(a[i], a[n - 1 - i])});
                u.push_back({min(b[i], b[n - 1 - i]), max(b[i], b[n - 1 - i])});
            }

        sort(v.begin(), v.end());
        sort(u.begin(), u.end());

        for(int i=0; i < n / 2; i++)
        {
            if(v[i] != u[i])
                f = 0;
        }

        if(f)
            cout << "Yes\n";
        else cout << "No\n";
    }
}