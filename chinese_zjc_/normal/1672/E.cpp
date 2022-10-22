// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, ans;
int query(int y)
{
    static int x;
    std::cout << "? " << y << std::endl;
    std::cin >> x;
    return x;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    int l = 1, r = 4004000;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (query(mid) != 1)
            l = mid + 1;
        else
            r = mid;
    }
    ans = l;
    for (int i = 1; i <= n; ++i)
    {
        int w = query(l / i);
        if (w)
            ans = std::min(ans, w * (l / i));
    }
    std::cout << "! " << ans << std::endl;
    return 0;
}