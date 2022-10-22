#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, W, H, x[2], y[2], w, h;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> W >> H >> x[0] >> y[0] >> x[1] >> y[1] >> w >> h;

        int ans = 1e18;

        if(w + x[1] - x[0] <= W)
            ans = min({ans, w - x[0], x[1] - W + w});

        if(h + y[1] - y[0] <= H)
            ans = min({ans, h - y[0], y[1] - H + h});

        if(ans == 1e18)
            cout << "-1\n";
        else cout << max(0ll, ans) << "\n";
    }
}