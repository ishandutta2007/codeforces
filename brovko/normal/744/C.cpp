#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, r[16], b[16], dp[257][65536], used[16], kb, kr;
char c[16];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> c[i] >> r[i] >> b[i];

    int R1 = 0;

    for(int i = 0; i < n; i++)
    {
        if(r[i] > n)
        {
            R1 += r[i] - n;
            r[i] = n;
        }
    }

    for(int i = 0; i < 257; i++)
        for(int mask = 1; mask < 65536; mask++)
            dp[i][mask] = 1000000000;

    for(int R = 0; R < n * n + 1; R++)
    {
        for(int i = 0; i < n; i++)
            used[i] = 0;

        kb = 0;
        kr = 0;

        for(int mask = 1; mask < (1 << n); mask++)
        {
            int z = 0;

            while(used[z])
            {
                used[z] = 0;

                if(c[z] == 'R')
                    kr--;
                else kb--;

                z++;
            }

            used[z] = 1;

            if(c[z] == 'R')
                kr++;
            else kb++;

            /*cout << mask << ' ';
            for(int i = 0; i < n; i++)
                cout << used[i];
            cout << "\n";*/

            for(int i = 0; i < n; i++)
                if(used[i])
                {
                    if(c[i] == 'R')
                    {
                        if(R - max(0, r[i] - kr + 1) >= 0)
                            dp[R][mask] = min(dp[R][mask], dp[R - max(0, r[i] - kr + 1)][mask - (1 << i)] + max(0, b[i] - kb));
                    }
                    else
                    {
                        if(R - max(0, r[i] - kr) >= 0)
                            dp[R][mask] = min(dp[R][mask], dp[R - max(0, r[i] - kr)][mask - (1 << i)] + max(0, b[i] - kb + 1));
                    }
                }
        }
    }

    /*for(int i = 0; i < (1 << n); i++)
        cout << dp[1][i] << ' ';
    cout << "\n";*/

    int ans = 1000000000;

    for(int R = 0; R < n * n + 1; R++)
        ans = min(ans, max(R + R1, dp[R][(1 << n) - 1]));

    cout << ans + n;
}