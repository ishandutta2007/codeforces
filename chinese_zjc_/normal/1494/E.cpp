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
int A, B, n, m;
std::map<std::pair<int, int>, char> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    while (m--)
    {
        static char c;
        static int x, y;
        static std::map<std::pair<int, int>, char>::iterator iter;
        std::cin >> c;
        switch (c)
        {
        case '+':
            std::cin >> x >> y >> c;
            map[{x, y}] = c;
            iter = map.find({y, x});
            if (iter != map.end())
            {
                ++A;
                if (iter->second == c)
                    ++B;
            }
            break;
        case '-':
            std::cin >> x >> y;
            c = (iter = map.find({x, y}))->second;
            map.erase(iter);
            iter = map.find({y, x});
            if (iter != map.end())
            {
                --A;
                if (iter->second == c)
                    --B;
            }
            break;
        case '?':
            std::cin >> x;
            std::cout << ((x & 1 ? A : B) ? "YES" : "NO") << std::endl;
        }
    }
    return 0;
}