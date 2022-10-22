//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, T;
std::deque<int> b[105];
std::vector<int> ans[105];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            static int tmp;
            for (int j = 1; j <= m; ++j)
            {
                std::cin >> tmp;
                b[i].push_back(tmp);
            }
            std::sort(b[i].begin(), b[i].end());
        }
        for (int i = 1; i <= m; ++i)
        {
            int Min = 1;
            for (int j = 2; j <= n; ++j)
                if (*b[j].begin() < *b[Min].begin())
                    Min = j;
            for (int j = 1; j < Min; ++j)
            {
                ans[i].push_back(*b[j].rbegin());
                b[j].pop_back();
            }
            ans[i].push_back(*b[Min].begin());
            b[Min].pop_front();
            for (int j = Min + 1; j <= n; ++j)
            {
                ans[i].push_back(*b[j].rbegin());
                b[j].pop_back();
            }
        }
        for (int i = 0; i != n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cout << ans[j][i] << " \n"[j == m];
        for (int i = 1; i <= m; ++i)
            ans[i].clear();
    }
    return 0;
}