#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[205], dp[205][405];

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

        sort(a, a + n);

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= 2 * n; j++)
            {
                dp[i][j] = 1e9;
            }

        for(int j = 0; j <= 2 * n; j++)
        {
            dp[0][j] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 1; j <= 2 * n; j++)
            {
                dp[i + 1][j] = min(dp[i + 1][j - 1], dp[i][j - 1] + abs(a[i] - j));
            }

        cout << dp[n][2 * n] << "\n";
    }
}