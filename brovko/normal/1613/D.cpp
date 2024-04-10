#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int t, n, a[500005], dp[500005], dp2[500005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
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

        for(int i = 0; i <= n; i++)
        {
            dp[i] = 0;
            dp2[i] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            dp2[a[i] + 1] = mul(dp2[a[i] + 1], 2);

            if(a[i] > 0)
                dp2[a[i] - 1] = mul(dp2[a[i] - 1], 2);

            if(a[i] > 1)
                dp2[a[i] - 1] = add(dp2[a[i] - 1], dp[a[i] - 2]);

            if(a[i] == 1)
                dp2[0] = add(dp2[0], 1);

            dp[a[i]] = mul(dp[a[i]], 2);

            if(a[i] > 0)
                dp[a[i]] = add(dp[a[i]], dp[a[i] - 1]);

            if(a[i] == 0)
                dp[a[i]] = add(dp[a[i]], 1);
        }

        int ans = 0;

        for(int i = 0; i < n; i++)
            ans = add(ans, add(dp[i], dp2[i]));

        cout << ans << "\n";
    }
}