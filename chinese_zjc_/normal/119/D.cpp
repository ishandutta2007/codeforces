// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s, h, t;
int n, zts[1000005], zh[1000005], zt[1000005], zht[1000005], max[1000005], ans1 = -1, ans2 = -1;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    h = s;
    std::reverse(h.begin(), h.end());
    n = t.size();
    if (s.size() != t.size())
        return std::cout << "-1 -1" << std::endl, 0;
    for (int i = 1, l = 0, r = 0; i != n; ++i)
    {
        if (i < r)
            zt[i] = std::min(zt[i - l], r - i);
        while (i + zt[i] != n && t[i + zt[i]] == t[zt[i]])
            ++zt[i];
        if (i + zt[i] > r)
            l = i, r = i + zt[i];
    }
    for (int i = 0, l = 0, r = 0; i != n; ++i)
    {
        if (i < r)
            zts[i] = std::min(zt[i - l], r - i);
        while (i + zts[i] != n && s[i + zts[i]] == t[zts[i]])
            ++zts[i];
        if (i + zts[i] > r)
            l = i, r = i + zts[i];
    }
    for (int i = 0; i != n; ++i)
        zts[i] = std::min(zts[i], n - 1);
    for (int i = 1, l = 0, r = 0; i != n; ++i)
    {
        if (i < r)
            zh[i] = std::min(zh[i - l], r - i);
        while (i + zh[i] != n && h[i + zh[i]] == h[zh[i]])
            ++zh[i];
        if (i + zh[i] > r)
            l = i, r = i + zh[i];
    }
    for (int i = 0, l = 0, r = 0; i != n; ++i)
    {
        if (i < r)
            zht[i] = std::min(zh[i - l], r - i);
        while (i + zht[i] != n && t[i + zht[i]] == h[zht[i]])
            ++zht[i];
        if (i + zht[i] > r)
            l = i, r = i + zht[i];
    }
    max[0] = zht[0];
    for (int i = 1; i != n; ++i)
        max[i] = std::max(max[i - 1], i + zht[i]);
    for (int i = 1; i != n; ++i)
    {
        if (h[n - i] != t[n - i])
            break;
        int l = 0, r = std::min(zts[i], n - i - 1);
        if (max[r] >= n - i)
        {
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (max[mid] >= n - i)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans1 = i;
            ans2 = n - i - l;
        }
    }
    if (!~ans1)
        return std::cout << "-1 -1" << std::endl, 0;
    std::cout << ans1 - 1 << ' ' << n - ans2 << std::endl;
    return 0;
}