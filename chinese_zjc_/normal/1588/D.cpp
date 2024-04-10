// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const unsigned B = 1 << 10;
unsigned map[128], T, n, dp[52][B], from[52][B], ans, app[52][10][2];
std::string a[10];
std::priority_queue<std::pair<unsigned, unsigned>> que;
void print(unsigned now)
{
    if (~now)
    {
        print(from[now / B][now % B]);
        std::cout << char(now / B < 26 ? now / B + 'A' : now / B - 26 + 'a');
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (unsigned i = 0; i != 26; ++i)
        map[i + 'A'] = i, map[i + 'a'] = i + 26;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        memset(app, -1, sizeof(app));
        memset(from, -1, sizeof(from));
        memset(dp, 0, sizeof(dp));
        for (unsigned i = 0; i != n; ++i)
        {
            std::cin >> a[i];
            for (unsigned j = 0; j != unsigned(a[i].size()); ++j)
                (~app[map[a[i][j]]][i][0] ? app[map[a[i][j]]][i][1] : app[map[a[i][j]]][i][0]) = j;
        }
        ans = -1;
        for (unsigned i = 0; i != 52; ++i)
        {
            dp[i][0] = 1;
            for (unsigned j = 0; j != n; ++j)
                if (!~app[i][j][0])
                    dp[i][0] = 0;
            if (dp[i][0])
                que.push({dp[i][0], i * B});
        }
        while (!que.empty())
        {
            std::pair<unsigned, unsigned> now = que.top();
            que.pop();
            if (now.first ^ dp[now.second / B][now.second % B])
                continue;
            if (!~ans || now.first > dp[ans / B][ans % B])
                ans = now.second;
            for (unsigned i = 0; i != 52; ++i)
            {
                unsigned nxt = 0;
                for (unsigned j = 0; j != n; ++j)
                    if (~app[i][j][0] && app[i][j][0] > app[now.second / B][j][now.second >> j & 1])
                        continue;
                    else if (~app[i][j][1] && app[i][j][1] > app[now.second / B][j][now.second >> j & 1])
                        nxt |= 1 << j;
                    else
                        nxt = -1;
                if (~nxt && dp[i][nxt] <= now.first)
                    que.push({dp[i][nxt] = now.first + 1, i * B + nxt}), from[i][nxt] = now.second;
            }
        }
        std::cout << (~ans ? dp[ans / B][ans % B] : 0) << std::endl;
        print(ans);
        std::cout << std::endl;
    }
    return 0;
}