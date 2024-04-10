#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    char a[n + 2][m + 2];
    int dp[n + 2][m + 2], Max[m + 2] = {0};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = j + 1;

                if(a[i - 1][j] == '.')
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);

                if(a[i][j - 1] == '.')
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }

            Max[j] = max(Max[j], dp[i][j]);
        }

    for(int j = 1; j < m; j++)
        Max[j] = max(Max[j], Max[j - 1]);

    int t;
    cin >> t;

    while(t--)
    {
        int l, r;
        cin >> l >> r;

        if(Max[r - 1] > l)
            cout << "NO\n";
        else cout << "YES\n";
    }
}