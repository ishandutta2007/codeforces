#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int t, n, m, k, fact[1000005];

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

int C(int x, int y)
{
    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 1000005; i++)
        fact[i] = mul(i, fact[i - 1]);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> k;

        if(m == 0)
            cout << 0 << "\n";

        else if(m == n)
            cout << mul(m, k) << "\n";

        else
        {
            int ans = 0;

            for(int i = 1; i <= m; i++)
                ans = add(ans, mul(C(n - i - 1, m - i), mul(i, binpow(2, MOD - 1 - (n - i - 1 + 1)))));

            cout << mul(ans, k) << "\n";
        }

    }
}