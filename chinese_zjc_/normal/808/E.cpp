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
int n, m, res, ans;
std::vector<int> w[4];
std::vector<int>::iterator pos[4];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int W, V;
        std::cin >> W >> V;
        w[W].push_back(V);
    }
    w[0].push_back(0);
    for (int i = 1; i <= 3; ++i)
        std::sort(w[i].begin(), w[i].end(), std::greater<int>()), pos[i] = w[i].begin();
    while (m >= 20)
    {
        int max = 0, val = 0;
        for (int i = 1; i <= 3; ++i)
            if (pos[i] != w[i].end() && *pos[i] * 6 / i > val)
                max = i, val = *pos[i] * 6 / i;
        if (!max)
            return std::cout << res << std::endl, 0;
        res += *(pos[max]++);
        m -= max;
    }
    for (int i = 1; i <= 3; ++i)
        for (int j = 0; j != 10 && pos[i] != w[i].begin(); ++j)
        {
            res -= *--pos[i];
            m += i;
        }
    for (int i = 0; i <= std::min(w[1].end() - pos[1], 100ll); ++i)
        for (int j = 0; j <= std::min(w[2].end() - pos[2], 100ll); ++j)
            for (int k = 0; k <= std::min(w[3].end() - pos[3], 100ll); ++k)
            {
                if (i * 1 + j * 2 + k * 3 > m)
                    continue;
                int tmp = 0;
                for (int l = 0; l != i; ++l)
                    tmp += *(pos[1] + l);
                for (int l = 0; l != j; ++l)
                    tmp += *(pos[2] + l);
                for (int l = 0; l != k; ++l)
                    tmp += *(pos[3] + l);
                ans = std::max(ans, res + tmp);
            }
    std::cout << ans << std::endl;
    return 0;
}