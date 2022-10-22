#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, l, r, k, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> l >> r >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;

        sort(a, a + n);

        for(int i = 0; i < n; i++)
        {
            if(a[i] >= l && a[i] <= r && a[i] <= k)
            {
                ans++;
                k -= a[i];
            }
        }

        cout << ans << "\n";
    }
}