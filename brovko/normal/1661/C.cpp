#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, h[300005];

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
            cin >> h[i];

        int Max = 0;

        for(int i = 0; i < n; i++)
            Max = max(Max, h[i]);

        int ans = 1e18;

        for(int H = Max; H < Max + 2; H++)
        {
            int x = 0, y = 0;

            for(int i = 0; i < n; i++)
            {
                x += (H - h[i]) % 2;
                y += (H - h[i]) / 2;
            }

            int d = max(0ll, (y - x + 1) / 3);

            y -= d;
            x += 2 * d;

            ans = min(ans, max(2 * x - 1, 2 * y));
        }

        cout << ans << "\n";
    }
}