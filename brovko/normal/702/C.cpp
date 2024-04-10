#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    int x = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        while(x < m - 1 && b[x + 1] <= a[i])
            x++;

        int y = abs(b[x] - a[i]);

        if(x < m - 1)
            y = min(y, abs(b[x + 1] - a[i]));

        ans = max(ans, y);
    }

    cout << ans;
}