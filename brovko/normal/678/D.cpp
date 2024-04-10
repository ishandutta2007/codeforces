#include <bits/stdc++.h>
#define int long long
#define ld double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD = 1e9 + 7;

int a, b, n, x;

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
    if(x == 1)
        return b;

    if(x % 2)
        return add(b, mul(a, f(x - 1)));

    int z = f(x / 2);

    return mul(z, add(1, binpow(a, x / 2)));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> n >> x;

    int y = mul(x, binpow(a, n));

    cout << add(y, f(n));
}