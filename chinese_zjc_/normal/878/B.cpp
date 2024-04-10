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
int n, k, m, c[100005];
std::list<int> front, back, mid;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> m;
    // bool flag = 99999 == n && k == 1000 && m == 1000000000;
    for (int i = 1, app = 0; i <= n; ++i)
    {
        static int v;
        std::cin >> v;
        // if (flag && i > 91912 && (mid.empty() || mid.back() != v))
        //     std::cout << i << " " << v << std::endl;
        if (!mid.empty() && mid.back() == v)
            ++app;
        else
            app = 1;
        mid.push_back(v);
        if (app == k)
        {
            while (app--)
                mid.pop_back();
            app = 0;
            if (!mid.empty())
            {
                for (std::list<int>::reverse_iterator i = mid.rbegin(); i != mid.rend(); ++i)
                    if (*i == mid.back())
                        ++app;
                    else
                        break;
            }
        }
    }
    for (auto i : mid)
        ++c[i];
    while (!mid.empty() && mid.front() == mid.back() && c[mid.front()] != (int)mid.size())
    {
        int b = 0, f = 0, v = mid.front();
        for (std::list<int>::reverse_iterator i = mid.rbegin(); i != mid.rend(); ++i)
            if (*i == v)
                ++b;
            else
                break;
        for (std::list<int>::iterator i = mid.begin(); i != mid.end(); ++i)
            if (*i == v)
                ++f;
            else
                break;
        for (int i = (b + f) / k * k; i--;)
            if (b)
                mid.pop_back(), back.push_front(v), --c[v], --b;
            else
                mid.pop_front(), front.push_back(v), --c[v], --f;
        if (b || f)
            break;
        // if (flag)
        //     std::cout << "here good" << std::endl;
    }
    if (!mid.empty() && c[mid.front()] == (int)mid.size())
    {
        front.splice(front.end(), std::list<int>(mid.size() * m % k, mid.front()));
        front.splice(front.end(), back);
        // static int lst = -1, cnt = 0;
        // for (auto i : front)
        // {
        //     if (lst == i)
        //         ++cnt;
        //     else
        //         std::cout << lst << ' ' << cnt << std::endl, lst = i, cnt = 1;
        // }
        // std::cout << lst << ' ' << cnt << std::endl;
        // std::cout << front.size() << std::endl;
        for (std::list<int>::iterator i = front.begin(); i != front.end();)
        {
            std::list<int>::iterator j = i;
            int len = 0;
            while (j != front.begin() && *--j == *i)
                ;
            if (*j != *i)
                ++j;
            i = j;
            while (j != front.end() && *j == *i)
                ++j, ++len;
            for (int l = 0; l != len / k * k; ++l)
                front.erase(i++);
            i = j;
        }
        std::cout << front.size() << std::endl;
    }
    else
        std::cout << front.size() + mid.size() * m + back.size() << std::endl;
    return 0;
}