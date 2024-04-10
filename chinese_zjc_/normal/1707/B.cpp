// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
#include <windows.h>
int T, n;
std::vector<int> a;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        a.resize(n);
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        for (int i = 0; i != n - 1 && !a.empty(); ++i)
        {
            std::vector<int> b;
            if ((a.size()) != n - i)
                b.push_back(a.front());
            for (std::size_t j = 1; j != a.size(); ++j)
                if (a[j - 1] != a[j])
                    b.push_back(a[j] - a[j - 1]);
            std::sort(b.begin(), b.end());
            a = b;
        }
        std::cout << (a.empty() ? 0 : a.back()) << std::endl;
    }
    return 0;
}