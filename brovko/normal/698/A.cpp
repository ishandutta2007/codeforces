#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, a[105], dp[105][3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            dp[i][j] = 1e9;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(a[i] & j || j == 0)
            {
                if(i == 0)
                    dp[i][j] = (j == 0);
                else
                {
                    if(j == 0)
                        dp[i][j] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;

                    if(j == 1)
                        dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]);

                    if(j == 2)
                        dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]);
                }
            }
        }
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}