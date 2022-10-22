//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
const int xx[] = {0, +1, 0, -1},
          yy[] = {-1, 0, +1, 0};
int n, m, d;
char c[1005][1005];
std::set<std::pair<int, int>> mouse;
std::set<std::pair<int, int>> getmap(std::pair<int, int> sta)
{
#ifdef debug
    std::cout << sta.first << ' ' << sta.second << std::endl;
#endif
    std::queue<std::pair<int, int>> que[2];
    std::set<std::pair<int, int>> res;
    que->push(sta);
    res.insert(sta);
    for (int i = 0; i != d; ++i)
        while (!que[i & 1].empty())
        {
            std::pair<int, int> now = que[i & 1].front();
            que[i & 1].pop();
            for (int j = 0; j != 4; ++j)
            {
                std::pair<int, int> to = {now.first + xx[j], now.second + yy[j]};
                if (c[to.first][to.second] != 'X' && !res.count(to))
                    res.insert(to), que[~i & 1].push(to);
            }
        }
    return res;
}
std::set<std::pair<int, int>> operator-(const std::set<std::pair<int, int>> &A, const std::set<std::pair<int, int>> &B)
{
    std::set<std::pair<int, int>> res;
    std::set<std::pair<int, int>>::iterator first1 = A.begin(), first2 = B.begin();
    while (first1 != A.end() && first2 != B.end())
        if (*first1 < *first2)
        {
            res.insert(res.end(), *first1);
            ++first1;
        }
        else if (*first2 < *first1)
            ++first2;
        else
        {
            ++first1;
            ++first2;
        }
    res.insert(first1, A.end());
#ifdef debug
    for (auto i : res)
        std::cout << i.first << ' ' << i.second << "?" << std::endl;
#endif
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
#ifndef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::cin >> n >> m >> d;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            std::cin >> c[i][j];
            if (c[i][j] == 'R')
                mouse.insert({i, j});
        }
    if (mouse.size() > 200)
        return std::cout << -1 << std::endl, 0;
    std::set<std::pair<int, int>> can1 = getmap(*mouse.begin());
#ifdef debug
    for (auto j : mouse)
        std::cout << j.first << ' ' << j.second << std::endl;
    for (auto j : can1)
        std::cout << j.first << ' ' << j.second << std::endl;
#endif
    for (auto i : can1)
    {
        std::set<std::pair<int, int>> left1 = mouse - getmap(i);
        if (left1.empty())
        {
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= m; ++k)
                    if ((i.first != j || i.second != k) && c[j][k] != 'X')
                        return std::cout << i.first << ' ' << i.second << ' ' << j << ' ' << k << std::endl, 0;
        }
        std::set<std::pair<int, int>> can2 = getmap(*left1.begin());
        for (auto j : can2)
        {
            std::set<std::pair<int, int>> left2 = left1 - getmap(j);
            if (left2.empty())
                return std::cout << i.first << ' ' << i.second << ' ' << j.first << ' ' << j.second << std::endl, 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}