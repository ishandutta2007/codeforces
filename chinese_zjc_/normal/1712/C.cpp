// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, a[100005], suf, max, cnt, ans;
std::vector<int> app[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], app[a[i]].push_back(i);
        suf = n;
        while (suf > 1 && a[suf - 1] <= a[suf])
            --suf;
        max = 0;
        cnt = 0;
        ans = 0;
        for (int i = 1; i <= n && !(max == cnt && max + 1 >= suf); ++i)
            if (i == app[a[i]].front())
            {
                cnt += app[a[i]].size();
                ++ans;
                max = std::max(max, app[a[i]].back());
            }
        for (int i = 1; i <= n; ++i)
            app[i].clear();
        std::cout << ans << std::endl;
    }
    return 0;
}