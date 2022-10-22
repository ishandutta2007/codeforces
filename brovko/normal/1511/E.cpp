#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
const int MOD = 998244353;

int n, m;

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

    cin >> n >> m;

    char a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0, w = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            w += (a[i][j] == 'o');

    int x = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(a[i][j] == 'o' && j > 0 && a[i][j - 1] == 'o')
            x = divide(add(MOD + 1, MOD - 2 * x), 4);
        else x = 0;

        //cout << mul(x, 32) << endl;

        ans = add(ans, mul(x, binpow(2, w)));
    }

    x = 0;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
    {
        if(a[j][i] == 'o' && j > 0 && a[j - 1][i] == 'o')
            x = divide(add(MOD + 1, MOD - 2 * x), 4);
        else x = 0;

        //cout << mul(x, 32) << endl;

        ans = add(ans, mul(x, binpow(2, w)));
    }

    cout << ans;
}