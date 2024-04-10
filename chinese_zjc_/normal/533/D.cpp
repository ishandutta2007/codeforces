// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
long long p[1000005], v[1000005], r[1000005], l[1000005], ans = LLONG_MAX;
std::deque<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i <= n + 1; ++i)
        std::cin >> p[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i], v[i] <<= 1;
    que.clear();
    que.push_back(0);
    r[0] = p[n + 1];
    r[n + 1] = p[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        while (r[que.back()] < p[i])
            que.pop_back();
        r[i] = p[que.back()] + v[i];
        if (r[i] < p[i])
            continue;
        while (!que.empty() && r[que.back()] <= r[i])
            que.pop_back();
        que.push_back(i);
    }
    if (*std::max_element(r + 1, r + 1 + n) >= p[n + 1])
        return std::cout << 0 << std::endl, 0;
    que.clear();
    que.push_back(n + 1);
    l[0] = p[0];
    l[n + 1] = p[0];
    for (int i = n; i >= 1; --i)
    {
        while (l[que.back()] > p[i])
            que.pop_back();
        l[i] = p[que.back()] - v[i];
        if (l[i] > p[i])
            continue;
        while (!que.empty() && l[que.back()] >= l[i])
            que.pop_back();
        que.push_back(i);
    }
    que.clear();
    que.push_back(0);
    // for (int i = 0; i <= n + 1; ++i)
    //     std::cout << std::setw(10) << (l[i] < p[i] ? l[i] : -1);
    // std::cout << std::endl;
    // for (int i = 0; i <= n + 1; ++i)
    //     std::cout << std::setw(10) << (p[i] < r[i] ? r[i] : -1);
    // std::cout << std::endl;
    for (int i = 1; i <= n + 1; ++i)
    {
        if (l[i] < p[i])
        {
            // std::cout << i << std::endl;
            // for (auto j : que)
            //     std::cout << j << ' ' << p[j] << ' ' << r[j] << std::endl;
            while (!que.empty() && r[que.front()] >= l[i])
                ans = std::min(ans, p[i] - p[que.front()]), que.pop_front();
        }
        if (p[i] < r[i])
        {
            if (i == n + 1)
                break;
            while (!que.empty() && r[que.back()] <= r[i])
                que.pop_back();
            que.push_back(i);
        }
    }
    std::cout << ans / 2 << (ans & 1 ? ".5" : "") << std::endl;
    return 0;
}