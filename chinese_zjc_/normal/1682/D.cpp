// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
char c[200005];
std::vector<std::pair<int, int>> to;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> c[i];
        int cnt = std::count(c, c + n, '1');
        if (cnt & 1 || cnt == 0)
            std::cout << "NO" << std::endl;
        else
        {
            to.clear();
            std::cout << "YES" << std::endl;
            int p = 0;
            for (int i = 0; i != n; ++i)
                if (c[(i - 1 + n) % n] == '1' && c[i] == '0')
                {
                    p = i;
                    break;
                }
            for (int i = 1; i != n; ++i)
            {
                to.push_back({p, (p + i) % n});
                while (c[(p + i) % n] == '0')
                    to.push_back({(p + i) % n, (p + i + 1) % n}), ++i;
            }
            for (auto i : to)
                std::cout << i.first + 1 << ' ' << i.second + 1 << std::endl;
        }
    }
    return 0;
}