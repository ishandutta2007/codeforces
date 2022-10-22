#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 3e5 + 5;
const int MOD = 998244353;

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

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        fact[0] = ifact[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            fact[i] = mul(fact[i - 1], i);
            ifact[i] = inv(fact[i]);
        }

        vector <int> dp(n + 1);

        dp[0] = 1;

        for(int i = 1; i <= n; i++)
            dp[i] = add(dp[i - 1], mul(i - 1, (i < 2 ? 0 : dp[i - 2])));

        vector <int> pairs(n + 1);

        pairs[0] = 1;

        for(int i = 2; i <= n; i += 2)
            pairs[i] = mul(2, mul(i - 1, pairs[i - 2]));

        int ans = dp[n];

        for(int i = 1; i <= n / 4; i++)
        {
            ans = add(ans, mul(C(n - 2 * i, 2 * i), mul(dp[n - 4 * i], pairs[2 * i])));
        }

        cout << ans << "\n";
    }
}