// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[105], b[105];
bool did[105];
std::map<int, int> map;
void add(int pos, int val)
{
    if (!(map[pos] += val))
        map.erase(pos);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        map.clear();
        std::fill(did + 1, did + 1 + n, false);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];
        std::sort(a + 1, a + 1 + n);
        std::sort(b + 1, b + 1 + n);
        bool ans = true;
        for (int i = 1; i <= n; ++i)
            ans &= a[i] == b[i] || a[i] + 1 == b[i];
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}