#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int n, a[200005], k[35];

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
    if(y < 0)
        return 0;

    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        int x = 0;

        while(a[i] % 2 == 0)
        {
            a[i] /= 2;
            x++;
        }

        k[x]++;
    }

    int ans = sub(binpow(2, n), 1);

    for(int i = 1; i < 35; i++)
    {
        int x = binpow(2, k[i] - 1);

        for(int j = i + 1; j < 35; j++)
            x = mul(x, binpow(2, k[j]));

        ans = sub(ans, x);
    }

    cout << ans;
}