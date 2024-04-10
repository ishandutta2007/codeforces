// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::deque<int> p, a, q;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        a.assign(n, 0);
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        if (a.front() != n && a.back() != n)
        {
            std::cout << -1 << std::endl;
            continue;
        }
        else if (a.front() == n)
        {
            std::cout << n;
            for (std::deque<int>::reverse_iterator i = a.rbegin(); i + 1 != a.rend(); ++i)
                std::cout << ' ' << *i;
            std::cout << std::endl;
        }
        else
        {
            for (std::deque<int>::reverse_iterator i = a.rbegin() + 1; i != a.rend(); ++i)
                std::cout << *i << ' ';
            std::cout << n << std::endl;
        }
    }
    return 0;
}