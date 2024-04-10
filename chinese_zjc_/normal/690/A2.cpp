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
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    if (n & 1)
        std::cout << n / 2 << std::endl;
    else
        std::cout << (n - (1 << (int)log2(n))) / 2 << std::endl;
    return 0;
}