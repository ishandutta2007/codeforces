#include <iostream>

using namespace std;

bool s[105] = {0}, c[105] = {0};
int dp[3][105];

const int rest = 0, sport = 1, contest = 2;

int main()
{
    ios_base::sync_with_stdio(false);

    int n, temp;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;

        if (temp >= 2)
            s[i] = true;

        if (temp == 1 or temp == 3)
            c[i] = true;
    }

    dp[rest][0] = 1;
    dp[sport][0] = (s[0]) ? 0 : 1e5;
    dp[contest][0] = (c[0]) ? 0 : 1e5;

    for (int i = 1; i < n; ++i)
    {
        dp[rest][i] = 1 + min(dp[rest][i-1], min(dp[sport][i-1], dp[contest][i-1]));
        dp[sport][i] = dp[contest][i] = 1e5;

        if (s[i])
            dp[sport][i] = min(dp[rest][i-1], dp[contest][i-1]);

        if (c[i])
            dp[contest][i] = min(dp[rest][i-1], dp[sport][i-1]);
    }

    cout << min(dp[rest][n-1], min(dp[sport][n-1], dp[contest][n-1]));

    return 0;
}