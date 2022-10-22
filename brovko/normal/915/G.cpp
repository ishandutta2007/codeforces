#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;
const int N = 2000005;

int n, k, kd[2000005], a[2000005], ans, z, c[2000005], p[2000005];
vector <int> v[2000005];

int add(int x, int y)
{
    return (x + y) % MOD;
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

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int sub(int x, int y)
{
    return add(x, MOD - y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < N; i++)
        p[i] = binpow(i, n);

    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            v[j].pb(i);

    for(int i = 2; i < N; i++)
    {
        int x = i;

        if(x % (v[i][1] * 1ll * v[i][1]) == 0)
            c[i] = 1;

        while(x % v[i][1] == 0)
            x /= v[i][1];

        kd[i] = kd[x] + 1;

        if(c[x])
            c[i] = 1;
    }

    //cout << 1 << endl;

    for(int i = 1; i <= k; i++)
    {
        for(auto to:v[i])
        {
            if(c[to] == 0)
            {
                if(kd[to] % 2 == 0)
                {
                    ans = sub(ans, p[a[to]]);
                    a[to]++;
                    ans = add(ans, p[a[to]]);
                }
                else
                {
                    ans = add(ans, p[a[to]]);
                    a[to]++;
                    ans = sub(ans, p[a[to]]);
                }
            }
        }

        //cout << ans << endl;

        z = add(z, (ans ^ i));
    }

    cout << z;
}