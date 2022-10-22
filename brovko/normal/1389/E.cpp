#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, m, d, w;

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> m >> d >> w;

        int x = w / gcd(w, d - 1);

        int y = min(d, m);

        cout << x * (y / x) * (y / x - 1) / 2 + (y / x) * (y % x) << "\n";
    }
}