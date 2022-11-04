#include <cmath>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

long long dp[(int)1e5 + 10][5];
long long a[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long b[3];
    cin >> n >> b[0] >> b[1] >> b[2];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fill(dp[0], dp[0] + 4, (long long)-5e18);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1] + b[j - 1] * a[i]);
        }
    }
    cout << dp[n][3] << endl;
    return 0;
}