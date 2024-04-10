#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int n, k, dp[2][505][505], ps[505];

int add(int x, int y)
{
    return (x + y) % MOD;
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

    cin >> n >> k;

    dp[0][0][1] = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
            for(int z = j; z <= n; z++)
            {
                dp[1][j + 1][max(z, j + 1)] = add(dp[1][j + 1][max(z, j + 1)], dp[0][j][z]);
                dp[1][1][z] = add(dp[1][1][z], dp[0][j][z]);
            }

        for(int j = 0; j <= n; j++)
            for(int z = j; z <= n; z++)
            {
                dp[0][j][z] = dp[1][j][z];
                dp[1][j][z] = 0;
            }
    }

    int ans = 0;

    for(int z = 0; z <= n; z++)
    {
        int s = 0;

        for(int i = 0; i <= z; i++)
            s = add(s, dp[0][i][z]);

        ps[z + 1] = add(ps[z], s);
    }



//        ps[i + 1] = add(ps[i], dp[n][i]);

    for(int i = 1; i <= n; i++)
        for(int z = i; z <= n; z++)
            ans = add(ans, mul(dp[0][i][z], ps[min(n + 1, (k - 1) / z + 1)]));

    cout << divide(ans, 2);
}