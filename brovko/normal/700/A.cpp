#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, v1, v2, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> v1 >> v2 >> k;

    int c = (n + k - 1) / k;

    ld t = (ld)l / ((ld)2 * v1 * v2 / (v1 + v2) * (c - 1) + v2);
    t = min(t, (ld)l / v2);

    ld ans = t + (l - v2 * t) / v1;

    cout << setprecision(20) << ans;
}