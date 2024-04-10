#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[105], dp[105][65536], mask[105], pr[105][65536], b[105];
vector <int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1; i <= 58; i++)
    {
        for(int j = 0; j < 16; j++)
            if(i % p[j] == 0)
                mask[i] += (1ll << j);
    }

//    for(int i = 1; i <= 58; i++)
//        cout << mask[i] << endl;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 65536; j++)
        {
            dp[i][j] = 1e18;

            for(int k = 1; k <= 58; k++)
            {
                int x = dp[i][j];

                if((j & mask[k]) == mask[k])
                    dp[i][j] = min(dp[i][j], abs(a[i] - k) + ((i == 0 && j == mask[k]) ? 0ll : i == 0 ? (int)1e18 : dp[i - 1][j - mask[k]]));

                if(dp[i][j] < x)
                    pr[i][j] = k;
            }
        }

    int ans = 1e18;

    for(int j = 0; j < 65536; j++)
        ans = min(ans, dp[n - 1][j]);

//    cout << "ans = " << ans << endl;

    int x = 0;

    while(dp[n - 1][x] > ans)
        x++;

//    cout << "x = " << x << endl;

    for(int i = n - 1; i >= 0; i--)
    {
        b[i] = pr[i][x];
        x -= mask[pr[i][x]];
    }

    for(int i = 0; i < n; i++)
        cout << b[i] << ' ';
}