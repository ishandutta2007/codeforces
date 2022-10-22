// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int max, mex, T, n, k;
std::set<int> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        max = mex = 0;
        app.clear();
        for (int i = 0, x; i != n; ++i)
            std::cin >> x, app.insert(x), max = std::max(max, x);
        bool d = false;
        while (k--)
        {
            while (app.count(mex))
                ++mex;
            if (!app.insert((max + mex + 1) / 2).second)
                break;
            max = std::max(max, *app.rbegin());
            if (mex == max)
            {
                d = true;
                break;
            }
        }
        std::cout << (d ? app.size() + k : app.size()) << std::endl;
    }
    return 0;
}