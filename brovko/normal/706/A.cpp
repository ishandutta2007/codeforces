#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int a, b, n, x, y, v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n;

    ld ans = 1e18;

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> v;

        ans = min(ans, sqrt((ld)(x - a) * (x - a) + (y - b) * (y - b)) / v);
    }

    cout << setprecision(20) << ans;
}