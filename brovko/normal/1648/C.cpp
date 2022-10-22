#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 998244353;

int n, m, s[200005], t[200005], fact[200005], k[200005], ft[200005];

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

int C(int x, int y)
{
    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans = add(ans, ft[r]);

    return ans;
}

void inc(int i, int d)
{
    for(; i < 200005; i = (i | i + 1))
        ft[i] = add(ft[i], d);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 200005; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = 0; i < m; i++)
        cin >> t[i];

    for(int i = 0; i < n; i++)
        k[s[i]]++;

    int q = 1;

    for(int i = 0; i < 200005; i++)
        q = mul(q, fact[k[i]]);

    for(int i = 0; i < 200005; i++)
        inc(i, k[i]);

    int ans = 0;

    for(int i = 0; i <= n; i++)
    {
        if(i == n && n < m)
        {
            ans = add(ans, 1);
            break;
        }

        ans = add(ans, mul(sum(t[i] - 1), divide(fact[n - i - 1], q)));

        if(k[t[i]] == 0)
            break;

        q = divide(q, k[t[i]]);
        k[t[i]]--;

        inc(t[i], -1);
    }

    cout << ans;
}