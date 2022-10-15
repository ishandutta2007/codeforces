#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        vector<ll> a(3);
        cin >> a[0] >> a[1] >> a[2];
        ll ans = (ll) 1e18;
        for (ll x = -1; x <= 1; x++)
        {
            for (ll y = -1; y <= 1; y++)
            {
                for (ll z = -1; z <= 1; z++)
                {
                    ll xx = x + a[0];
                    ll yy = y + a[1];
                    ll zz = z + a[2];
                    ans = min(ans, abs(xx - yy) + abs(xx - zz) + abs(yy - zz));
                }
            }
        }
        cout << ans << "\n";
    }

}