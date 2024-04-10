#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, dp[5005][5005];
char a[5005][5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = m - 1; j >= 0; j--)
        {
            if(a[i][j] == '0')
                dp[i][j] = 0;
            else dp[i][j] = 1 + (j < m - 1 ? dp[i][j + 1] : 0);
        }

//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//            cout << dp[i][j] << ' ';
//
//        cout << "\n";
//    }

    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        vector <int> v;

        for(int j = 0; j < n; j++)
            v.pb(dp[j][i]);

        sort(v.rbegin(), v.rend());

        for(int j = 0; j < n; j++)
            ans = max(ans, v[j] * (j + 1));
    }

    cout << ans;
}