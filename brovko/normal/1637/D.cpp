#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[105], b[105], dp[105][20005];

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

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i <= n; i++)
            for(int j = 0; j < 20005; j++)
                dp[i][j] = 0;

        dp[0][0] = 1;

        for(int i = 0; i < n; i++)
            for(int j = 10000; j >= 0; j--)
            {
                dp[i + 1][j + a[i]] |= dp[i][j];
                dp[i + 1][j + b[i]] |= dp[i][j];
            }

        int s = 0, sk = 0;

        for(int i = 0; i < n; i++)
        {
            s += a[i] + b[i];
            sk += a[i] * a[i] + b[i] * b[i];
        }

        int ans = 1e18;

        for(int i = 0; i <= 10000; i++)
        {
            if(dp[n][i])
                ans = min(ans, i * i + (s - i) * (s - i) + (n - 2) * sk);
        }

        cout << ans << "\n";
    }
}