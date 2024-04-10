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
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n, lim, pop[1 << 10];
short app[50000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 1; i != 1 << 10; ++i)
        pop[i] = pop[i & (i - 1)] + 1;
    std::cin >> n;
    lim = std::min(5000000ll, n * n * 2);
    for (int i = 2; i <= lim; ++i)
    {
        int tmp = i;
        for (int j = 0; j != 10; ++j)
            if (tmp % p[j] == 0)
            {
                app[i] |= 1 << j;
                while (tmp % p[j] == 0)
                    tmp /= p[j];
            }
        if (tmp != 1)
            app[i] = -1;
    }
    for (int i = 1; i <= 10; ++i)
    {
        int num[i], tot = 0;
        std::vector<int> has[1 << i];
        memset(num, 0, sizeof(num));
        for (int j = 2; j <= lim; ++j)
            if ((app[j] & ((1 << i) - 1)) == app[j])
            {
                ++tot;
                has[app[j]].push_back(j);
            }
        for (int j = 0; j != 1 << i; ++j)
            for (int k = 0; k != 1 << i; ++k)
                if (j & 1 << k)
                    num[k] += has[j].size();
        bool flag = tot >= n;
        for (int j = 0; j != i; ++j)
            if (num[j] < n / 2)
                flag = false;
        if (flag)
        {
            memset(num, 0, sizeof(num));
            // std::cout << i << std::endl;
            int avai = (1 << i) - 1;
            for (int j = 0; j != n; ++j)
            {
                int best = 0;
                for (int k = 1; k != 1 << i; ++k)
                    if (!has[k].empty() && pop[k & avai] >= pop[best & avai])
                        best = k;
                std::cout << has[best].back() << ' ';
                has[best].pop_back();
                for (int j = 0; j != i; ++j)
                    if (best & 1 << j)
                        if (++num[j] >= n / 2)
                            avai &= ~(1 << j);
            }
            std::cout << std::endl;
            break;
        }
    }
    return 0;
}