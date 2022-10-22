#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int Min1 = a[0], Min2 = 1e18;

        int s = a[0], ans = 1e18;

        for(int i = 1; i < n; i++)
        {
            if(i % 2 == 0)
                Min1 = min(Min1, a[i]);
            else Min2 = min(Min2, a[i]);

            s += a[i];

            ans = min(ans, s + (n - (i + 2) / 2) * Min1 + (n - (i + 1) / 2) * Min2);
        }

        cout << ans << "\n";
    }
}