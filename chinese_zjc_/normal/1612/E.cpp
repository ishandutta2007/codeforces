// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int lim = 60;
int n, m[200005], k[200005];
long long C[lim + 5][lim + 5];
double bes, val[200005], P[lim + 5][lim + 5];
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 0; i <= lim; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 1; i <= lim; ++i)
        for (int j = 1; j <= lim; ++j)
            P[i][j] = j <= i ? 1.0 * C[i - 1][j - 1] / C[i][j] : 1;
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> m[i] >> k[i];
    for (int cho = 1; cho <= lim; ++cho)
    {
        std::priority_queue<std::pair<double, int>> que;
        std::fill(val + 1, val + 1 + 200000, 0);
        for (int i = 1; i <= n; ++i)
            val[m[i]] += P[cho][k[i]];
        for (int i = 1; i <= 200000; ++i)
            que.push({val[i], i});
        std::vector<int> sol;
        double now = 0;
        for (int i = 1; i <= cho; ++i)
            now += que.top().first, sol.push_back(que.top().second), que.pop();
        if (now > bes)
            ans = sol, bes = now;
    }
    std::cout << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}