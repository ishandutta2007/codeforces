#include <bits/stdc++.h>
#define li long long

using namespace std;
const int N = 1005;

int dp[N][11][11];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int m;
    cin >> s >> m;

    s = "0" + s;

    dp[0][0][0] = 1;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < 11; j++)
            for(int k = 0; k < 11; k++)
                for(int nj = 1; nj < 11; nj++)
                    if(s[nj] == '1' && nj > k && j != nj)
                    {
                        dp[i + 1][nj][nj - k] |= dp[i][j][k];
                    }

    for(int j = 1; j < 11; j++)
        for(int k = 1; k < 11; k++)
            if(dp[m][j][k])
            {
                int I = m, J = j, K = k;

                vector <int> ans;

                while(I > 0)
                {
                    I--;
                    ans.push_back(J);
                    K = J - K;

                    for(int nj = 0; nj < 11; nj++)
                        if(nj != J && dp[I][nj][K])
                        {
                            J = nj;
                            break;
                        }
                }

                cout << "YES\n";

                reverse(ans.begin(), ans.end());

                for(int i = 0; i < ans.size(); i++)
                    cout << ans[i] << ' ';

                return 0;
            }

    cout << "NO";
}