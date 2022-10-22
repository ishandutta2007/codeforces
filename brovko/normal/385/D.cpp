#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const ld pi = 3.14159265358979323846;

int n, l, r, x[25], y[25], a[25];
ld dp[1 << 20];

ld dist(ld x, ld a, ld b, ld alpha)
{
    alpha *= pi / 180;
    ld beta = atan2(b, a - x);
    ld gamma = pi - alpha - beta;

    ld ab = sqrt((a - x) * (a - x) + b * b);

    if(gamma <= 1e-9)
        return 1e18;

    ld d = sin(alpha) * ab / sin(gamma);
    return d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> r;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> a[i];

    dp[0] = l;

    for(int i = 1; i < (1 << n); i++)
    {
        dp[i] = -1e18;
        
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
            {
                dp[i] = min((ld)r, max(dp[i], dp[i ^ (1 << j)] + dist(dp[i ^ (1 << j)], x[j], y[j], a[j])));
            }
    }

    cout << setprecision(20) << min((ld)r, dp[(1 << n) - 1]) - l;
}