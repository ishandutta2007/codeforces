#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, k, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++)
        cin >> a[i];

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        int x;
        cin >> x;

        int y = 0;

        for(int i = 0; i < k; i++)
            if(a[i] == x)
                y = i;

        ans += y + 1;

        int z = a[y];

        for(int i = y - 1; i >= 0; i--)
            a[i + 1] = a[i];

        a[0] = z;
    }

    cout << ans;
}