#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, m, dp[505][505];
char a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        for(int i = 0; i < m; i++)
            dp[n][i] = 0;

        int ans = 0;

        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '.')
                dp[i][j] = 0;

            else if(j == 0 || j == m - 1)
                dp[i][j] = 1;

            else dp[i][j] = 1 + min({dp[i + 1][j - 1], dp[i + 1][j], dp[i + 1][j + 1]});

            ans += dp[i][j];
        }

        cout << ans << "\n";
    }
}