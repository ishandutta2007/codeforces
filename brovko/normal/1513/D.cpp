#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, p, a[200005], l[200005], r[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> p;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        l[0] = a[0];

        for(int i = 1; i < n; i++)
        {
            if(a[i] % l[i - 1] == 0)
                l[i] = l[i - 1];
            else l[i] = a[i];
        }

        r[n - 1] = a[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            if(a[i] % r[i + 1] == 0)
                r[i] = r[i + 1];
            else r[i] = a[i];
        }

        int ans = 0;

        for(int i = 1; i < n; i++)
        {
            int x = p;

            if(a[i - 1] % r[i] == 0)
                x = min(x, r[i]);

            if(a[i] % l[i - 1] == 0)
                x = min(x, l[i - 1]);

            ans += x;
        }

        cout << ans << "\n";
    }
}