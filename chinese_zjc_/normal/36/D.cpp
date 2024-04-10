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
int k;
bool D(int n, int m)
{
    int t = std::min(n, m) / (2 * k + 2);
    n -= t * (2 * k + 2);
    m -= t * (2 * k + 2);
    if ((n % (k + 1) == 0 && m >= n) || (m % (k + 1) == 0 && n >= m))
        return true;
    return k == 1 ? (n + m) & 1 : (std::min(n, m) > k + 1) ^ ((n + m) & 1);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, n, m;
    std::cin >> T >> k;
    // for (int i = 1; i <= 100; ++i, std::cout << std::endl)
    //     for (int j = 1; j <= 100; ++j)
    //         std::cout << D(i, j);
    while (T--)
    {
        std::cin >> n >> m;
        std::cout << "-+"[D(n, m)] << std::endl;
    }
    return 0;
}