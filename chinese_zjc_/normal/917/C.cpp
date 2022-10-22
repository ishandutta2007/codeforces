// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define popcount __builtin_popcountll
int pos, x, k, n, q;
long long cost[30][1 << 8][1 << 8], cur[1 << 8], v[10];
std::pair<int, long long> extra[25];
std::map<int, long long> add;
void cmin(long long &A, long long B) { A = std::min(A, B); }
void moveto(int end)
{
    for (int i = 30; i--;)
        if (end - pos >= 1 << i)
        {
            long long tmp[1 << 8];
            memset(tmp, 0x3f, sizeof(tmp));
            for (int j = 0; j != 1 << k; ++j)
                for (int l = 0; l != 1 << k; ++l)
                    cmin(tmp[l], cur[j] + cost[i][j][l]);
            std::swap(tmp, cur);
            pos += 1 << i;
        }
}
void boomto(int end)
{
    while (pos < end)
    {
        long long tmp[1 << 8];
        memset(tmp, 0x3f, sizeof(tmp));
        for (int i = 0; i != 1 << k; ++i)
            if (i & 1)
            {
                for (int j = 1; j <= k; ++j)
                    if (~i >> j & 1)
                    {
                        auto iter = add.find(pos + j);
                        cmin(tmp[(i | 1 << j) >> 1], cur[i] + v[j] + (iter == add.end() ? 0 : iter->second));
                    }
            }
            else
                cmin(tmp[i >> 1], cur[i]);
        std::swap(tmp, cur);
        ++pos;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> x >> k >> n >> q;
    for (int i = 1; i <= k; ++i)
        std::cin >> v[i];
    for (int i = 0; i != q; ++i)
        std::cin >> extra[i].first >> extra[i].second, add[--extra[i].first] += extra[i].second;
    std::sort(extra, extra + q);
    memset(cost, 0x3f, sizeof(cost));
    for (int i = 0; i != 1 << k; ++i)
        if (i & 1)
            for (int j = 1; j <= k; ++j)
            {
                if (~i >> j & 1)
                    cmin(cost[0][i][(i | 1 << j) >> 1], v[j]);
            }
        else
            cost[0][i][i >> 1] = 0;
    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 0; j != 1 << k; ++j)
            if (popcount(j) == x)
                for (int l = 0; l != 1 << k; ++l)
                    if (popcount(l) == x)
                        for (int o = 0; o != 1 << k; ++o)
                            if (popcount(o) == x)
                                cmin(cost[i][j][l], cost[i - 1][j][o] + cost[i - 1][o][l]);
    memset(cur, 0x3f, sizeof(cur));
    cur[(1 << x) - 1] = 0;
    for (int i = 0; i != q; ++i)
    {
        moveto(extra[i].first - k);
        boomto(std::min(n - x, extra[i].first));
    }
    moveto(n - x);
    std::cout << cur[(1 << x) - 1] << std::endl;
    return 0;
}