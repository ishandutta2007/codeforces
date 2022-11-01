#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    long dp[1001], pos[5][1001], a[5][1001], i, j, k, n, ma, max1 = 0, p;
    scanf("%ld %ld", &n, &k);
    for(i = 0; i < k; i++)
        for(j = 0; j < n; j++)
        {
            scanf("%ld", &a[i][j]);
            pos[i][a[i][j]] = j;
        }
    for(i = 0; i < n; i++)
    {
        ma = 0;
        for(j = 0; j < i; j++)
        {
            for(p = 1; p < k && pos[p][a[0][i]] > pos[p][a[0][j]]; p++);
            if(k == p && dp[j] > ma)ma = dp[j];
        }
        dp[i] = ma + 1;
        max1 = max(dp[i], max1);
    }
    cout << max1;
    return 0;
}