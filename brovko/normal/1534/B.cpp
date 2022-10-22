#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[400005];

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

        int ans = a[0] + a[n - 1];

        for(int i = 1; i < n; i++)
            ans += abs(a[i] - a[i - 1]);

        for(int i = 1; i < n - 1; i++)
            ans -= max(0ll, a[i] - max(a[i - 1], a[i + 1]));

        if(n > 1)
        {
            ans -= max(0ll, a[0] - a[1]);
            ans -= max(0ll, a[n - 1] - a[n - 2]);
        }

        if(n > 1)
            cout << ans << "\n";
        else cout << a[0] << "\n";
    }
}