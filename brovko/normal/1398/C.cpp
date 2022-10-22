#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, ps[100005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        ps[0] = 0;

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + s[i] - '0';

        for(int i = 0; i <= n; i++)
            ps[i] -= i;

        map <int, int> m;

        int ans = 0;

        for(int i = 0; i <= n; i++)
        {
            ans += m[ps[i]];
            m[ps[i]]++;
        }

        cout << ans << "\n";
    }
}