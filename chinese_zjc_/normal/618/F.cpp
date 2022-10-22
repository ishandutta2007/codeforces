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
int n, a[1000005], b[1000005];
std::pair<int, int> ans[1000005];
bool swaped;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    for (int i = 1; i <= n; ++i)
        b[i] += b[i - 1];
    if (a[n] > b[n])
    {
        std::swap(a, b);
        swaped = true;
    }
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i <= n; ++i)
    {
        int j = std::lower_bound(b, b + 1 + n, a[i]) - b;
        if (~ans[b[j] - a[i]].first && ~ans[b[j] - a[i]].second)
        {
            if (!swaped)
            {
                std::cout << i - ans[b[j] - a[i]].first << std::endl;
                for (int k = ans[b[j] - a[i]].first; ++k <= i;)
                    std::cout << k << " \n"[k == i];
            }
            std::cout << j - ans[b[j] - a[i]].second << std::endl;
            for (int k = ans[b[j] - a[i]].second; ++k <= j;)
                std::cout << k << " \n"[k == j];
            if (swaped)
            {
                std::cout << i - ans[b[j] - a[i]].first << std::endl;
                for (int k = ans[b[j] - a[i]].first; ++k <= i;)
                    std::cout << k << " \n"[k == i];
            }
            return 0;
        }
        else
        {
            ans[b[j] - a[i]] = std::make_pair(i, j);
        }
    }
    return 0;
}