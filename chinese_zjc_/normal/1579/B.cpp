// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[55], b[55], c;
struct node
{
    int l, r, d;
};
std::vector<node> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        app.clear();
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], b[i] = a[i];
        std::sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == b[i])
                continue;
            for (int j = i + 1; j <= n; ++j)
                if (b[i] == a[j])
                {
                    app.push_back({i, j, j - i});
                    c = a[j];
                    for (int k = j; k > i; --k)
                        a[k] = a[k - 1];
                    a[i] = c;
                    break;
                }
        }
        std::cout << app.size() << std::endl;
        for (auto i : app)
            std::cout << i.l << ' ' << i.r << ' ' << i.d << std::endl;
    }
    return 0;
}