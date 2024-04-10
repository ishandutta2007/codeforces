#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a, b, c, d;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> d >> c;

    cout << max(0ll, n * (min({a + b, b + c, c + d, d + a}) - max({a + b, b + c, c + d, d + a}) + n));
}