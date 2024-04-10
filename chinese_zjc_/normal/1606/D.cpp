// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m;
struct node
{
    int lmin, lmax, rmin, rmax, p;
    friend node operator+(const node &A, const node &B)
    {
        return {std::min(A.lmin, B.lmin), std::max(A.lmax, B.lmax), std::min(A.rmin, B.rmin), std::max(A.rmax, B.rmax)};
    }
};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cin >> a[i][j];
        std::vector<std::vector<int>>
            premin(n + 1, std::vector<int>(m + 1)),
            premax(n + 1, std::vector<int>(m + 1)),
            sufmin(n + 1, std::vector<int>(m + 1)),
            sufmax(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; ++i)
        {
            premin[i][1] = a[i][1];
            for (int j = 2; j <= m; ++j)
                premin[i][j] = std::min(premin[i][j - 1], a[i][j]);
            premax[i][1] = a[i][1];
            for (int j = 2; j <= m; ++j)
                premax[i][j] = std::max(premax[i][j - 1], a[i][j]);
            sufmin[i][m] = a[i][m];
            for (int j = m - 1; j >= 1; --j)
                sufmin[i][j] = std::min(sufmin[i][j + 1], a[i][j]);
            sufmax[i][m] = a[i][m];
            for (int j = m - 1; j >= 1; --j)
                sufmax[i][j] = std::max(sufmax[i][j + 1], a[i][j]);
        }
        for (int i = 1; i < m; ++i)
        {
            std::vector<node> p;
            for (int j = 1; j <= n; ++j)
                p.push_back({premin[j][i], premax[j][i], sufmin[j][i + 1], sufmax[j][i + 1], j});
            std::sort(p.begin(), p.end(), [&](const node &A, const node &B)
                      { return A.lmax < B.lmax; });
            std::vector<node> suf(n);
            node pre = p[0];
            suf[n - 1] = p[n - 1];
            for (int j = n - 2; j >= 0; --j)
                suf[j] = suf[j + 1] + p[j];
            for (int j = 1; j < n; pre = pre + p[j++])
            {
                if (pre.lmax < suf[j].lmin && suf[j].rmax < pre.rmin)
                {
                    std::cout << "YES" << std::endl;
                    std::vector<char> num(n + 1);
                    for (int k = 0; k != j; ++k)
                        num[p[k].p] = 'B';
                    for (int k = j; k != n; ++k)
                        num[p[k].p] = 'R';
                    for (int i = 1; i <= n; ++i)
                        std::cout << num[i];
                    std::cout << ' ' << i << std::endl;
                    goto nextcase;
                }
            }
        }
        std::cout << "NO" << std::endl;
    nextcase:;
    }
    return 0;
}