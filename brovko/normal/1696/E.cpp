#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

int fact[N];

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

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int C(int x, int y)
{
    if(x < 0 || y < 0 || x < y)
        return 0;

    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);

    int n;
    cin >> n;

    n++;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i++)
        ans = add(ans, C(i + a[i], i + 1));

    cout << ans;
}