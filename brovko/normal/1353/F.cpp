#include <bits/stdc++.h>
//#define int long long
#define li long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int t, n, m;
li a[105][105], b[105][105], dp[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        li ans = 1e18;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                for(int x = 0; x <= n; x++)
                    for(int y = 0; y <= m; y++)
                    {
                        if((x == 0 || y == 0) && x + y != 1)
                            dp[x][y] = 1e18;
                        else dp[x][y] = 0;
                    }

                li a00 = a[i][j] - i - j;

                if(a00 > a[0][0])
                    continue;

                for(int x = 0; x < n; x++)
                    for(int y = 0; y < m; y++)
                    {
                        b[x][y] = a[x][y] - (a00 + x + y);

                        if(b[x][y] < 0)
                            b[x][y] = 1e18;

                        dp[x + 1][y + 1] = min(dp[x][y + 1], dp[x + 1][y]) + b[x][y];

                        if(dp[x + 1][y + 1] > 1e18)
                            dp[x + 1][y + 1] = 1e18;
                    }

                ans = min(ans, dp[n][m]);
            }

        cout << ans << "\n";
    }
}