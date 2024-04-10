#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int s, x1, x2, t1, t2, p, d;

int tram(int p, int d, int x)
{
    if(d == 1 && p <= x || d == -1 && p >= x)
        return abs(p - x) * t1;

    if(d == 1)
        return t1 * (2 * s - p - x);

    return t1 * (p + x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

    int d1 = 1;

    if(p > x1 || (p == x1 && d == -1))
        d1 = -1;

    cout << min(abs(x1 - x2) * t2, tram(p, d, x1) + tram(x1, d1, x2));
}