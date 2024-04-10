#include <bits/stdc++.h>
using namespace std;

int dp[1 << 15][15];
int t[15], g[15];
const int mod = 1e9 + 7;

int main()
{
    int n, T;
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; i++)
        scanf("%d%d", t + i, g + i), --g[i];
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if (dp[i][j])
                for (int k = 0; k < n; k++)
                    if ((i >> k & 1 ^ 1) && g[k] != g[j])
                        (dp[i | (1 << k)][k] += dp[i][j]) %= mod;
    int ans = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        int tt = 0;
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                tt += t[j];
        if (tt == T)
            for (int j = 0; j < n; j++)
                (ans += dp[i][j]) %= mod;
    }
    printf("%d\n", ans);
}