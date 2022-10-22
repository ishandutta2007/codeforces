#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int d, k, a, b, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> d >> k >> a >> b >> t;

    if(a * k + t >= b * k)
    {
        int x = min(d, k);

        int ans = x * a;

        ans += b * (d - x);

        cout << ans;
    }
    else
    {
        int ans = 0;

        if(d / k > 0)
        {
            ans = a * (d / k * k) + t * (d / k - 1);

            d -= d / k * k;

            ans += min(b * d, a * d + t);

            cout << ans;
        }
        else cout << a * d;
    }
}