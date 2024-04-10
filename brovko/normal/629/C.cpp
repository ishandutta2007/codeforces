#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD = 1e9 + 7;

int add(int x, int y)
{
    return (x + y) % MOD;
}

int n, m, dp[2005][4005][2];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;

    int Min = 0, last = 0;

    for(int i = 0; i < m; i++)
    {
        if(s[i] == '(')
            last++;
        else last--;

        Min = min(Min, last);
    }

    if(abs(last) > n - m)
    {
        cout << 0;
        return 0;
    }

    dp[0][0][0] = 1;

    if(Min >= 0)
        dp[0][last][1] = 1;

    for(int i = 1; i <= n - m; i++)
        {
            for(int j = 0; j < 4004; j++)
            {
                dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j + 1][0]);

                if(j > 0)
                    dp[i][j][0] = add(dp[i][j][0], dp[i - 1][j - 1][0]);
            }

            for(int j = 0; j < 4004; j++)
            {
                if(j - last >= 0 && j - last < 4004 && j - last + Min >= 0)
                {
                    dp[i][j][1] = add(dp[i][j][1], dp[i][j - last][0]);
                }

                dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j + 1][1]);

                if(j > 0)
                    dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j - 1][1]);
            }
        }

    cout << dp[n - m][0][1];
}