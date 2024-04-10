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
bool work(int a, int b)
{
    if (a < b)
        std::swap(a, b);
    if (b == 0)
        return false;
    if (!work(a % b, b))
        return true;
    int x = a / b;
    return !((x % (b + 1)) & 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    while (T--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << (work(a, b) ? "First" : "Second") << std::endl;
    }
    return 0;
}