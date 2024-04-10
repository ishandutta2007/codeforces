#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 9;

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int x = max(0ll, m - (n - m) * 1ll * (k - 1)) / k;

//    cout << x << endl;

    int ans = add(binpow(2, x + 1), MOD - 2);

//    cout << ans << endl;

    cout << add(mul(k, ans), add(m, MOD - mul(x, k)));
}