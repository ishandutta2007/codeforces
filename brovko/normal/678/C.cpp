#include <bits/stdc++.h>
#define int long long
#define ld double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a, b, p, q;

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

    cin >> n >> a >> b >> p >> q;

    cout << n / a * p + n / b * q - n / lcm(a, b) * min(p, q);
}