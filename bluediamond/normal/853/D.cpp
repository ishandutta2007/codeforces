#include <bits/stdc++.h>

using namespace std;

const int B = 31;
const int INF = (int) 1e9;
int dp[B];
int dp_ant[B];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < B; i++)
    {
        dp[i] = INF;
    }

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x /= 100;
        for (int b = 0; b < B; b++)
        {
            dp_ant[b] = dp[b];
            dp[b] = INF;
        }
        for (int b = 0; b < B; b++)
        {
            if (b + x / 10 < B)
            {
                dp[b + x / 10] = min(dp[b + x / 10], dp_ant[b] + x);
            }
            int use = min(b, x);
            dp[b - use] = min(dp[b - use], dp_ant[b] + x - use);
        }
    }
    cout << dp[0] << "00\n";
}