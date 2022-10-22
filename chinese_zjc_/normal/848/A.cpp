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
std::bitset<100005> dp[27];
int n, v[50];
void work(int now, int v)
{
    if (now == 0)
    {
        if (v)
            std::cout << "?" << std::endl;
        return;
    }
    for (int i = 1; i * (i - 1) / 2 <= v; ++i)
        if (dp[now - 1][v - i * (i - 1) / 2])
        {
            work(now - 1, v - i * (i - 1) / 2);
            std::cout << std::string(i, 'a' + now - 1);
            return;
        }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    dp[0][0] = true;
    for (int i = 1; i <= 26; ++i)
        for (int j = 1; j * (j - 1) / 2 <= n; ++j)
            dp[i] |= dp[i - 1] << (j * (j - 1) / 2);
    work(26, n);
    std::cout << std::endl;
    return 0;
}