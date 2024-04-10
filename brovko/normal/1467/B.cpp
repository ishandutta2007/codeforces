#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[300005];

int f(int x)
{
    if(x > 0 && x < n - 1 && (a[x] > a[x - 1] && a[x] > a[x + 1] || a[x] < a[x - 1] && a[x] < a[x + 1]))
        return 1;

    return 0;
}

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

        int x = 0, ans = 1e9;

        for(int i = 0; i < n; i++)
            x += f(i);

        ans = min(ans, x);

        for(int i = 1; i < n; i++)
        {
            int z = a[i], y = x - f(i) - f(i - 1) - f(i + 1);
            a[i] = a[i - 1];

            y += f(i) + f(i - 1) + f(i + 1);
            ans = min(ans, y);

            a[i] = z;
        }

        for(int i = 0; i < n / 2; i++)
            swap(a[i], a[n - 1 - i]);

        for(int i = 1; i < n; i++)
        {
            int z = a[i], y = x - f(i) - f(i - 1) - f(i + 1);
            a[i] = a[i - 1];

            y += f(i) + f(i - 1) + f(i + 1);
            ans = min(ans, y);

            a[i] = z;
        }

        cout << ans << "\n";
    }
}