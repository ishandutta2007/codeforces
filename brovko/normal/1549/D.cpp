#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005], b[200005], st[200005][20];

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
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

        for(int i = 0; i < n - 1; i++)
            b[i] = abs(a[i + 1] - a[i]);

        int m = n - 1;

        for(int i = 0; i < m; i++)
            st[i][0] = b[i];

        for(int j = 1; j < 20; j++)
            for(int i = 0; i <= m - (1ll << j); i++)
                st[i][j] = gcd(st[i][j - 1], st[i + (1ll << j - 1)][j - 1]);

        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            int x = i, y = 0;

            for(int j = 19; j >= 0; j--)
            {
                if(x + (1ll << j) <= m && gcd(y, st[x][j]) > 1)
                {
                    y = gcd(y, st[x][j]);
                    x += (1ll << j);
                }
            }

            ans = max(ans, x - i);
        }

        cout << ans + 1 << "\n";
    }
}