#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[100005], m, b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i <= m; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
            b[a[i] % m]++;

        int ans = 0;

        if(b[0] > 0)
            ans = 1;

        for(int i = 1; i <= m / 2; i++)
            if(b[i] > 0 || b[m - i] > 0)
                ans += 1 + max(0ll, max(b[i], b[m - i]) - min(b[i], b[m - i]) - 1);

        cout << ans << "\n";
    }
}