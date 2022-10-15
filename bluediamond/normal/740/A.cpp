#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll n, a1, a2, a3, ans = (ll) 1e18;
    cin >> n >> a1 >> a2 >> a3;

    for (ll i1 = 0; i1 <= 3; i1++)
    {
        for (ll i2 = 0; i2 <= 3; i2++)
        {
            for (ll i3 = 0; i3 <= 3; i3++)
            {
                ll mod = (n + i1 * 1 + i2 * 2 + i3 * 3) % 4;
                if (mod == 0)
                {
                    ans = min(ans, i1 * a1 + i2 * a2 + i3 * a3);
                }
            }
        }
    }
    cout << ans << "\n";
}