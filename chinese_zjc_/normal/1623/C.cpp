// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005];
long long b[200005], c[200005];
bool check(int x)
{
    std::copy(a + 1, a + 1 + n, b + 1);
    std::fill(c + 1, c + 1 + n, 0);
    for (int i = n; i >= 3; --i)
    {
        if (b[i] + c[i] < x)
            return false;
        long long d = std::min(b[i], b[i] + c[i] - x) / 3;
        b[i] -= 3 * d;
        c[i - 1] += 1 * d;
        c[i - 2] += 2 * d;
    }
    return b[1] + c[1] >= x && b[2] + c[2] >= x;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        int l = 0, r = 1000000000;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        std::cout << l << std::endl;
    }
    return 0;
}