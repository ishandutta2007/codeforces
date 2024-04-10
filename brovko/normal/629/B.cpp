#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, l, r, kf[370], km[370];
char c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> c >> l >> r;

        for(int j = l; j <= r; j++)
        {
            if(c == 'M')
                km[j]++;
            else kf[j]++;
        }
    }

    int ans = 0;

    for(int i = 0; i < 370; i++)
        ans = max(ans, 2 * min(kf[i], km[i]));

    cout << ans;
}