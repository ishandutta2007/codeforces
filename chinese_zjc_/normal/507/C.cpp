// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long x, n, h, ans;
void work(long long x, long long depth, bool nxt)
{
    if (n >> (h - depth) != x)
    {
        ans += (1ll << (h - depth + 1)) - 1;
        return;
    }
    if (depth == h)
    {
        std::cout << ans << std::endl;
        exit(0);
    }
    ++ans;
    work(x << 1 | nxt, depth + 1, !nxt);
    work(x << 1 | !nxt, depth + 1, nxt);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> h >> n;
    n = 1ll << h | (n - 1);
    work(1, 0, false);
    return 0;
}