#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[300005];
const int MOD = 1e9 + 7;

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

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = 0;
    int s = 0;

    for(int i = n - 1; i > 0; i--)
        s = add(mul(s, 2), a[i]);

    //cout << s << "\n";

    for(int i = 0; i < n - 1; i++)
    {
        ans = add(ans, add(s, MOD - mul(binpow(2, n - i - 1) - 1, a[i])));

        s = add(s, MOD - a[i + 1]);
        s = divide(s, 2);

        //cout << s << "\n";
    }

    cout << ans;
}