#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, dp[300005][4];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        dp[0][0] = 0;
        dp[0][1] = 0;

        for(int i = 1; i <= n; i++)
        {
            if(s[i - 1] == 'L')
                dp[i][0] = 1 + dp[i - 1][1];

            if(s[i - 1] == 'R')
                dp[i][1] = 1 + dp[i - 1][0];
        }

        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == 'L')
                dp[i][2] = 1 + dp[i + 1][3];
            else dp[i][3] = 1 + dp[i + 1][2];
        }

        for(int i = 0; i <= n; i++)
            cout << 1 + dp[i][0] + dp[i][3] << ' ';

        cout << "\n";

        for(int i = 0; i <= n; i++)
            for(int j = 0; j < 4; j++)
                dp[i][j] = 0;
    }
}