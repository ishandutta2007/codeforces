// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
std::pair<int, int> dp[1 << 14];
bool able[14][14];
int n, m, from[1 << 14][14], vis[1 << 14], can[1 << 14];
std::vector<std::pair<int, int>> ans;
template <class T>
void cmin(T &A, T B) { A = std::min(A, B); }
void print(int now)
{
    if (now == 1 << n >> 1)
        return;
    int i = dp[now].second, t = now ^ i;
    if (t & (t - 1))
    {
        std::memset(from, -1, sizeof(from));
        std::queue<std::pair<int, int>> que;
        for (int j = 0; j != n; ++j)
            if (t >> j & 1)
                for (int k = 0; k != n; ++k)
                    if (i >> k & 1 && able[j][k])
                    {
                        que.push({1 << j, j}), from[1 << j][j] = k;
                        break;
                    }
        // std::cout << "?" << std::endl;
        while (!que.empty())
        {
            std::pair<int, int> now = que.front();
            que.pop();
            // std::cout << i << ' ' << t << ' ' << now.first << ' ' << now.second << std::endl;
            for (int j = 0; j != n; ++j)
                if (able[now.second][j])
                {
                    if (now.first == t && i >> j & 1)
                    {
                        ans.push_back({now.second, j});
                        int cur = t, p = now.second;
                        while (cur)
                        {
                            int lst = from[cur][p];
                            ans.push_back({lst, p});
                            cur ^= 1 << p;
                            p = lst;
                        }
                        goto next;
                    }
                    if (t >> j & 1 && !~from[now.first | 1 << j][j])
                        que.push({now.first | 1 << j, j}), from[now.first | 1 << j][j] = now.second;
                }
        }
    }
    else
    {
        int v = __builtin_ctz(t);
        for (int j = 0; j != n; ++j)
            for (int k = j + 1; k != n; ++k)
                if (i >> j & 1 && i >> k & 1 && able[j][v] && able[k][v])
                {
                    ans.push_back({j, v});
                    ans.push_back({k, v});
                    goto next;
                }
        exit(114514);
    }
next:
    print(i);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0, x, y; i != m; ++i)
    {
        std::cin >> x >> y;
        --x;
        --y;
        able[x][y] = able[y][x] = true;
        can[1 << x] |= 1 << y;
        can[1 << y] |= 1 << x;
    }
    for (int i = 1; i != 1 << n; ++i)
        can[i] = can[i & (i - 1)] | can[i & -i];
    for (int i = 0; i != 1 << n; ++i)
        dp[i].first = INT_MAX / 2;
    dp[1 << n >> 1] = {0, 0};
    for (int i = 1 << n >> 1; i != 1 << n; ++i)
    {
        for (int j = 0; j != n; ++j)
            for (int k = j + 1; k != n; ++k)
                if (i >> j & 1 && i >> k & 1)
                    for (int l = 0; l != n; ++l)
                        if (~i >> l & 1 && able[j][l] && able[k][l])
                            cmin(dp[i | 1 << l], {dp[i].first + 1, i});
        std::vector<int> sta;
        for (int j = ((1 << n) - 1) ^ i; j; j = (j - 1) & ~i)
        {
            sta.push_back(j);
            vis[j] = 0;
        }
        for (int j = 0; j != n; ++j)
            if (~i >> j & 1 && can[i] >> j & 1)
                vis[1 << j] = 1 << j;
        std::reverse(sta.begin(), sta.end());
        for (auto j : sta)
        {
            for (int k = 0; k != n; ++k)
                if (~j >> k & 1 && can[vis[j]] >> k & 1)
                {
                    if (i >> k & 1)
                    {
                        if (j & (j - 1))
                            cmin(dp[i | j], {dp[i].first + 1, i});
                    }
                    else
                        vis[j | 1 << k] |= 1 << k;
                }
        }
        // while (!que.empty())
        // {
        //     std::pair<int, int> now = que.front();
        //     que.pop();
        //     for (int j = 0; j != n; ++j)
        //         if (~now.first >> j & 1 && able[now.second][j])
        //         {
        //             if (i >> j & 1)
        //             {
        //                 if (__builtin_popcount(now.first) > 1)
        //                     cmin(dp[i | now.first], {dp[i].first + __builtin_popcount(now.first) + 1, i});
        //             }
        //             else if (vis[now.first | 1 << j][j] != i)
        //                 que.push({now.first | 1 << j, j}), vis[now.first | 1 << j][j] = i;
        //         }
        // }
    }
    // std::cout << dp[0b11110].first << ' ' << dp[0b11110].second << std::endl;
    // std::cout << dp[(1 << n) - 1].first << ' ' << dp[(1 << n) - 1].second << std::endl;
    print((1 << n) - 1);
    std::cout << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i.first + 1 << ' ' << i.second + 1 << std::endl;
    return 0;
}