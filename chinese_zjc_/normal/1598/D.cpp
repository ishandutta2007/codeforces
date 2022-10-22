// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
long long ans;
std::map<int, int> mapA, mapB;
struct node
{
    int a, b;
} a[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        std::cin >> n;
        for (int i = 0; i != n; ++i)
            std::cin >> a[i].a >> a[i].b;
        mapA.clear();
        for (int i = 0; i != n; ++i)
            ++mapA[a[i].a];
        mapB.clear();
        for (int i = 0; i != n; ++i)
            ++mapB[a[i].b];
        for (int i = 0; i != n; ++i)
            ans += (mapA[a[i].a] - 1ll) * (mapB[a[i].b] - 1ll);
        std::cout << n * (n - 1ll) * (n - 2ll) / 6ll - ans << std::endl;
    }
    return 0;
}