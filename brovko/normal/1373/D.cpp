#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[200005];

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

        vector <int> v;

        for(int i = 1; i < n; i += 2)
            v.push_back(a[i] - a[i - 1]);

        int ans = 0;

        int dp[n];

        for(int i = 0; i < v.size(); i++)
        {
            if(i == 0)
                dp[i] = max(0ll, v[i]);
            else dp[i] = max(0ll, v[i] + dp[i - 1]);

            ans = max(ans, dp[i]);
        }

        v.clear();

        for(int i = 2; i < n; i += 2)
            v.push_back(a[i - 1] - a[i]);

        for(int i = 0; i < v.size(); i++)
        {
            if(i == 0)
                dp[i] = max(0ll, v[i]);
            else dp[i] = max(0ll, v[i] + dp[i - 1]);

            ans = max(ans, dp[i]);
        }

        for(int i = 0; i < n; i += 2)
            ans += a[i];

        cout << ans << "\n";
    }
}