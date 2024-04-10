#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

int q, x, y, fact[2000005], lp[1000005];

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
    for(int i=1; i<2000005; i++)
        fact[i] = mul(fact[i - 1], i);

    for(int i=2; i <= 1000; i++)
        if(lp[i] == 0)
    {
        for(int j = i * i; j <= 1000000; j += i)
            if(lp[j] == 0)
                lp[j] = i;
    }

    cin >> q;
    while(q--)
    {
        cin >> x >> y;
        int ans = 1;

        while(lp[x])
        {
            int c = lp[x];
            int k = 0;

            while(x % c == 0)
            {
                x /= c;
                k++;
            }

            ans = mul(ans, C(k + y - 1, y - 1));
        }

        if(x > 1)
            ans = mul(ans, y);

        ans = mul(ans, binpow(2, y - 1));
        cout << ans << "\n";
    }
}