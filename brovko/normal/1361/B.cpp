#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;
const int mod = (1ll << 62);

int n, p, a[1000005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int rec(int x, int y)
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

int add2(int x, int y)
{
    return (x + y) % mod;
}

int rec2(int x, int y)
{
    return add2(x, mod - y);
}

int mul2(int x, int y)
{
    return x * y % mod;
}

int binpow2(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2)
        return mul2(x, binpow2(x, y - 1));
    int z = binpow2(x, y / 2);
    return mul2(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t;
    cin >> t;

    while(t--)
    {
        cin >> n >> p;
        for(int i=0; i<n; i++)
            cin >> a[i];

        sort(a, a + n);

        int ans = binpow(p, a[n - 1]);
        int ans2 = binpow2(p, a[n - 1]);

        for(int i=n-2; i>=0; i--)
        {
            //cout << ans << ' ' << ans2 << "\n";
            if(a[i] == a[i + 1] || (ans == 0 && ans2 == 0))
            {
                if(ans == 0 && ans2 == 0)
                    {
                        ans = binpow(p, a[i]);
                        ans2 = binpow2(p, a[i]);
                    }
                else
                {
                    ans = 0;
                    ans2 = 0;
                }
            }
            else
            {
                int j = i;
                while(i >= 0 && (ans != 0 || ans2 != 0))
                {
                    ans = rec(ans, binpow(p, a[i]));
                    ans2 = rec2(ans2, binpow2(p, a[i]));
                    i--;
                }
                i++;
            }
        }

        cout << ans << "\n";
    }

}