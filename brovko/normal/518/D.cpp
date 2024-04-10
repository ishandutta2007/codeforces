#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, t;
ld p, dp[2005][2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> t;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= t; j++)
        {
            dp[i][j] = p * (dp[i - 1][j - 1] + 1) + (1 - p) * dp[i][j - 1];
        }

    cout << setprecision(20) << dp[n][t];
}