#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int m, c[500005], k[1000005], fact[2000005];

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

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> c[i];

    fact[0] = 1;

    for(int i = 1; i < 2000005; i++)
        fact[i] = mul(fact[i - 1], i);

    for(int i = 0; i < m; i++)
        k[c[i]]++;

    int ans = 1;

    int d = 0;

    for(int i = 0; i <= 1000000; i++)
        d += k[i] * i;

    d--;

//    cout << mul(divide(add(d, d - 2 * 1 + 2), 2), 1) << endl;

    int s = 0;

    for(int i = 1000000; i > 0; i--)
    {
        k[i] += k[i + 2];

        if(i > 1)
            ans = mul(ans, mul(fact[k[i]], fact[k[i]]));
        else ans = mul(ans, fact[k[i]]);

        if(i > 1 && k[i] > 0)
            s = add(s, add(mul(i - 2, mul(k[i], d - k[i] + 1)), mul(divide(add(d, d - 2 * k[i] + 2), 2), k[i])));

        d -= 2 * k[i];
    }

    cout << s << ' ' << ans;
}