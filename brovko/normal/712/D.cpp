#include <bits/stdc++.h>
//#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;
const int MOD = 1e9 + 7;

int a, b, k, t, dp[205][300105], ps[205][300105];

int add(int x, int y)
{
    y += x;

    while(y >= MOD)
        y -= MOD;

    while(y < 0)
        y += MOD;

    return y;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> k >> t;

    int N = 100005;

    dp[0][N] = 1;

    for(int i = N; i <= 3 * N; i++)
        ps[0][i] = 1;

    for(int i = 1; i <= 2 * t; i++)
    {
        for(int j = 1; j <= 3 * N; j++)
        {
            dp[i][j] = sub(ps[i - 1][min(j + k, 3 * N)], ps[i - 1][max(0, j - k - 1)]);
            ps[i][j] = add(ps[i][j - 1], dp[i][j]);
        }
    }

    int ans = 0;

    for(int i = b - a + 1 + N; i <= 3 * N; i++)
        ans = add(ans, dp[2 * t][i]);

    cout << ans;
}