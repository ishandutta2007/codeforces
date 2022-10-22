#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, l[20], r[20], dp[20][2];
string s[20];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = n - 1; i >= 0; i--)
        cin >> s[i];

    for(int i = 0; i < n; i++)
    {
        l[i] = m + 1;

        for(int j = 0; j < m + 2; j++)
        {
            if(s[i][j] == '1')
            {
                l[i] = min(l[i], j);
                r[i] = max(r[i], j);
            }
        }
    }

    while(l[n - 1] == m + 1 && r[n - 1] == 0)
        n--;

    dp[0][1] = 1e9;

    for(int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i - 1][1] + m + 2, dp[i - 1][0] + 2 * r[i - 1] + 1);
        dp[i][1] = min(dp[i - 1][0] + m + 2, dp[i - 1][1] + 2 * (m + 1 - l[i - 1]) + 1);
    }

    //cout << dp[1][0] << ' ' << dp[1][1] << "\n";

    cout << min(dp[n - 1][0] + r[n - 1], dp[n - 1][1] + m + 1 - l[n - 1]);
}