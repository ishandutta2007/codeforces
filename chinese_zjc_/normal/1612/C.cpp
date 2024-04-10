// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T;
long long n, x;
long long presum(long long k) { return k * (k + 1) / 2; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> x;
        if (presum(n) < x)
        {
            long long l = 0, r = n - 1;
            while (l < r)
            {
                long long mid = (l + r) / 2;
                if (presum(n) + presum(n - 1) - presum(n - 1 - mid) < x)
                    l = mid + 1;
                else
                    r = mid;
            }
            std::cout << n + l << std::endl;
        }
        else
        {
            long long l = 1, r = n;
            while (l < r)
            {
                long long mid = (l + r) / 2;
                if (presum(mid) < x)
                    l = mid + 1;
                else
                    r = mid;
            }
            std::cout << l << std::endl;
        }
    }
    return 0;
}