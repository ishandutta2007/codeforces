#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[200005], dp[200005][2];

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
            for(int j = 0; j < 2; j++)
                dp[i][j] = 1e18;

        dp[0][0] = 0;

        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][1];

            if(i > 1)
                dp[i][0] = min(dp[i][0], dp[i - 2][1]);

            dp[i][1] = dp[i - 1][0] + a[i - 1];

            if(i > 1)
                dp[i][1] = min(dp[i][1], dp[i - 2][0] + a[i - 1] + a[i - 2]);
        }

        cout << min(dp[n][0], dp[n][1]) << "\n";
    }
}