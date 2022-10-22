#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

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
    return mul(fact[x], mul(ifact[x - y], ifact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fact[0] = ifact[0] = 1;

    for(int i = 1; i <= n; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        ifact[i] = inv(fact[i]);
    }

    k = min(k, n);

    int ans = 0;

    for(int i = 0; i <= k; i++)
        ans = add(ans, C(n, i));

    cout << ans;
}