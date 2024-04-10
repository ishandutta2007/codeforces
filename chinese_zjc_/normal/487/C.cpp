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
int n;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % n;
        B >>= 1;
        A = A * A % n;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    if (n == 4)
        return std::cout << "YES" << std::endl
                         << "1 3 2 4" << std::endl,
               0;
    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl;
    std::cout << 1 << std::endl;
    for (int i = 2; i < n; ++i)
        std::cout << (i - 1) * power(i, n - 2) % n << std::endl;
    if (n > 1)
        std::cout << n << std::endl;
    return 0;
}