#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int n, a[200005], t[200005], b[200005], ps[200005];

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

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans = add(ans, t[r]);

    return ans;
}

void inc(int i, int d)
{
    for(; i <= n; i = (i | i + 1))
        t[i] = add(t[i], d);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(a[i] > -1)
        {
            ans = add(ans, sum(a[i]));
            inc(a[i], 1);
        }
    }

    for(int i = 0; i < n; i++)
        if(a[i] > -1)
            b[a[i]]++;

    ps[0] = 0;

    for(int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + 1 - b[i];

    int x = 0, k = 0;

    for(int i = 0; i < n; i++)
        if(a[i] == -1)
            k++;
    if(k > 0)
        for(int i = 0; i < n; i++)
        {
            if(a[i] > -1)
                ans = add(ans, add(mul(ps[a[i]], divide(k - x, k)), mul(k - ps[a[i]], divide(x, k))));
            else x++;
        }

    ans = add(ans, divide(mul(k, k - 1), 4));

    cout << ans;
}