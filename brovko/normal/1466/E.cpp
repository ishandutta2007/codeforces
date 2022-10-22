#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;
const int MOD = 1e9 + 7;

int t, n, a[500005], b[65];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return (x % MOD) * (y % MOD) % MOD;
}

int And(int x)
{
    int ans = 0, y = 0;

    while(x > 0)
    {
        ans = add(ans, mul(1ll << y, b[y] * (x % 2)));

        x /= 2;
        y++;
    }

    return ans;
}

int Or(int x)
{
    for(int i = 0; i < 65; i++)
        b[i] = n - b[i];

    int y = And(((1ll << 60) - 1) ^ x);

    for(int i = 0; i < 65; i++)
        b[i] = n - b[i];

    return add(mul((1ll << 60) - 1, n), MOD - y);
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

        for(int i = 0; i < 65; i++)
            b[i] = 0;

        for(int i = 0; i < n; i++)
        {
            int x = a[i];
            int y = 0;

            while(x > 0)
            {
                b[y] += x % 2;
                y++;
                x /= 2;
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
            ans = add(ans, mul(And(a[i]), Or(a[i])));

        cout << ans << "\n";
    }
}