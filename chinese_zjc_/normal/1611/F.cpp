// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::pair<int, int> ans;
long long s, a[200005], sum[200005];
std::map<long long, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + a[i];
        ans = {0, 0};
        for (int i = 1; i <= n; ++i)
        {
            map.insert({-sum[i - 1], i});
            while (!map.empty() && sum[i] + s + map.begin()->first < 0)
            {
                if (i - map.begin()->second > ans.second - ans.first)
                    ans.first = map.begin()->second, ans.second = i;
                map.erase(map.begin());
            }
        }
        while (!map.empty())
        {
            if (n + 1 - map.begin()->second > ans.second - ans.first)
                ans.first = map.begin()->second, ans.second = n + 1;
            map.erase(map.begin());
        }
        if (ans.first == 0)
            std::cout << -1 << std::endl;
        else
            std::cout << ans.first << ' ' << ans.second - 1 << std::endl;
    }
    return 0;
}