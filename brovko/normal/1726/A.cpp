#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;


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

        int mx = -1e9, mn = 1e9;

        for(int i = 0; i < n; i++)
        {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }

        int ans = max(mx - a[0], a[n - 1] - mn);

        for(int i = 0; i < n; i++)
            ans = max(ans, a[i] - a[(i + 1) % n]);

        cout << ans << "\n";
    }
}