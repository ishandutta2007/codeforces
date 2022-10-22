#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, x1, y1, z1, x2, y2, z2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        int ans = min(z1, y2);
        ans -= max(0ll, z2 - (x1 + z1 - ans));

        cout << ans * 2 << "\n";
    }
}