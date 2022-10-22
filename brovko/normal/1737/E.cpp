#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int sub(int x, int y)
{
    return add(x, MOD - y);
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

    int p = binpow(x, y / 2);

    return mul(p, p);
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

void naive(int n)
{
    vector <int> suf(n);

    for(int mask = 0; mask < (1 << n); mask++)
    {
        int mx = 0;

        for(int i = 0; i < n; i++)
        {
            bool F = (i == n - 1 || (mask & (1 << i)) == 0);

            for(int j = (i + 1) / 2; j < i; j++)
                F &= ((mask & (1 << j)) != 0);

            if(F)
                mx = max(mx, i);
        }

        for(int i = 0; i <= (mx + 1) / 2; i++)
            suf[i]++;
    }

    for(int i = 0; i < n; i++)
        cout << suf[i] << ' ';

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {

        int n;
        cin >> n;

        vector <int> suf(n + 1), bsuf(n + 1);

        bsuf[n] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            suf[i] = suf[i + 1];

            if(2 * i - 1 < n)
                suf[i] = add(suf[i], mul(binpow(inv(2), i - (2 * i - 1 == n - 1)), bsuf[2 * i]));

            if(2 * i < n)
                suf[i] = add(suf[i], mul(binpow(inv(2), i + 1 - (2 * i == n - 1)), bsuf[2 * i + 1]));

            bsuf[i] = sub(1, suf[i]);

    //        cout << suf[i] << endl;
        }

        for(int i = 0; i < n; i++)
            suf[i] = mul(suf[i], binpow(2, n));

    //    for(int i = 0; i < n; i++)
    //        cout << suf[i] << ' ';
    //
    //    cout << endl;

    //    naive(n);

        for(int i = 0; i < n; i++)
        {
            int ans = mul(bsuf[i + 1], binpow(inv(2), i - (i + 1) / 2 + 1 - (i == n - 1)));
            cout << ans << "\n";
        }

    }
}