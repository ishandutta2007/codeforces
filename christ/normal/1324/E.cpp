#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int dp[MAXN][MAXN];

int main()
{
    int n, h, l, r;
    scanf("%i%i%i%i", &n, &h, &l, &r);
    for (int x = 0; x <= n; x++)
        for (int y = 0; y < h; y++)
            dp[x][y] = INT_MIN / 2;
    dp[0][0 ] = 0;
    int ans = 0;
    for (int x = 1; x <= n; x++)
    {
        int a;
        scanf("%i", &a);
        for (int y = 0; y <= 1; y++)
        {
            int _a = a - y;
            for (int z = 0; z < h; z++)
            {
                int _z = (z - _a) % h;
                _z += h;
                _z %= h;
                dp[x][z] = max(dp[x][z], dp[x-1][_z] + (l <= z && z <= r));
                ans = max(ans, dp[x][z]);
            }
        }
    }
    printf("%i\n", ans);
}