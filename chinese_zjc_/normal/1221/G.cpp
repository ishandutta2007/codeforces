// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const long long INF = LLONG_MAX >> 1;
int n, m, mid, to[40], sum[1ll << 20], ans, vis, color, tmp, cnt, no;
template <class FUN>
void dfs1(int now, int can, int cho, int lim, FUN F)
{
    if (now == lim)
    {
        F(can, cho);
        return;
    }
    if (can >> now & 1)
        dfs1(now + 1, can & ~to[now], cho | 1ll << now, lim, F);
    dfs1(now + 1, can, cho, lim, F);
}
bool dfs2(int now)
{
    bool flag = true;
    for (int i = 0; i != n; ++i)
        if (to[now] >> i & 1)
        {
            if (~vis >> i & 1)
                vis |= 1ll << i, color |= (~color >> now & 1) << i, flag &= dfs2(i);
            else
                flag &= (color >> i & 1) ^ (color >> now & 1);
        }
    return flag;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    ans = 1ll << n;
    for (int i = 0; i != m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        --x, --y;
        to[x] |= 1ll << y;
        to[y] |= 1ll << x;
    }
    mid = n >> 1;
    dfs1(0, (1ll << n) - 1, 0, mid, [&](const int can, const int &cho)
         { ++sum[can >> mid]; });
    for (int i = 0; i != n - mid; ++i)
        for (int j = 1ll << i; j < 1ll << (n - mid); j = (j + 1) | 1ll << i)
            sum[j ^ 1ll << i] += sum[j];
    dfs1(mid, (1ll << n) - 1, 0, n, [&](const int can, const int &cho)
         { ans -= sum[cho >> mid] * 2; });
    tmp = 1;
    for (int i = 0; i != n; ++i)
        if (~vis >> i & 1)
        {
            ++cnt;
            if (dfs2(i))
                tmp *= 2;
            else
                tmp = 0;
        }
    ans -= 1ll << cnt;
    ans += tmp;
    no = std::count(to, to + n, 0);
    ans += 1ll << no << 1;
    ans -= (cnt == no) * 1ll << n;
    std::cout << ans << std::endl;
    return 0;
}