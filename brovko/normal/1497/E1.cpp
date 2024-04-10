#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int t, n, k, a[200005], dp[10000005], used[10000005], u;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i < 10000005; i++)
    {
        if(dp[i] == 0)
            dp[i] = i;

        for(int j = 2; i * j * j < 10000005; j++)
            dp[i * j * j] = dp[i];
    }

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        u++;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = dp[a[i]];

            if(used[a[i]] == u)
            {
                u++;
                ans++;
            }

            used[a[i]] = u;
        }

        cout << ans + 1 << "\n";
    }
}