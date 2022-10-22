#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int MOD = 998244353;
const int N = 65;

int fact[N], ifact[N];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
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

int C(int x, int y)
{
    if(y < 0 || x < y)
        return 0;

    return mul(fact[x], mul(ifact[x - y], ifact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = ifact[0] = 1;

    for(int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        ifact[i] = inv(fact[i]);
    }

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int x = n / 2, y = n / 2, ans = 0;

        for(int i = 0; i < n; i += 2)
        {
            if(i % 4 == 0)
                ans = add(ans, C(x + y - 1, x - 1));
            else ans = add(ans, C(x + y - 2, x - 2));

            x--;
            y--;
        }

        cout << ans << ' ' << add(MOD - 1, add(MOD - ans, C(n, n / 2))) << ' ' << 1 << "\n";
    }
}