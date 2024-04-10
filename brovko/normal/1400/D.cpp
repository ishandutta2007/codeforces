#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, a[3005], b[3005][3005];

int k(int l, int r, int x)
{
    if(l == 0)
        return b[r][x];

    return b[r][x] - b[l - 1][x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            for(int j = 0; j <= n; j++)
                b[i][j] = 0;

        b[0][a[0]] = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= n; j++)
                b[i][j] = b[i - 1][j];

            b[i][a[i]]++;
        }

        int ans = 0;

        for(int i = 0; i < n - 1; i++)
            for(int j = 1; j < i; j++)
        {
            ans += k(0, j - 1, a[i]) * k(i + 1, n - 1, a[j]);
        }

        cout << ans << "\n";
    }
}