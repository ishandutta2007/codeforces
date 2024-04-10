#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int n, m, a, b[200005];

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

    cin >> n >> m >> a;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(b, b + m);

    int ans = binpow(a, n - 2 * b[m - 1]);

    for(int i = m - 1; i >= 1; i--)
        b[i] -= b[i - 1];

    for(int i = 0; i < m; i++)
        ans = mul(ans, divide(add(binpow(a, 2 * b[i]), binpow(a, b[i])), 2));

    cout << ans;
}