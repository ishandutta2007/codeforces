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
std::bitset<100000> bit[26];
std::string s;
unsigned n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    for (unsigned i = 0; i != s.length(); ++i)
        bit[s[i] - 'a'][i] = true;
    std::cin >> n;
    while (n--)
    {
        static unsigned a, c, l, r;
        static char x;
        static std::string y;
        static std::bitset<100000> z;
        std::cin >> c;
        switch (c)
        {
        case 1:
            std::cin >> a >> x;
            --a;
            bit[s[a] - 'a'][a] = false;
            s[a] = x;
            bit[s[a] - 'a'][a] = true;
            break;
        case 2:
            std::cin >> l >> r >> y;
            --l;
            if (r - l < y.length())
            {
                std::cout << "0" << std::endl;
                break;
            }
            r -= y.length() - 1;
            z.set();
            for (unsigned i = 0; i != y.length(); ++i)
                z &= bit[y[i] - 'a'] >> i;
            unsigned ans = (z >> l).count() - (z >> r).count();
            std::cout << ans << std::endl;
            // std::cout << z << std::endl;
            break;
        }
    }
if(1==1);
    return 0;
}// nmsl
// luogu sb