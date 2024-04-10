#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

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
        string s;
        cin >> s;

        int n = s.size();

        int dp[n + 1][n + 1] = {};

        for(int i = n - 1; i >= 0; i--)
            for(int j = i + 1; j < n; j += 2)
            {
                if(dp[i + 2][j + 1] == 1 && dp[i + 1][j] == 1)
                    dp[i][j + 1] = 1;

                if(dp[i + 1][j] == 1 && dp[i][j - 1] == 1)
                    dp[i][j + 1] = 1;

                if(dp[i][j + 1] == 0)
                {
                    dp[i][j + 1] = -1;

                    if(dp[i + 2][j + 1] >= 0 && dp[i + 1][j] >= 0)
                    {
                        char a = s[i];
                        char b = 127;

                        if(dp[i + 2][j + 1] <= 0)
                            b = min(b, s[i + 1]);

                        if(dp[i + 1][j] <= 0)
                            b = min(b, s[j]);

                        dp[i][j + 1] = max(dp[i][j + 1], (int)(a < b ? 1 : a == b ? 0 : -1));
                    }

                    if(dp[i + 1][j] >= 0 && dp[i][j - 1] >= 0)
                    {
                        char a = s[j];
                        char b = 127;

                        if(dp[i + 1][j] <= 0)
                            b = min(b, s[i]);

                        if(dp[i][j - 1] <= 0)
                            b = min(b, s[j - 1]);

                        dp[i][j + 1] = max(dp[i][j + 1], (int)(a < b ? 1 : a == b ? 0 : -1));
                    }
                }
            }

        cout << (dp[0][n] == 1 ? "Alice\n" : dp[0][n] == 0 ? "Draw\n" : "Bob\n");
    }
}