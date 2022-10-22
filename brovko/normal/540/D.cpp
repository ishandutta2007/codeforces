#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int r, s, p;
ld dp[105][105][105][3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> s >> p;

    for(int i = 0; i <= r; i++)
        for(int j = 0; j <= s; j++)
            for(int k = 0; k <= p; k++)
            {
                if(i + j + k == 0)
                    continue;

                if(i > 0 && j == 0 && k == 0)
                    dp[i][j][k][0] = 1;

                if(i == 0 && j > 0 && k == 0)
                    dp[i][j][k][1] = 1;

                if(i == 0 && j == 0 && k > 0)
                    dp[i][j][k][2] = 1;

                if(i > 0 && j > 0)
                    for(int z = 0; z < 3; z++)
                        dp[i][j][k][z] += (ld)(i * j) / (i * j + i * k + j * k) * dp[i][j - 1][k][z];

                if(k > 0 && j > 0)
                    for(int z = 0; z < 3; z++)
                        dp[i][j][k][z] += (ld)(k * j) / (i * j + i * k + j * k) * dp[i][j][k - 1][z];

                if(i > 0 && k > 0)
                    for(int z = 0; z < 3; z++)
                        dp[i][j][k][z] += (ld)(i * k) / (i * j + i * k + j * k) * dp[i - 1][j][k][z];
            }

    cout << setprecision(20) << dp[r][s][p][0] << ' ' << dp[r][s][p][1] << ' ' << dp[r][s][p][2];
}