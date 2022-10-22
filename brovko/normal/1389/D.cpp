#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, k, l1, r1, l2, r2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;

        if(min(r1, r2) >= max(l1, l2))
        {
            int x = max(r1, r2) - min(l1, l2);

            int k1 = n * (2 * x - r1 + l1 - r2 + l2);

            k -= n * (min(r1, r2) - max(l1, l2));

            if(k < k1)
                cout << max(0ll, k);
            else cout << 2 * k - k1;
        }
        else
        {
            int d = max(l1, l2) - min(r1, r2);
            int x = max(r1, r2) - min(l1, l2);

            int k1 = min(n, k / x);

            k -= k1 * x;

            int ans = k1 * (x + d);

            if(k < d && k1 > 0 || k1 == n)
                ans += 2 * k;
            else ans += k + d;

            cout << ans;
        }

        cout << "\n";
    }
}