// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long T, n, s, max, a[1000005], sum, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        max = 0;
        sum = 0;
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            max = a[max] > a[i] ? max : i;
            sum += a[i];
            if (sum - a[max] > s)
            {
                for (int j = i + 1; j <= n; ++j)
                    std::cin >> a[j];
                break;
            }
            ans = max;
        }
        std::cout << (sum <= s ? 0 : ans) << std::endl;
    }
    return 0;
}