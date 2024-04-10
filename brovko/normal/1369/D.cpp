#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

int t, n, dp[2000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[3] = 4;

    for(int i = 4; i < 2000005; i++)
        {
            dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
            if(i % 3 == 0)
                dp[i] = (dp[i] + 4) % MOD;
        }

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
}