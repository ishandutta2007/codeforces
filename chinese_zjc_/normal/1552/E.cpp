// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[10005];
std::pair<int, int> ans[105];
std::vector<std::vector<int>> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    app.resize(n);
    for (int i = 1; i <= n * k; ++i)
    {
        std::cin >> a[i];
        app[--a[i]].push_back(i);
    }
    int t = (n - 1) / (k - 1) + 1;
    for (int i = 1; i * t <= n; ++i)
    {
        std::nth_element(app.begin(), app.begin() + t, app.end(), [&](const std::vector<int> &A, const std::vector<int> &B)
                         { return A[i] < B[i]; });
        for (int j = 0; j != t; ++j)
            ans[a[app[j].back()]] = {app[j][i - 1], app[j][i]};
        app.erase(app.begin(), app.begin() + t);
    }
    for (const auto &i : app)
        ans[a[i.back()]] = {*++i.rbegin(), i.back()};
    for (int i = 0; i != n; ++i)
        std::cout << ans[i].first << ' ' << ans[i].second << std::endl;
    return 0;
}