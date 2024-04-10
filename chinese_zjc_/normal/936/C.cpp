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
int n, cnt;
std::string s, t;
std::stringstream res;
void work(int x)
{
    std::reverse(s.begin(), s.end() - x);
    std::reverse(s.begin(), s.end());
    res << x << ' ';
    ++cnt;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s >> t;
    for (int i = 0; i != 26; ++i)
        if (std::count(s.begin(), s.end(), i + 'a') != std::count(t.begin(), t.end(), i + 'a'))
            return std::cout << -1 << std::endl, 0;
    for (int i = 0; i != n; ++i)
    {
        int p = s.find(t[i]);
        work(n - p - 1);
        // std::cout << s << std::endl;
        work(1);
        // std::cout << s << std::endl;
        work(n);
        // std::cout << s << std::endl;
        // std::cout << "-----" << std::endl;
    }
    std::cout << cnt << std::endl
              << res.str() << std::endl;
    return 0;
}