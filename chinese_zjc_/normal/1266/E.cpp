// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, c[200005];
long long a[200005], sum;
std::map<std::pair<int, int>, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], sum += a[i];
    std::cin >> q;
    for (int i = 1, s, t, l; i <= q; ++i)
    {
        std::cin >> s >> t >> l;
        if (map.count({s, t}))
        {
            if (c[map[{s, t}]]-- <= a[map[{s, t}]])
                ++sum;
            map.erase(map.find({s, t}));
        }
        if (l)
        {
            if (++c[map[{s, t}] = l] <= a[l])
                --sum;
            map[{s, t}] = l;
        }
        std::cout << sum << std::endl;
    }
    return 0;
}