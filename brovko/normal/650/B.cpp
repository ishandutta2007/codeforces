#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a, b, T;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> T >> s;

    int r = n - 1;

    int kw = 0;

    for(auto to:s)
        if(to == 'w')
            kw++;

    int ans = 0;

    for(int l = n - 1; l >= 0; l--)
    {
        while(r > l && a * (min(l, n - 1 - r) + l + n - 1 - r) + b * kw + l + n - 1 - r + 1 <= T)
            {
                if(s[r] == 'w')
                    kw++;

                r--;
            }

        if(r < n - 1 && a * (min(l, n - 1 - r) + l + n - 1 - r) + b * kw + l + n - r > T)
        {
            r++;

            if(s[r] == 'w')
                kw--;
        }

        if(a * (min(l, n - 1 - r) + l + n - 1 - r) + b * kw + l + n - 1 - r + 1 <= T)
            ans = max(ans, l + n - r);

        if(s[l] == 'w')
            kw--;
    }

    cout << ans;
}