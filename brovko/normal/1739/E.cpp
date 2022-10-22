#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    char a[2][n + 1];

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    a[0][n] = a[1][n] = '0';

    int dp[2][n + 1][4];

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n + 1; j++)
            for(int k = 0; k < 4; k++)
            {
                if(j == n)
                    dp[i][j][k] = 0;
                else dp[i][j][k] = -1e9;
            }

    for(int j = n - 1; j >= 0; j--)
        for(int i = 0; i < 2; i++)
            for(int mask = 0; mask < 4; mask++)
            {
                if((mask & 1) && a[0][j] == '0' || (mask & 2) && a[1][j] == '0')
                    continue;

                for(int nm = 0; nm < 4; nm++)
                {
                    int val = __builtin_popcount(mask);
                    int ni = (i ^ bool(mask & (1 << (i ^ 1))));

                    if((mask & (1 << (i ^ 1))) && (nm & (1 << i)))
                        val = -1e9;

                    dp[i][j][mask] = max(dp[i][j][mask], dp[ni][j + 1][nm] + val);
                }
            }

//    cout << dp[1][1][0] << endl;

    int ans = 0;

    for(int m = 0; m < 4; m++)
        ans = max(ans, dp[0][0][m]);

    cout << ans;
}

/*
6
101101
100110

*/