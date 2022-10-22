#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[500005];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> s;

    int x = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'B')
            x += a[i];
    }

    int y = 0, ans = x;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'A')
            y += a[i];
        else y -= a[i];

        ans = max(ans, x + y);
    }

    y = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == 'A')
            y += a[i];
        else y -= a[i];

        ans = max(ans, x + y);
    }

    cout << ans;
}