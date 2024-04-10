#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

int n, m, a[100005], b[100005], dp[100005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
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

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];

    dp[n] = 0;
    for(int i=n-1; i>=0; i--)
    {
        if(a[i] > 0 && b[i] > 0)
        {
            if(a[i] > b[i])
                dp[i] = 1;
            else if(a[i] == b[i])
                dp[i] = dp[i + 1];
            else dp[i] = 0;
        }

        if(a[i] > 0 && b[i] == 0)
        {
            dp[i] = add(divide(a[i] - 1, m), divide(dp[i + 1], m));
        }

        if(a[i] == 0 && b[i] > 0)
        {
            dp[i] = add(divide(m - b[i], m), divide(dp[i + 1], m));
        }

        if(a[i] == 0 && b[i] == 0)
        {
            dp[i] = add(divide(m - 1, mul(2, m)), divide(dp[i + 1], m));
        }
    }

    cout << dp[0];
}