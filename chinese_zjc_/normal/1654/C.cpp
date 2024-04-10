// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long a[200005], sum;
std::map<long long, int> app;
bool bad;
void work(long long v)
{
    if (bad)
        return;
    if (app.count(v))
    {
        if (--app[v] == 0)
            app.erase(v);
        return;
    }
    if (v == 1)
    {
        bad = true;
        return;
    }
    work(v / 2);
    work((v + 1) / 2);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], sum += a[i], ++app[a[i]];
        bad = false;
        work(sum);
        std::cout << (app.empty() ? "YES" : "NO") << '\n';
        sum = 0;
        app.clear();
    }
    return 0;
}