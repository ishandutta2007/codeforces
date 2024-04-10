#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int a, dp[20][10][2], cnt[20][10][2];

int f(int x)
{
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 2; k++)
            {
                dp[i][j][k] = 0;
                cnt[i][j][k] = 0;
            }

    int ans = 0;

    vector <int> v(20);
    int y = x;

    for(int i = 0; y > 0; i++)
    {
        v[i] = y % 10;
        y /= 10;
    }

    reverse(v.begin(), v.end());

    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 10; j++)
            for(int k = 0; k < 2; k++)
            {
                if(i == 0)
                {
                    if(k == 1 && j == v[0] || k == 0 && j < v[0])
                        cnt[i][j][k] = 1;
                    else cnt[i][j][k] = 0;

                    dp[i][j][k] = cnt[i][j][k] * j;

                    continue;
                }

                if(k == 1)
                {
                    if(j == v[i])
                    {
                        dp[i][j][k] = dp[i - 1][v[i - 1]][k] + j;
                        cnt[i][j][k] = 1;
                    }
                }
                else
                {
                    for(int z = 0; z < 10; z++)
                    {
                        dp[i][j][0] += dp[i - 1][z][0] + j * cnt[i - 1][z][0];
                        cnt[i][j][0] += cnt[i - 1][z][0];
                    }

                    if(j < v[i])
                    {
                        dp[i][j][0] += dp[i - 1][v[i - 1]][1] + j;
                        cnt[i][j][0]++;
                    }
                }

//                if(dp[i][j][k] > 0)
//                    cout << i << ' ' << j << ' ' << k << endl;

                if(i == 19)
                    ans += dp[i][j][k];
            }

    return ans;
}



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;

    for(int i = 1; ; i++)
    {
        int L = 0, R = 1e17;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(f(M) - f(i - 1) < a)
                L = M;
            else R = M;
        }

        if(f(R) - f(i - 1) == a)
        {
            cout << i << ' ' << R;
            return 0;
        }
    }
}