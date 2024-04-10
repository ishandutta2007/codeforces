#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c;

    if(a < b - c || b > n)
        cout << n / a;

    else
    {
        int ans = 1;
        n -= b;

        int x = n / (b - c);

        n -= x * (b - c);
        n += c;

        ans += x;

        ans += n / a;
        cout << ans;
    }
}