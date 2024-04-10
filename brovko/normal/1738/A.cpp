#include <bits/stdc++.h>
//#define int long long
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
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <int> b(n);

        for(int i = 0; i < n; i++)
            cin >> b[i];

        li ans = 0;

        for(int i = 0; i < n; i++)
            ans += b[i];

        vector <int> z, o;

        for(int i = 0; i < n; i++)
            if(a[i] == 0)
                z.pb(b[i]);
            else o.pb(b[i]);

        sort(z.rbegin(), z.rend());
        sort(o.rbegin(), o.rend());

        int m = min(z.size(), o.size());

        for(int i = 0; i < m; i++)
            ans += z[i] + o[i];

        if(n == 2 * m)
            ans -= min(z[m - 1], o[m - 1]);

        cout << ans << "\n";
    }
}