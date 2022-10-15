#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d, e, f, t, ans = 0;
    cin >> a >> b >> c >> d >> e >> f;
    if (f > e)
    {
        t = min(min(b, c), d);
        b -= t;
        c -= t;
        d -= t;
        ans += t * f;
        t = min(a, d);
        a -= t;
        d -= t;
        ans += t * e;
    }
    else
    {
        t = min(a, d);
        a -= t;
        d -= t;
        ans += t * e;
        t = min(min(b, c), d);
        b -= t;
        c -= t;
        d -= t;
        ans += t * f;
    }
    cout << ans << "\n";
}