#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1000000007;

int t, l, r, lp[5000005], f[5000005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i * i < 5000005; i++)
        if(lp[i] == 0)
            for(int j = i * i; j < 5000005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;

    for(int i = 2; i < 5000005; i++)
    {
        if(lp[i] == 0)
            f[i] = i * (i - 1) / 2 % MOD;
        else f[i] = (f[lp[i]] * i / lp[i] + f[i / lp[i]]) % MOD;
    }

    int x = 1;
    int ans = 0;

    cin >> t >> l >> r;

    for(int i = l; i <= r; i++)
    {
        ans = add(ans, mul(x, f[i]));
        x = mul(x, t);
    }

    cout << ans;
}