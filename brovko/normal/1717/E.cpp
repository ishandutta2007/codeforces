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

int lp[N], phi[N];
vector <int> divs[N];

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 2; i * i <= n; i++)
        if(lp[i] == 0)
            for(int j = i * i; j <= n; j += i)
                if(lp[j] == 0)
                    lp[j] = i;

    for(int i = 1; i <= n; i++)
    {
        if(lp[i] == 0)
            lp[i] = i;

        phi[i] = i;
        int val = i;

        while(val > 1)
        {
            int d = lp[val];

            while(lp[val] == d)
            {
                val /= d;
            }

            phi[i] /= d;
            phi[i] *= d - 1;
        }
    }

    phi[1] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j += i)
            divs[j].pb(i);

    int ans = 0;

    for(int c = 1; c <= n - 2; c++)
    {
        int ab = n - c;

        for(auto g:divs[ab])
        {
            int L = (c * 1ll * g / __gcd(c, g)) % MOD;
            ans = add(ans, mul(L, phi[ab / g]));
        }
    }

    cout << ans;
}