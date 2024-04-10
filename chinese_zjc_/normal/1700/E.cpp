// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int xx[5] = {0, -1, 0, +1, 0}, yy[5] = {-1, 0, +1, 0, 0};
int n, m, a[400005], X, Y, cnt;
std::vector<std::pair<int, int>> ans;
int id(int x, int y) { return x * m + y; }
bool check(int x, int y)
{
    if (a[id(x, y)] == 1)
        return true;
    bool flag = false;
    for (int k = 0; k != 4; ++k)
        if (x + xx[k] >= 0 && x + xx[k] < n && y + yy[k] >= 0 && y + yy[k] < m)
            flag |= a[id(x + xx[k], y + yy[k])] < a[id(x, y)];
    return flag;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            std::cin >> a[id(i, j)];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            if (!check(i, j))
                X = i, Y = j, ++cnt;
    if (!cnt)
        return std::cout << 0 << std::endl, 0;
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != m; ++j)
        {
            for (int k = 0; k != 5; ++k)
                if (X + xx[k] >= 0 && X + xx[k] < n && Y + yy[k] >= 0 && Y + yy[k] < m)
                {
                    int tmp = cnt, A = X + xx[k], B = Y + yy[k];
                    std::vector<std::pair<int, int>> vec;
                    for (int l = 0; l != 5; ++l)
                        if (i + xx[l] >= 0 && i + xx[l] < n && j + yy[l] >= 0 && j + yy[l] < m)
                            vec.push_back({i + xx[l], j + yy[l]});
                    for (int l = 0; l != 5; ++l)
                        if (A + xx[l] >= 0 && A + xx[l] < n && B + yy[l] >= 0 && B + yy[l] < m)
                            vec.push_back({A + xx[l], B + yy[l]});
                    std::sort(vec.begin(), vec.end());
                    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
                    for (auto l : vec)
                        tmp -= !check(l.first, l.second);
                    std::swap(a[id(i, j)], a[id(A, B)]);
                    for (auto l : vec)
                        tmp += !check(l.first, l.second);
                    if (tmp == 0)
                        ans.push_back(std::minmax(id(i, j), id(A, B)));
                    std::swap(a[id(i, j)], a[id(A, B)]);
                }
        }
    }
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
    if (ans.empty())
        std::cout << 2 << std::endl;
    else
        std::cout << 1 << ' ' << ans.size() << std::endl;
    return 0;
}