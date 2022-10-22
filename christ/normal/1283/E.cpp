#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> cnt(n+1), dp(n+1);
    for (int x = 1; x <= n; x++)
    {
        int a;
        scanf("%i", &a);
        cnt[a]++;
    }
    if (n == 1)
        return 0 * printf("1 1\n");
    dp[1] = !!cnt[1];
    for (int x = 2; x <= n; x++)
    {
        int ma = INT_MAX;
        int s = 0;
        for (int y = 1; y <= 3; y++)
        {
            s += cnt[x-y+1];
            if (x-y >= 0)
                ma = min(ma, dp[x-y] + !!s);
        }
        dp[x] = ma;
    }
    set<int> used;
    for (int x = 1; x <= n; x++)
    {
        for (int y = -1; y <= 1; y++)
            if (cnt[x] && used.find(x+y) == used.end())
                used.insert(x+y), cnt[x]--;
    }
    printf("%i %lu\n", dp[n], used.size());
}