#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int n, x, dp[505][505], fact[505], ifact[505];

int add(int x, int y)
{
    x += y;
    if(x >= MOD)
        x -= MOD;

    return x;
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

int C(int x, int y)
{
    return mul(fact[x], mul(ifact[x - y], ifact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    fact[0] = 1;

    for(int i = 1; i <= n; i++)
        fact[i] = mul(i, fact[i - 1]);

    for(int i = 0; i <= n; i++)
        ifact[i] = inv(fact[i]);

    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= x; j++)
        {
            if(i == 0)
                dp[i][j] = 1;
            else if(i == 1)
                dp[i][j] = 0;
            else if(i > j)
                dp[i][j] = binpow(j, i);
            else
            {
                for(int k = 0; k <= i; k++)
                    dp[i][j] = add(dp[i][j], mul(dp[i - k][j - i + 1], mul(C(i, k), binpow(i - 1, k))));
            }
        }

    cout << dp[n][x];
}