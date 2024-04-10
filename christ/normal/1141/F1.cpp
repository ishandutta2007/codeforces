#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%i", &n);
    vector<int> arr(n);
    for (auto &x : arr)
        scanf("%i", &x);
    map<long long, map<int, pair<int, int>>> dp;
    map<long long, int> bst;
    long long ans = -1, ansi = 0, anscur = 0;
    for (int x = 0; x < n; x++)
    {
        long long cur = 0;
        for (int y = x; y >= 0; y--)
        {
            cur += arr[y];
            if (dp[cur].count(x))
                continue;
            auto it = dp[cur].upper_bound(y-1);
            if (it != dp[cur].begin())
            {
                --it;
                int cc = (it->second).first + 1;
                if (cc > bst[cur])
                {
                    dp[cur][x] = {cc, it->first};
                    bst[cur] = cc;
                }
            }
            else if (1 > bst[cur])
            {
                dp[cur][x] = {1, -1};
                bst[cur] = 1;
            }
            if (dp[cur].count(x) && dp[cur][x].first > ans)
                ans = dp[cur][x].first, ansi = x, anscur = cur;
        }
    }
    printf("%lli\n", ans);
    int p = ansi;
    while (~p)
    {
        int l = p-1;
        long long cc = arr[p];
        for (; cc != anscur; l--)
            cc += arr[l];
        assert(l+2 <= p+1);
        printf("%i %i\n", l+2, p+1);
        p = dp[anscur][p].second;
    }
}