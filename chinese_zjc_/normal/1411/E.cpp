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
int n, T, c[64];
char x;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> T;
    for (int i = 1; i <= n - 2; ++i)
    {
        std::cin >> x;
        ++c[x - 'a'];
    }
    std::cin >> x;
    T += 1 << (x - 'a');
    std::cin >> x;
    T -= 1 << (x - 'a');
    for (int i = 63; i--;)
        while (c[i]--)
            if (T > 0)
                T -= 1 << i;
            else
                T += 1 << i;
    std::cout << (T ? "No" : "Yes") << std::endl;
    return 0;
}