#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, d[205], p[205], dp[6005][205];
long long a[205];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        while(a[i] % 2 == 0)
        {
            a[i] /= 2;
            d[i]++;
        }

        while(a[i] % 5 == 0)
        {
            a[i] /= 5;
            p[i]++;
        }
    }

    for(int i = 0; i < 6005; i++)
        for(int j = 0; j < k; j++)
            dp[i][j] = -1e9;

    dp[0][0] = 0;


    for(int i = 0; i < n; i++)
        for(int x = k - 1; x >= 0; x--)
            for(int j = 0; j < 6005; j++)
            if(j + p[i] < 6005)
                {
                    dp[j + p[i]][x + 1] = max(dp[j + p[i]][x + 1], dp[j][x] + d[i]);
                }


    int Max = 0;

    /*for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }*/

    for(int j = 0; j < 6005; j++)
        {
            Max = max(Max, min(j, dp[j][k]));

            /*if(min(j, dp[j][k]) == 4)
                cout << j << ' ';*/
        }

    cout << Max;
}