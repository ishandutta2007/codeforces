#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;
const int MOD = 1e9 + 7;

int n, a[100005], kp[100005], b[100005], lp[100005], sp[100005];

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


    for(int i = 2; i < 100005; i++)
        if(lp[i] == 0)
    {
        lp[i] = i;
        for(int j = i * i; j < 100005; j += i)
            if(lp[j] == 0)
                    lp[j] = i;
    }

    for(int i = 1; i < 100005; i++)
    {
        int x = i;
        int k = 0;
        int y = -1;

        while(lp[x])
        {
            if(lp[x] != y)
            {
                y = lp[x];
                k = 0;
            }

            x /= lp[x];
            kp[i]++;
            k++;

            if(k >= 2)
                sp[i] = 1;
        }

        kp[i]++;
    }

    /*for(int i = 0; i < 106; i++)
        if(sp[i] == 0)
        cout << kp[i] << ' ' << i << "\n";*/

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }

    int ans = 0;

    for(int i = 1; i < 100005; i++)
        if(sp[i] == 0)
    {
        int x = 1;

        for(int j = i; j < 100005; j += i)
            x = mul(x, binpow(2, b[j]));

        if(kp[i] % 2)
            ans = add(ans, x - 1);
        else ans = sub(ans, x - 1);

        /*if(x > 1)
            cout << x << ' ' << ans << ' ' << i << "\n";*/
    }

    cout << (ans + MOD) % MOD;
}