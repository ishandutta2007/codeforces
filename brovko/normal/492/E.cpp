#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, dx, dy, phi, k[1000005];

int add(int x, int y)
{
    return (x + y) % n;
}

int mul(int x, int y)
{
    return x * y % n;
}

int sub(int x, int y)
{
    return add(x, n - y);
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
    return binpow(x, phi - 1);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> dx >> dy;
    phi = n;

    int N = n;

    for(int i = 2; i <= N; i++)
    {
        if(N % i == 0)
        {
            while(N % i == 0)
                N /= i;

            phi = phi / i * (i - 1);
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        int y2 = sub(y, mul(dy, divide(x, dx)));
        k[y2]++;

        if(k[y2] > k[ans])
            ans = y2;
    }

    cout << 0 << ' ' << ans;
}