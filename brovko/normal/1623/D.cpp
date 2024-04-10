#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int n, m, a, b, c, d, p;

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

int inv(int x)
{
    return binpow(x, MOD - 2);
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

    int t;
    cin >> t;

    while(t--)
    {

        cin >> n >> m >> a >> b >> c >> d >> p;
        int x = a, y = b;

        int ans = 0, dr = 1, dc = 1;
        vector <int> v;

        while(ans == 0 || x != a || y != b || (x > 1 && x < n && dr != 1) || (y > 1 && y < m && dc != 1))
        {
            if(a == c || b == d)
                v.pb(ans);

            if(a == n)
                dr = -1;

            if(a == 1)
                dr = 1;

            if(b == m)
                dc = -1;

            if(b == 1)
                dc = 1;

            a += dr;
            b += dc;
            ans++;
        }

//        cout << "!" << ans << "\n";
//
//        for(auto x:v)
//            cout << x << ' ';
//
//        cout << "\n";

        p = divide(p, 100);

        int ans2 = 0;

        for(int i = 0; i < v.size(); i++)
        {
            int A = v[i];
            int P = mul(p, binpow(sub(1, p), i));
            int Q = binpow(sub(1, p), v.size());
            int S = ans;

            ans2 = add(ans2, add(divide(mul(A, P), sub(1, Q)), divide(mul(S, mul(P, Q)), binpow(sub(1, Q), 2))));
        }

        cout << ans2 << "\n";
    }
}