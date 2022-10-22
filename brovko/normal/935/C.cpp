#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

ld R, x1, y1, x2, y2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> x1 >> y1 >> x2 >> y2;
    ld dx = x2 - x1;
    ld dy = y2 - y1;
    ld d = sqrt(dx * dx + dy * dy);

    if(d > R)
    {
        cout << x1 << ' ' << y1 << ' ' << R;
        return 0;
    }

    if(d == 0)
    {
        cout << x1 - R / 2 << ' ' << y1 << ' ' << R / 2;
        return 0;
    }

    ld x = x2 - dx * (R + d) / (2 * d);
    ld y = y2 - dy * (R + d) / (2 * d);
    ld r = (R + d) / 2;

    cout << setprecision(20) << x << ' ' << y << ' ' << r;
}