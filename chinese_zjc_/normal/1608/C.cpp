// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
struct node
{
    int x, y;
} a[100005];
std::multimap<int, int, std::greater<int>> X, Y;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i].x;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i].y;
        for (int i = 1; i <= n; ++i)
            X.insert({a[i].x, i}), Y.insert({a[i].y, i});
        int yl = a[X.begin()->second].y, xl = a[Y.begin()->second].x;
        while (true)
        {
            bool flag = false;
            if (!X.empty() && X.begin()->first > xl)
                yl = std::min(yl, a[X.begin()->second].y), X.erase(X.begin()), flag = true;
            if (!Y.empty() && Y.begin()->first > yl)
                xl = std::min(xl, a[Y.begin()->second].x), Y.erase(Y.begin()), flag = true;
            if (!flag)
                break;
        }
        for (int i = 1; i <= n; ++i)
            std::cout << (a[i].x >= xl || a[i].y >= yl);
        std::cout << std::endl;
        X.clear();
        Y.clear();
    }
    return 0;
}