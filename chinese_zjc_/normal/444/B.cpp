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
int n, d, x, a[100005], b[100005], c[200005], app[100005];
std::vector<int> e;
int getNextX() { return x = (x * 37 + 10007) % 1000000007; }
void initAB()
{
    for (int i = 0; i < n; i = i + 1)
        a[i] = i + 1;
    for (int i = 0; i < n; i = i + 1)
        std::swap(a[i], a[getNextX() % (i + 1)]);
    for (int i = 0; i < n; i = i + 1)
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    for (int i = 0; i < n; i = i + 1)
        std::swap(b[i], b[getNextX() % (i + 1)]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d >> x;
    initAB();
    for (int i = 0; i != n; ++i)
        app[a[i]] = i;
    for (int i = 0; i != n; ++i)
        if (b[i])
            e.push_back(i);
    // for (int i = 0; i != n; ++i)
    //     std::cout << a[i] << ' ';
    // std::cout << std::endl;
    // for (int i = 0; i != n; ++i)
    //     std::cout << b[i] << ' ';
    // std::cout << std::endl;
    for (int i = 0; i != n; ++i)
        if (d >= 500)
        {
            for (int j = n; j; --j)
                if (i - app[j] >= 0 && b[i - app[j]])
                {
                    c[i] = j;
                    break;
                }
        }
        else
        {
            for (auto j : e)
                if (i - j >= 0)
                    c[i] = std::max(c[i], a[i - j]);
        }
    for (int i = 0; i != n; ++i)
        std::cout << c[i] << std::endl;
    return 0;
}