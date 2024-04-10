#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, dp[3005][2], a[3005], b[3005], c[3005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        cin >> c[i];

    dp[0][0] = a[0];
    dp[0][1] = b[0];

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + b[i]);
    }

    cout << dp[n - 1][0];
}