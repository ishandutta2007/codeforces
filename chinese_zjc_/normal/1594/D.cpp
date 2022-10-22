// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, fa[400005], siz[400005], ans;
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int A, int B) { fa[find(A)] = find(B); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n * 2; ++i)
            fa[i] = i, siz[i] = 0;
        for (int i = 1; i <= m; ++i)
        {
            static int a, b;
            static std::string c;
            std::cin >> a >> b >> c;
            if (a < b)
                std::swap(a, b);
            if (c == "crewmate")
                merge(a, b), merge(a + n, b + n);
            else
                merge(a, b + n), merge(a + n, b);
        }
        for (int i = 1; i <= n; ++i)
            if (find(i) == find(i + n))
            {
                std::cout << -1 << std::endl;
                goto next;
            }
        for (int i = 1; i <= n; ++i)
            ++siz[find(i + n)];
        ans = 0;
        for (int i = 1; i <= n; ++i)
            if (find(i) == i && find(i + n) == i + n)
                ans += std::max(siz[find(i)], siz[find(i + n)]);
        std::cout << ans << std::endl;
    next:;
    }
    return 0;
}