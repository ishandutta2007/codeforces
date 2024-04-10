#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;
const int MOD = 998244353;
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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 1; i < n; i++)
            a[i] += a[i - 1];

        for(int i = 0; i < n; i++)
            a[i] = 2 * a[i] - a[n - 1];

        map <int, int> mp;

        for(int i = 0; i < n - 1; i++)
            mp[a[i]]++;

        int ans = 1;

        for(auto p:mp)
        {
            if(p.f < 0)
            {
                int x = p.s, y = mp[-p.f];

                int k = 0;

                for(int i = 0; i <= min(x, y); i++)
                    k = add(k, mul(C(x, i), C(y, i)));

                ans = mul(ans, k);
            }
            else if(p.f == 0)
            {
                ans = mul(ans, binpow(2, p.s));
            }
        }

        cout << ans << "\n";
    }
}