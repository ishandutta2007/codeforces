#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int t, n, a[4005], dp[4005][4005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n * 2; i++)
            cin >> a[i];

        vector <int> v;

        int x = 0;
        int k = 1;

        for(int i = 1; i < n * 2; i++)
        {
            if(a[i] > a[x])
            {
                v.push_back(k);
                k = 1;
                x = i;
            }
            else k++;
        }
        
        v.push_back(k);

        for(int i = 0; i < v.size(); i++)
            for(int j = 0; j <= 2 * n; j++)
                dp[i][j] = 0;

        dp[0][0] = 1;
        dp[0][v[0]] = 1;

        for(int i = 1; i < v.size(); i++)
            for(int j = 0; j <= 2 * n; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if(j - v[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]]);
        }

        if(dp[(int)v.size() - 1][n])
            cout << "YES\n";
        else cout << "NO\n";
    }
}