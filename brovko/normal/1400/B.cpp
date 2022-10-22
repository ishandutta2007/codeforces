#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, p, f, cnts, cntw, s, w;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> p >> f >> cnts >> cntw >> s >> w;

        if(s > w)
        {
            swap(s, w);
            swap(cnts, cntw);
        }

        int ans = 0;

        for(int i = 0; i <= min(cnts, p / s); i++)
        {
            int x = i * s;
            int ks = i, kw = min(cntw, (p - x) / w);

            x += kw * w;

            int s2 = min(cnts - ks, f / s);
            int y = s2 * s;

            int w2 = min(cntw - kw, (f - y) / w);
            y += w2 * w;

            ans = max(ans, ks + kw + s2 + w2);
        }

        cout << ans << "\n";
    }
}