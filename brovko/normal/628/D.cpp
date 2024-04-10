#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD = 1e9 + 7;

int m, d, dp[2005][2005][2][2], pow10[2005];
string a, b;

int add(int x, int y, int mod)
{
    return ((x + y) % mod + mod) % mod;
}

int sub(int x, int y, int mod)
{
    return add(x, mod - y, mod);
}

int mul(int x, int y, int mod)
{
    return x * 1ll * y % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> d >> a >> b;
    int n = a.size();

    pow10[0] = 1;

    for(int i = 1; i <= n; i++)
        pow10[i] = mul(pow10[i - 1], 10, m);

    int val = 0;

    /*for(int i = 1; i < n; i += 2)
        val = add(val, mul(pow10[n - 1 - i], d, m), m);*/

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {

        for(int c = 0; c <= 9; c++)
            if(c != d && i % 2 == 0 || c == d && i % 2 != 0)
        {
            int x = mul(c, pow10[n - 1 - i], m);

            if(i == 0)
            {
                if(sub(j, x, m) == val)
                {
                    //cout << c << endl;

                    if(c == a[i] - '0' && c == b[i] - '0')
                        dp[i][j][1][1] = add(dp[i][j][1][1], 1, MOD);

                    else if(c > a[i] - '0' && c == b[i] - '0')
                        dp[i][j][0][1] = add(dp[i][j][0][1], 1, MOD);

                    else if(c == a[i] - '0' && c < b[i] - '0')
                        dp[i][j][1][0] = add(dp[i][j][1][0], 1, MOD);

                    else if(c > a[i] - '0' && c < b[i] - '0')
                        dp[i][j][0][0] = add(dp[i][j][0][0], 1, MOD);
                }
            }
            else
            {
                int p = sub(j, x, m);

                dp[i][j][0][0] = add(dp[i][j][0][0], dp[i - 1][p][0][0], MOD);

                if(c > a[i] - '0')
                    dp[i][j][0][0] = add(dp[i][j][0][0], dp[i - 1][p][1][0], MOD);

                if(c < b[i] - '0')
                    dp[i][j][0][0] = add(dp[i][j][0][0], dp[i - 1][p][0][1], MOD);

                if(c > a[i] - '0' && c < b[i] - '0')
                    dp[i][j][0][0] = add(dp[i][j][0][0], dp[i - 1][p][1][1], MOD);

                if(c == a[i] - '0')
                {
                    dp[i][j][1][0] = add(dp[i][j][1][0], dp[i - 1][p][1][0], MOD);

                    if(c < b[i] - '0')
                        dp[i][j][1][0] = add(dp[i][j][1][0], dp[i - 1][p][1][1], MOD);
                }

                if(c == b[i] - '0')
                {
                    dp[i][j][0][1] = add(dp[i - 1][p][0][1], dp[i][j][0][1], MOD);

                    if(c > a[i] - '0')
                        dp[i][j][0][1] = add(dp[i][j][0][1], dp[i - 1][p][1][1], MOD);
                }

                if(c == a[i] - '0' && c == b[i] - '0')
                    dp[i][j][1][1] = add(dp[i][j][1][1], dp[i - 1][p][1][1], MOD);
            }
        }
    }

    //cout << dp[0][0][0][0] << ' ' << dp[0][0][0][1] << ' ' << dp[0][0][1][0] << ' ' << dp[0][0][1][1] << endl;

    int z = (n - 1);

    cout << add(add(dp[z][0][0][0], dp[z][0][0][1], MOD), add(dp[z][0][1][0], dp[z][0][1][1], MOD), MOD);
}