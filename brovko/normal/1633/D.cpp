#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int w[2005], b[1005], c[1005], dp[1005][12005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    w[1] = 0;

    for(int i = 2; i < 2005; i++)
        w[i] = 1e9;

    for(int i = 1; i <= 1000; i++)
        for(int j = 1; j <= i; j++)
            w[i + i / j] = min(w[i + i / j], w[i] + 1);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
            cin >> c[i];

        k = min(k, 12 * n);

        int ans = 0;

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= k; j++)
            {
                dp[i][j] = dp[i - 1][j];

                if(j >= w[b[i - 1]])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[b[i - 1]]] + c[i - 1]);

                ans = max(ans, dp[i][j]);
            }

        cout << ans << "\n";
    }
}