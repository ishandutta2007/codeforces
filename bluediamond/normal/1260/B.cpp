#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0)
        {
            ll s = (a + b) / 3;
            ll y = a - s;
            ll x = a - 2 * y;
            if (x >= 0 && y >= 0)
            {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
}