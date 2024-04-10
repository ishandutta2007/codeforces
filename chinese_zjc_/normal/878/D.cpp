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
int n, k, q, v[12][100000];
std::vector<std::bitset<1 << 12>> dp;
std::vector<int> rk[100000];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> q;
    dp.resize(k);
    for (unsigned i = 0; i != k; ++i)
    {
        for (int j = 1 << i; j < 1 << k; j = (j + 1) | 1 << i)
        {
            dp[i][j] = true;
        }
        for (unsigned j = 0; j != n; ++j)
        {
            std::cin >> v[i][j];
        }
    }
    for (unsigned i = 0; i != n; ++i)
    {
        for (unsigned j = 0; j != k; ++j)
            rk[i].push_back(j);
        std::sort(rk[i].begin(), rk[i].end(), [&](const int &A, const int &B) { return v[A][i] < v[B][i]; });
    }
    while (q--)
    {
        static int x, y, opt;
        std::cin >> opt >> x >> y;
        --x;
        --y;
        switch (opt)
        {
        case 1:
            dp.push_back(dp[x] & dp[y]);
            break;
        case 2:
            dp.push_back(dp[x] | dp[y]);
            break;
        case 3:
            int s = 0;
            for (unsigned i = 0; i != k; ++i)
            {
                s |= 1 << rk[y][i];
                if (dp[x][s])
                {
                    std::cout << v[rk[y][i]][y] << std::endl;
                    break;
                }
            }
            break;
        }
    }
    return 0;
}