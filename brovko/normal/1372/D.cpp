#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], dp[200005][2];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1e18;
        dp[i][1] = 1e18;
    }

    if(n == 1)
    {
        cout << a[0];
        return 0;
    }

    dp[1][0] = a[1];
    dp[2][1] = min(a[1], a[2]);

    for(int i = 1; i < n; i++)
    {
        dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + min(a[i + 2], a[i + 3]));
        dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + a[i + 2]);
        dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + a[i + 2]);
    }

    int ans = dp[n - 1][1];


    for(int i = 0; i < n; i++)
    {
        dp[i][0] = 1e18;
        dp[i][1] = 1e18;
    }

    dp[0][0] = a[0];
    dp[1][1] = min(a[0], a[1]);

    for(int i = 0; i < n; i++)
    {
        dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + min(a[i + 2], a[i + 3]));
        dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + a[i + 2]);
        dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + a[i + 2]);
    }

    ans = min(ans, dp[n - 2][1]);

    ans = -ans;

    for(int i = 0; i < n; i++)
        ans += a[i];

    cout << ans;
}