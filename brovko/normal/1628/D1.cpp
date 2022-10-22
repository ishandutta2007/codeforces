#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int t, n, m, k, dp[2005][2005];
ld dp2[2005][2005];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i; j++)
            {
                if(i == j)
                {
                    dp[i][j] = i;
                    dp2[i][j] = i;
                }
                else if(j == 0)
                {
                    dp[i][j] = 0;
                    dp2[i][j] = 0;
                }
                else
                {
                    if(dp2[i - 1][j - 1] + 1 < (dp2[i - 1][j - 1] + dp2[i - 1][j] + 1) / 2)
                    {
                        dp2[i][j] = dp2[i - 1][j - 1] + 1;
                        dp[i][j] = add(dp[i - 1][j - 1], 1);
                    }
                    else
                    {
                        dp2[i][j] = (dp2[i - 1][j - 1] + dp2[i - 1][j] + 1) / 2;
                        dp[i][j] = divide(add(dp[i - 1][j - 1], dp[i - 1][j]), 2);
                    }
                }
            }

        cout << mul(dp[n][m], k) << "\n";
    }
}