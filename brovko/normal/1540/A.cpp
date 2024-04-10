#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[100005], ps[100005];

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

        sort(a, a + n);

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        int ans = a[n - 1];

        for(int i = 0; i < n; i++)
            ans -= a[i] * i - ps[i];

        cout << ans << "\n";
    }
}