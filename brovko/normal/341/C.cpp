#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

using li = long long;
const int MOD = 1e9 + 7;
const int N = 2005;

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

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int C(int x, int y)
{
    return mul(fact[x], mul(ifact[x - y], ifact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = ifact[0] = 1;

    for(int i = 1; i < N; i++)
    {
        fact[i] = mul(fact[i - 1], i);
        ifact[i] = inv(fact[i]);
    }

    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }

    vector <int> pos(n, -1);

    for(int i = 0; i < n; i++)
        if(a[i] >= 0)
            pos[a[i]] = i;

    int kp = 0, kt = 0;

    for(int i = 0; i < n; i++)
        if(a[i] < 0)
        {
            if(pos[i] >= 0)
                kp++;
            else kt++;
        }

    int ans = 0;

    for(int i = 0; i <= kt; i++)
    {
        int x = mul(C(kt, i), fact[kp + kt - i]);

        if(i % 2 == 0)
            ans = add(ans, x);
        else ans = add(ans, MOD - x);
    }

    cout << ans;
}