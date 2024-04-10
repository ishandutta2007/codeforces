#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;
const int MOD = 998244353;

int t, n, a[200005], fact[200005];

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

    fact[0] = 1;

    for(int i = 1; i < 200005; i++)
        fact[i] = mul(i, fact[i - 1]);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int x = a[0];

        for(int i = 0; i < n; i++)
            x = max(x, a[i]);

        int k = 0, k2 = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] == x)
                k++;

            if(a[i] == x - 1)
                k2++;
        }

        if(k >= 2)
            cout << fact[n] << "\n";

        else cout << mul(k2, divide(fact[n], k2 + 1)) << "\n";
    }
}