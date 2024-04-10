#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;
const int MOD = 1e9 + 7;

int n, k, l[400005], r[400005], fact[400005], a[400005], t[400005], y;
map <int, int> m;

int add(int x, int y)
{
    return (x + y) % MOD;
}

int sub(int x, int y)
{
    return add(x, MOD - y);
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
    if(x < y)
        return 0;

    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i < y; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 200005; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        v.push_back(l[i]);
        v.push_back(r[i]);
    }

    sort(v.begin(), v.end());

    y = 1;

    for(auto to:v)
    {
        if(m[to] == 0)
        {
            m[to] = y;
            a[y] = to;

            y++;
        }
    }

    int ans = 0;

    vector <pair <int, int> > u;

    for(int i = 0; i < n; i++)
        u.push_back({l[i], r[i]});

    sort(u.begin(), u.end());

    for(auto to:u)
    {
        ans = sub(ans, mul(to.first, C(sum(y - 1) - sum(m[to.first] - 1), k - 1)));

        inc(m[to.second], 1);
    }

    for(auto to:u)
    {
        inc(m[to.second], -1);
    }

    u.clear();

    for(int i = 0; i < n; i++)
        u.push_back({r[i], l[i]});

    sort(u.rbegin(), u.rend());

    for(auto to:u)
    {
        ans = add(ans, mul(to.first + 1, C(sum(m[to.first]), k - 1)));

        inc(m[to.second], 1);
    }

    cout << (ans + MOD) % MOD;
}