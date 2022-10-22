#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MOD = 998244353;

int n, k, l, r, fact[300005];
vector <pair <int, int> > v;

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
    if(y > x)
        return 0;

    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 300005; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;

        v.push_back({l, 1});
        v.push_back({r, 2});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int c = 0;

    for(auto to:v)
    {
        int x = to.first;
        int y = to.second;

        if(y == 2)
            c--;
        else
        {
            ans = add(ans, C(c, k - 1));
            c++;
        }
    }

    cout << ans;
}