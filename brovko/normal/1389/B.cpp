#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, k, z, a[100005], dp[100005][7];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k >> z;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= z; j++)
                if(i + 2 * j <= k)
        {
            if(i == 0)
                dp[i][j] = a[0];

            {
                if(i > 0)
                    dp[i][j] = dp[i - 1][j] + a[i];

                if(i < n - 1 && j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i] + a[i + 1]);
            }

            ans = max(ans, dp[i][j]);
        }

        cout << ans << "\n";
    }
}