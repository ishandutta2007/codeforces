#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[300005], b[300005], c[300005];

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
            cin >> a[i] >> b[i];

        int d = 1e18;

        for(int i = 0; i < n; i++)
        {
            c[i] = max(0ll, a[i] - b[(i + n - 1) % n]);

            d = min(d, a[i] - c[i]);
        }

        int ans = d;

        for(int i = 0; i < n; i++)
            ans += c[i];

        cout << ans << "\n";
    }
}