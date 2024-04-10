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
std::vector<std::string> ans[15];
int n;
void print(const std::vector<int> &x)
{
    std::cout << '{';
    for (int i = 0; i != (int)x.size(); ++i)
        std::cout << x[i] << ",}"[i + 1 == (int)x.size()];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    ans[1].push_back("0");
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
        for (auto j : ans[i - 1])
        {
            char beg = ans[i].empty() ? '0' : ans[i].back().back(),
                 max = *std::max_element(j.begin(), j.end()) + 1;
            ans[i].push_back(j + beg);
            for (char k = '2'; k <= max; ++k)
                ans[i].push_back(j + k);
            ans[i].push_back(j + char(beg ^ '0' ^ '1'));
        }
    std::cout << ans[n].size() << std::endl;
    for (auto i : ans[n])
    {
        char max = *std::max_element(i.begin(), i.end());
        for (char j = '0'; j <= max; ++j)
        {
            std::vector<int> tmp;
            for (int k = 0; k != n; ++k)
                if (i[k] == j)
                    tmp.push_back(k + 1);
            print(tmp);
            std::cout << ",\n"[j == max];
        }
    }
    return 0;
}