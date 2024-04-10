#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = (1 << 20);
const int MOD = 1e9 + 7;

int n, a[N], k[N];

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        k[a[i]]++;
    }

    for(int i = 0; i < N / 2; i++)
        swap(k[i], k[N - 1 - i]);

    for(int i = 0; i < 20; i++)
        for(int j = 0; j < N; j++)
            if((j & (1 << i)) == 0)
                k[j ^ (1 << i)] += k[j];

    for(int i = 0; i < N / 2; i++)
        swap(k[i], k[N - 1 - i]);

    int ans = 0;

    for(int i = 0; i < N; i++)
    {
        if(__builtin_popcount(i) % 2 == 0)
            ans = add(ans, binpow(2, k[i]));
        else ans = sub(ans, binpow(2, k[i]));
    }

    cout << ans;
}