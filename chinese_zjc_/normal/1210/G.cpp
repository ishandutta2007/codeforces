// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, l[35005], r[35005];
long long ans = LLONG_MAX;
long long get(int x)
{
    long long k = 0, b = std::abs(x), llim = 0, rlim = 0;
    std::priority_queue<long long> lque;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> rque;
    for (int i = 1; i <= n; ++i)
    {
        llim += l[i] + (i == 1 ? x : 0) - (i == n ? x : 0);
        rlim += r[i] + (i == 1 ? x : 0) - (i == n ? x : 0);
        k -= 1;
        b += std::abs(llim);
        if (0 <= rlim)
        {
            if (!lque.empty() && lque.top() + llim <= 0)
                rque.push(-rlim), rque.push(-rlim);
            else
                lque.push(std::max(0ll, -llim)), lque.push(std::max(0ll, -llim));
        }
        while (int(lque.size()) + k < 0)
        {
            if (rque.empty())
                rque.push(0);
            lque.push(rque.top() + rlim - llim);
            rque.pop();
        }
        while (int(lque.size()) + k > 0)
        {
            rque.push(lque.top() + llim - rlim);
            lque.pop();
        }
#ifdef debug
        auto s = lque;
        auto t = rque;
        std::vector<int> sss;
        while (!s.empty())
        {
            sss.push_back(s.top() + llim);
            s.pop();
        }
        while (!t.empty())
        {
            sss.push_back(t.top() + rlim);
            t.pop();
        }
        std::sort(sss.begin(), sss.end());
        for (auto i : sss)
            std::cout << i << ' ';
        std::cout << std::endl;
        std::cout << llim << ' ' << rlim << ' ' << k << ' ' << b << std::endl;
#endif
    }
    long long val = b + (0 - llim) * k;
    while (!lque.empty())
    {
        if (0 > lque.top() + llim)
            val += 0 - (lque.top() + llim);
        lque.pop();
    }
    while (!rque.empty())
    {
        if (0 > rque.top() + rlim)
            val += 0 - (rque.top() + rlim);
        rque.pop();
    }
    return val;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, a; i <= n; ++i)
        std::cin >> a >> l[i] >> r[i], l[i] -= a, r[i] -= a;
    long long L = -1e12, R = +1e12;
    while (L < R)
    {
        long long mid1 = L + (R - L) / 3, mid2 = R - (R - L) / 3;
        long long v1 = get(mid1), v2 = get(mid2);
        if (v1 < v2)
            R = mid2 - 1, ans = std::min(ans, v1);
        else
            L = mid1 + 1, ans = std::min(ans, v2);
    }
    ans = std::min(ans, get(L));
    std::cout << ans << std::endl;
    // for (int i = -30; i <= +30; ++i)
    //     std::cout << i << ' ' << get(i) << std::endl;
    // std::cout << get(0) << std::endl;
    return 0;
}