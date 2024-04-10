#include <bits/stdc++.h>
//#define int long long
#define pb push_back

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(n % 2)
        {
            li ans = 0;

            for(int i = 1; i < n; i += 2)
            {
                ans += max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);
            }

            cout << ans << "\n";
        }
        else
        {
            vector <li> pref(n), suf(n);

            vector <li> c(n);

            for(int i = 1; i < n - 1; i++)
                c[i] = max(0, max(a[i - 1], a[i + 1]) + 1 - a[i]);

            pref[1] = c[1];

            for(int i = 2; i < n; i++)
                pref[i] = pref[i - 2] + c[i];

            suf[n - 2] = c[n - 2];

            for(int i = n - 3; i >= 0; i--)
                suf[i] = suf[i + 2] + c[i];

            li ans = 1e18;

            for(int i = 1; i < n; i += 2)
            {
                ans = min(ans, (i >= 2 ? pref[i - 2] : 0) + (i + 1 < n ? suf[i + 1] : 0));
            }

            cout << ans << "\n";
        }
    }
}