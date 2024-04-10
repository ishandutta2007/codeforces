#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005], dp[100005][2], ps[100005];

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
            ps[i + 1] = ps[i] + a[i];

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 1e18;
            dp[i][1] = 0;
        }

        for(int k = 1; ; k++)
        {
            for(int i = n - k; i >= 0; i--)
            {
                dp[i][1] = dp[i + 1][1];

                if(dp[i + k][0] > ps[i + k] - ps[i])
                    dp[i][1] = max(dp[i][1], ps[i + k] - ps[i]);
            }

            int F = 0;

            for(int i = 0; i < n; i++)
                if(dp[i][1] > 0)
                    F = 1;

            if(F == 0)
            {
                cout << k - 1 << "\n";
                break;
            }

            for(int i = 0; i <= n; i++)
            {
                dp[i][0] = dp[i][1];
                dp[i][1] = 0;
            }
        }
    }
}