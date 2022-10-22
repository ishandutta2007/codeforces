#include <bits/stdc++.h>

using namespace std;

int n, m, dp[2005][2005];
char a[2005][2005];

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(i <= 1 || j == 0 || j == m - 1 || a[i][j] != a[i - 1][j] || a[i][j] != a[i - 2][j] || a[i][j] != a[i - 1][j - 1] || a[i][j] != a[i - 1][j + 1])
            dp[i][j] = 1;
        else dp[i][j] = min({dp[i - 1][j], dp[i - 2][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + 1;

        ans += dp[i][j];
    }

    cout << ans;
}