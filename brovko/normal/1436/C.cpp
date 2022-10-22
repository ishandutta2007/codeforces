#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;
const int MOD = 1e9 + 7;

int n, x, pos, fact[1005];

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

int A(int x, int y)
{
    return divide(fact[x], fact[x - y]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 1005; i++)
        fact[i] = mul(i, fact[i - 1]);

    cin >> n >> x >> pos;

    int a = 0, b = 0;

    int L = 0, R = n;

    while(L < R)
    {
        int M = (L + R) / 2;

        if(M <= pos)
        {
            L = M + 1;

            if(M < pos)
                a++;
        }
        else
        {
            R = M;
            b++;
        }
    }

    cout << mul(A(x - 1, a), mul(A(n - x, b), fact[n - a - b - 1]));
}