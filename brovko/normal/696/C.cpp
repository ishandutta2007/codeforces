#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;
const int MOD = 1e9 + 7;

int n, a[100005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
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

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 2;

    for(int i = 0; i < n; i++)
        ans = binpow(ans, a[i]);

    ans = divide(ans, 2);

    int p = ans;
    int f = 0;

    for(int i = 0; i < n; i++)
        if(a[i] % 2 == 0)
            f = 1;

    if(f)
        p = add(p, 1);
    else p = sub(p, 1);

    p = divide(p, 3);

    cout << p << '/' << ans;
}