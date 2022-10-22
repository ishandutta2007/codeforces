#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, x, y, dp[10000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;

    for(int i = 1; i < 10000005; i++)
        dp[i] = 1e18;

    for(int i = 0; i < 10000005; i++)
    {
        if(i * 2 < 10000005)
            dp[i * 2] = min(dp[i * 2], dp[i] + y);

        if(i + 1 < 10000005)
            dp[i + 1] = min(dp[i + 1], dp[i] + x);

        if(i * 2 - 1 > i && i * 2 - 1 < 10000005)
            dp[i * 2 - 1] = min(dp[i * 2 - 1], dp[i] + x + y);
    }

    cout << dp[n];
}