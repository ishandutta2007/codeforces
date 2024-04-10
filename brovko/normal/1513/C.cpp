#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
const int MOD = 1e9 + 7;

int t, n, m, dp[10][200005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 10; i++)
        dp[i][0] = 1;

    for(int i = 1; i < 200005; i++)
        for(int j = 0; j < 10; j++)
        {
            if(j == 9)
                dp[j][i] = add(dp[0][i - 1], dp[1][i - 1]);
            else dp[j][i] = dp[j + 1][i - 1];
        }

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        int ans = 0;

        while(n)
        {
            ans = add(ans, dp[n % 10][m]);

            n /= 10;
        }

        cout << ans << "\n";
    }
}