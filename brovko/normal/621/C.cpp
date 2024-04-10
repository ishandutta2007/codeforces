#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, p, l[100005], r[100005];
ld a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];

        a[i] = (ld)(r[i] / p - (l[i] - 1) / p) / (r[i] - l[i] + 1);
    }

    ld ans = 0;

    for(int i = 0; i < n - 1; i++)
    {
        ans += a[i] + a[i + 1] - a[i] * a[i + 1];
    }

    ans += a[0] + a[n - 1] - a[0] * a[n - 1];

    cout << setprecision(20) << ans * 2000;
}