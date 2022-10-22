#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int x, y, z, a[300005], b[300005], c[300005], sa, sb, sc, s, ma, mb, mc;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> z;

    int ma = 1e9, mb = 1e9, mc = 1e9;

    for(int i = 0; i < x; i++)
    {
        cin >> a[i];
        sa += a[i];
        s += a[i];
        ma = min(ma, a[i]);
    }

    for(int i = 0; i < y; i++)
    {
        cin >> b[i];
        sb += b[i];
        s += b[i];
        mb = min(mb, b[i]);
    }

    for(int i = 0; i < z; i++)
    {
        cin >> c[i];
        sc += c[i];
        s += c[i];
        mc = min(mc, c[i]);
    }

    cout << max({s - 2 * sa, s - 2 * sb, s - 2 * sc, s - 2 * ma - 2 * mb, s - 2 * ma - 2 * mc, s - 2 * mb - 2 * mc});
}