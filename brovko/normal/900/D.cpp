#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

int x, y;
map <int, int> dp;

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

int f(int x)
{
    if(dp[x])
        return dp[x];
    int ans = binpow(2, x - 1);

    for(int i=1; i * i <= x; i++)
        if(x % i == 0)
    {
        ans = add(ans, MOD - f(i));
        if(i * i < x && i != 1)
            ans = add(ans, MOD - f(x / i));
    }

    dp[x] = ans;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[1] = 1;

    cin >> x >> y;
    if(y % x)
    {
        cout << 0;
        return 0;
    }

    y /= x;
    cout << f(y);
}