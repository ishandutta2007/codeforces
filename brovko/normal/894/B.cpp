#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

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

    int n, m, k;
    cin >> n >> m >> k;

    if(k == -1 && (n % 2 && m % 2 == 0 || m % 2 && n % 2 == 0))
    {
        cout << 0;
        return 0;
    }

    int ans = binpow(2, n);
    ans = binpow(ans, m);

    ans = divide(ans, binpow(2, n + m - 1));
    cout << ans;
}