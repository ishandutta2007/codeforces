#include <bits/stdc++.h>
//#define int long long
#define pb push_back

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int dp[n + 1][2] = {};

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                dp[a[i]][0] = dp[a[i]][1] + 1;
            else dp[a[i]][1] = dp[a[i]][0] + 1;
        }

        for(int i = 1; i <= n; i++)
            cout << max(dp[i][0], dp[i][1]) << ' ';

        cout << "\n";
    }
}