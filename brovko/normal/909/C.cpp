#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

int n, dp[5005][5005];
char a[5005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        if(i == 0)
            dp[i][1] = 1;
        else
        {
            if(a[i-1] == 'f')
                for(int j=2; j<=n; j++)
                    dp[i][j] = dp[i - 1][j - 1];
            else
                for(int j=n; j>=1; j--)
                    dp[i][j] = add(dp[i][j + 1], dp[i - 1][j]);
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
        ans = add(ans, dp[n-1][i]);
    cout << ans;
}