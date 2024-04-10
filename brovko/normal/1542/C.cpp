#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;
const int MOD = 1e9 + 7;

int t, n;

int add(int x, int y)
{
    return (x + y) % MOD;
}

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int ans = add(n, n), x = 1;

        for(int i = 2; x <= n; i++)
        {
            x = lcm(x, i);
            ans = add(ans, n / x);
        }

        cout << ans << "\n";
    }
}