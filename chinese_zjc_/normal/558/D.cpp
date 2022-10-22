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
std::set<std::pair<int, int>> ans;
int h, q;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> h >> q;
    ans.insert({1ll << (h - 1), (1ll << h) - 1});
    for (int i = 1; i <= q; ++i)
    {
        static int d, l, r, a;
        std::cin >> d >> l >> r >> a;
        while (d < h)
        {
            l = l << 1;
            r = r << 1 | 1;
            ++d;
        }
        // std::cout << l << ' ' << r << std::endl;
        if (a)
        {
            std::set<std::pair<int, int>>::iterator iter = ans.begin();
            while (iter != ans.end() && iter->second < l)
            {
                ans.erase(iter++);
            }
            if (iter != ans.end() && iter->first < l && iter->second >= l)
            {
                std::pair<int, int> tmp = *iter;
                ans.erase(iter);
                if (tmp.second > r)
                    tmp.second = r;
                tmp.first = l;
                ans.insert(tmp);
            }
            iter = ans.upper_bound({r, INF});
            if (iter != ans.begin())
            {
                --iter;
                if (iter->first <= r && iter->second > r)
                {
                    std::pair<int, int> tmp = *iter;
                    ans.erase(iter++);
                    tmp.second = r;
                    ans.insert(tmp);
                }
                else
                    ++iter;
            }
            while (iter != ans.end())
            {
                ans.erase(iter++);
            }
        }
        else
        {
            std::set<std::pair<int, int>>::iterator iter = ans.lower_bound({l, -INF});
            if (iter != ans.begin())
            {
                --iter;
                if (iter->second >= l)
                {
                    std::pair<int, int> tmp = *iter;
                    ans.erase(iter++);
                    if (tmp.second > r)
                        ans.insert({r + 1, tmp.second});
                    tmp.second = l - 1;
                    ans.insert(tmp);
                }
                else
                    ++iter;
            }
            while (iter != ans.end() && iter->second <= r)
            {
                ans.erase(iter++);
            }
            if (iter != ans.end() && iter->first <= r)
            {
                std::pair<int, int> tmp = *iter;
                ans.erase(iter);
                tmp.first = r + 1;
                ans.insert(tmp);
            }
        }
        // for (auto i : ans)
        //     std::cout << '[' << i.first << ',' << i.second << ']' << std::endl;
    }
    int tot = 0;
    for (auto i : ans)
        tot += i.second - i.first + 1;
    switch (tot)
    {
    case 0:
        std::cout << "Game cheated!" << std::endl;
        break;
    case 1:
        std::cout << ans.begin()->first << std::endl;
        break;
    default:
        std::cout << "Data not sufficient!" << std::endl;
        break;
    }
    return 0;
}