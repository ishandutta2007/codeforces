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
#include <unordered_set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
std::unordered_set<int> X[100005], Y[100005];
int n, lim, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    lim = sqrt(n);
    for (int k = 0; k <= 100000; ++k)
        if ((int)X[k].size() <= lim)
        {
            while (!X[k].empty())
            {
                std::unordered_set<int>::const_iterator i = X[k].begin();
                for (std::unordered_set<int>::const_iterator j = i; ++j != X[k].end();)
                {
                    int len = llabs(*j - *i);
                    if (k - len >= 0 && X[k - len].count(*i) && X[k - len].count(*j))
                        ++ans;
                    if (k + len <= 100000 && X[k + len].count(*i) && X[k + len].count(*j))
                        ++ans;
                }
                Y[*X[k].begin()].erase(k);
                X[k].erase(X[k].begin());
            }
        }
    for (int k = 0; k <= 100000; ++k)
        if ((int)Y[k].size() <= lim)
        {
            while (!Y[k].empty())
            {
                std::unordered_set<int>::const_iterator i = Y[k].begin();
                for (std::unordered_set<int>::const_iterator j = i; ++j != Y[k].end();)
                {
                    int len = llabs(*j - *i);
                    if (k - len >= 0 && Y[k - len].count(*i) && Y[k - len].count(*j))
                        ++ans;
                    if (k + len <= 100000 && Y[k + len].count(*i) && Y[k + len].count(*j))
                        ++ans;
                }
                X[*Y[k].begin()].erase(k);
                Y[k].erase(Y[k].begin());
            }
        }
    std::cout << ans << std::endl;
    return 0;
}