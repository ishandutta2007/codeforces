#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

int lcm(int x, int y)
{
    return x * 1ll * y / __gcd(x, y);
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
        int b, q, y;
        cin >> b >> q >> y;

        int c, r, z;
        cin >> c >> r >> z;

        if(r % q != 0 || (c - b) % q != 0 || b > c || b + q * 1ll * (y - 1) < c + r * 1ll * (z - 1))
        {
            cout << "0\n";
            continue;
        }

        if(b > c - r || b + q * 1ll * (y - 1) < c + r * 1ll * z)
        {
            cout << "-1\n";
            continue;
        }

        int ans = 0;

        for(int i = 1; i * i <= r; i++)
        {
            if(r % i == 0)
            {
                if(lcm(q, i) == r)
                    ans = add(ans, mul(r / i, r / i));

                if(i * i != r && lcm(q, r / i) == r)
                    ans = add(ans, mul(i, i));
            }
        }

        cout << ans << "\n";
    }
}