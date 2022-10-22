// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
std::priority_queue<std::pair<int, int>> que;
std::vector<std::pair<int, int>> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        app.clear();
        std::cin >> n;
        for (int i = 1, x; i <= n; ++i)
        {
            std::cin >> x;
            if (x)
                que.push({x, i});
        }
        while (que.size() > 1)
        {
            std::pair<int, int> A = que.top();
            que.pop();
            std::pair<int, int> B = que.top();
            que.pop();
            app.push_back({A.second, B.second});
            if (A.first > 1)
                que.push({A.first - 1, A.second});
            if (B.first > 1)
                que.push({B.first - 1, B.second});
        }
        while (!que.empty())
            que.pop();
        std::cout << app.size() << std::endl;
        for (auto i : app)
            std::cout << i.first << ' ' << i.second << std::endl;
    }
    return 0;
}