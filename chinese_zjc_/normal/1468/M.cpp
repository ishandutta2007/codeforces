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
#include <unordered_set>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, n, m, k[200005], d;
bool has[200005];
std::vector<int> app[200005], s[200005];
std::map<int, int> map;
std::set<int> set[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != (int)map.size(); ++i)
            app[i].clear();
        m = 0;
        map.clear();
        for (int i = 1; i <= n; ++i)
            set[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            static int k;
            std::cin >> k;
            s[i].resize(k);
            m += k;
            for (int j = 0; j != k; ++j)
            {
                std::cin >> s[i][j];
                app[s[i][j] = map.insert(std::make_pair(s[i][j], map.size())).first->second].push_back(i);
            }
        }
        d = 50;
        for (int i = 0; i != (int)map.size(); ++i)
        {
            if ((int)app[i].size() > d)
            {
                std::fill(has + 1, has + 1 + n, false);
                for (int j = 0; j != (int)app[i].size(); ++j)
                    has[app[i][j]] = true;
                for (int j = 0; j != (int)map.size(); ++j)
                    if (i != j && (j > i || (int)app[j].size() <= d))
                        for (int k = 0, tmp = 0; k != (int)app[j].size(); ++k)
                            if (has[app[j][k]])
                            {
                                if (tmp)
                                {
                                    std::cout << tmp << ' ' << app[j][k] << std::endl;
                                    goto nextcase;
                                }
                                else
                                    tmp = app[j][k];
                            }
            }
            else
            {
                for (int j = 0; j != (int)app[i].size(); ++j)
                    for (int k = j + 1; k != (int)app[i].size(); ++k)
                        if (!set[app[i][j]].insert(app[i][k]).second)
                        {
                            std::cout << app[i][j] << ' ' << app[i][k] << std::endl;
                            goto nextcase;
                        }
            }
        }
        std::cout << -1 << std::endl;
    nextcase:
        continue;
    }
    return 0;
}