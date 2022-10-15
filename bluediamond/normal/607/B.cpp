#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 5;

int n;
int a[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }
            if (j - i == 1)
            {
                dp[i][j] = 1 + (a[i]!=a[j]);
                continue;
            }
            dp[i][j] = (1 << 30);
            for (int  k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (a[i] == a[j])
            {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
}
/**

3 1 2 3

**/