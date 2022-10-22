#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, c, a[200005], b[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> c;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n - 1; i++)
            cin >> b[i];

        int x = 0, y = 0, ans = 1e18;

        for(int i = 0; i < n; i++)
        {
            ans = min(ans, x + max(0ll, (c - y + a[i] - 1) / a[i]));

            int dx = max(0ll, (b[i] - y + a[i] - 1) / a[i]);

            x += dx + 1;
            y += dx * a[i] - b[i];
        }

        cout << ans << "\n";
    }
}