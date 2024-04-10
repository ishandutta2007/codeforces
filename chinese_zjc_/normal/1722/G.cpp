// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n;
std::set<int> g;
std::mt19937 Rand(std::chrono::system_clock::now().time_since_epoch().count());
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        while (int(g.size()) != n)
        {
            g.clear();
            int sum = 0;
            for (int i = 1, x; i != n; ++i)
            {
                do
                    x = Rand() >> 1;
                while (g.count(x));
                g.insert(x);
                sum ^= x;
            }
            g.insert(sum);
        }
        for (auto i : g)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}