#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int n, a[505], fact[100005];
map <int, int> k;

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 100005; i++)
        fact[i] = mul(fact[i - 1], i);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        for(int j = 2; j * j <= a[i]; j++)
        {
            while(a[i] % j == 0)
            {
                k[j]++;
                a[i] /= j;
            }
        }

        if(a[i] > 1)
            k[a[i]]++;
    }

    int ans = 1;

    for(auto x:k)
        ans = mul(ans, C(x.y + n - 1, n - 1));

    cout << ans;
}