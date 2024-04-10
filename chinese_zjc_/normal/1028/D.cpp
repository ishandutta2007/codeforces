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
const int MOD = 1000000007;
int n, ans = 1;
std::set<int> unknow, sell, buy;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static std::string opt;
        static int x;
        std::cin >> opt >> x;
        if (opt == "ADD")
        {
            // unknow.insert(x);
            if (!buy.empty() && *buy.rbegin() > x)
                buy.insert(x);
            else if (!sell.empty() && *sell.begin() < x)
                sell.insert(x);
            else
                unknow.insert(x);
        }
        else if (opt == "ACCEPT")
        {
            // for (auto i : unknow)
            //     std::cout << i << ' ';
            // std::cout << std::endl;
            // for (auto i : sell)
            //     std::cout << i << ' ';
            // std::cout << std::endl;
            // for (auto i : buy)
            //     std::cout << i << ' ';
            // std::cout << std::endl;
            if (unknow.count(x))
            {
                ans = ans * 2 % MOD;
                for (std::set<int>::iterator i = unknow.begin(); i != unknow.end() && *i != x; unknow.erase(i++))
                    buy.insert(*i);
                unknow.erase(unknow.begin());
                for (std::set<int>::iterator i = unknow.begin(); i != unknow.end(); unknow.erase(i++))
                    sell.insert(*i);
                if (!unknow.empty())
                    exit(-1);
            }
            else if (buy.count(x))
            {
                if (*buy.rbegin() > x)
                {
                    std::cout << 0 << std::endl;
                    return 0;
                }
                for (std::set<int>::iterator i = unknow.begin(); i != unknow.end() && *i < x; unknow.erase(i++))
                    buy.insert(*i);
                for (std::set<int>::iterator i = unknow.begin(); i != unknow.end(); unknow.erase(i++))
                    sell.insert(*i);
                buy.erase(x);
            }
            else if (sell.count(x))
            {
                if (*sell.begin() < x)
                {
                    std::cout << 0 << std::endl;
                    return 0;
                }
                for (std::set<int>::iterator i = unknow.begin(); i != unknow.end() && *i < x; unknow.erase(i++))
                    buy.insert(*i);
                for (std::set<int>::iterator i = unknow.begin(); i != unknow.end(); unknow.erase(i++))
                    sell.insert(*i);
                sell.erase(x);
            }
            else
                std::cout << 0 << std::endl, exit(0);
        }
    }
    // for (int i = 0; i != (int)unknow.size(); ++i)
    //     ans = ans * 2 % MOD;
    ans = ans * (unknow.size() + 1) % MOD;
    std::cout << ans << std::endl;
    return 0;
}