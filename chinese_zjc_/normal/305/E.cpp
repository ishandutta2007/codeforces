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
char c[5005];
int n, dp[5005], ans;
bool good[5005];
int work(int l, int r)
{
    int res = 0;
    for (int i = l; i <= r;)
        if (good[i])
        {
            int j = i;
            while (j <= r && good[j])
                ++j;
            res ^= dp[j - i];
            i = j;
        }
        else
            ++i;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (c + 1);
    n = strlen(c + 1);
    for (int i = 2; i < n; ++i)
        if (c[i - 1] == c[i + 1])
            good[i] = true;
    for (int i = 1; i <= n; ++i)
    {
        bool app[5005];
        memset(app, false, sizeof(app));
        for (int j = 1; j <= i; ++j)
            app[dp[std::max(0ll, j - 2)] ^ dp[std::max(0ll, i - j - 1)]] = true;
        while (app[dp[i]])
            ++dp[i];
    }
    ans = work(1, n);
    std::cout << (ans ? "First" : "Second") << std::endl;
    if (ans)
        for (int i = 1; i <= n; ++i)
            if (good[i] && !(work(1, i - 2) ^ work(i + 2, n)))
                return std::cout << i << std::endl, 0;
    return 0;
}