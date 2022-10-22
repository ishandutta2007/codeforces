// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        ans = 0;
        for (int i = 0; true;)
        {
            int nxt = std::upper_bound(a, a + n, a[i]) - a;
            if (nxt == n)
            {
                ans = std::max(ans, n - i);
                break;
            }
            int end = a[nxt], cnt = nxt - i + 1;
            do
            {
                int o = std::lower_bound(a, a + n, 2 * end - a[i]) - a;
                if (o == n)
                    end = -1;
                else
                    end = a[o], ++cnt;
            } while (~end);
            ans = std::max(ans, cnt);
            i = nxt;
        }
        std::cout << n - ans << std::endl;
    }
    return 0;
}