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
int n, a[105];
bool h[105][105];
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            static char c;
            std::cin >> c;
            h[i][j] = c == '1';
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    while (true)
    {
        int pos = std::find(a + 1, a + 1 + n, 0) - a;
        if (pos > n)
            break;
        ans.push_back(pos);
        for (int i = 1; i <= n; ++i)
            if (h[pos][i])
                --a[i];
    }
    std::cout << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}