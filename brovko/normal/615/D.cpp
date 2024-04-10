#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;
const int MOD = 1e9 + 7;

int k[200005];

int add(int x, int y, int m)
{
    return (x + y) % m;
}

int mul(int x, int y, int m)
{
    return x * y % m;
}

int binpow(int x, int y, int m)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1, m), m);

    int z = binpow(x, y / 2, m);

    return mul(z, z, m);
}

int inv(int x, int m)
{
    return binpow(x, m - 2, m); // m = MOD
}

int divide(int x, int y, int m)
{
    return mul(x, inv(y, m), m);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin >> m;

    int p[m + 5];

    for(int i = 0; i < m; i++)
        cin >> p[i];

    for(int i = 0; i < m; i++)
        k[p[i]]++;

    int x = 1;

    int F = 0;

    for(int i = 0; i < 200005; i++)
    {
        if(k[i] % 2 && F == 0)
        {
            F = 1;
            x = mul(x, (k[i] + 1) / 2, MOD - 1);
        }
        else
        x = mul(x, k[i] + 1, MOD - 1);
    }

//    cout << x << endl;

    int ans = 1;

    for(int i = 1; i < 200005; i++)
        if(k[i] > 0)
            if(F)
                ans = mul(ans, binpow(i, x * k[i] % (MOD - 1), MOD), MOD);
            else ans = mul(ans, binpow(i, x * k[i] / 2 % (MOD - 1), MOD), MOD);

    cout << ans;
}