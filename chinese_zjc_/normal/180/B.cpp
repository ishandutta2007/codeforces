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
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int a, b, x;
bool check2()
{
    return b == 1;
}
bool check3()
{
    return x == 0 && (a - 1) % b == 0;
}
bool check11()
{
    return x == 0 && (a + 1) % b == 0;
}
bool check6() { return (a - 1) * (a + 1) / std::__gcd(a + 1, a - 1) % b == 0; }
int work()
{
    // std::cout << check2() << ' ' << check3() << ' ' << check11() << std::endl;
    if (check2())
        return 2;
    if (check3())
        return 3;
    if (check11())
        return 11;
    if (check6())
        return 6;
    return 7;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b;
    while (std::__gcd(a, b) > 1)
        b /= std::__gcd(a, b), ++x;
    std::cout << work() << "-type" << std::endl;
    if (work() == 2)
        std::cout << x << std::endl;
    return 0;
}