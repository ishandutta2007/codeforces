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
int n;
size_t ans = 1, pre, suf, len;
char prec, sufc;
std::string s[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i];
    if (std::count(s[n].begin(), s[n].end(), s[n].front()) == (int)s[n].size())
    {
        prec = sufc = s[n].front();
        len = pre = suf = s[n].size();
    }
    else
    {
        pre = s[n].find_first_not_of(prec = s[n].front());
        suf = s[n].size() - 1 - s[n].find_last_not_of(sufc = s[n].back());
        len = s[n].size();
    }
    ans = std::max(pre, suf);
    for (size_t i = 0; i != s[n].size();)
    {
        size_t j = i;
        while (j != s[n].size() && s[n][i] == s[n][j])
            ++j;
        ans = std::max(ans, j - i);
        i = j;
    }
    for (int i = n - 1; i; --i)
    {
        // std::cout << prec << ' ' << sufc << ' ' << pre << ' ' << suf << ' ' << len << std::endl;
        if (pre == len && std::count(s[i].begin(), s[i].end(), prec) == (int)s[i].size())
        {
            ans = std::max(ans, pre = suf = len = (s[i].size() + 1) * len + s[i].size());
        }
        else
        {
            if (pre == len)
            {
                for (size_t j = s[i].find(prec, 0); j != std::string::npos; j = s[i].find(prec, j))
                {
                    size_t k = j;
                    while (k != s[i].size() && s[i][k] == prec)
                        ++k;
                    ans = std::max(ans, (k - j + 1) * len + (k - j));
                    j = k;
                }
                len = (s[i].size() + 1) * len + s[i].size();
                pre = pre + (pre + 1) * s[i].find_first_not_of(prec);
                suf = suf + (suf + 1) * (s[i].size() - 1 - s[i].find_last_not_of(sufc));
            }
            else if (prec == sufc)
            {
                if (s[i].find(prec) != std::string::npos)
                    ans = std::max(ans, pre + 1 + suf);
            }
            else
            {
                if (s[i].find(prec) != std::string::npos)
                    ans = std::max(ans, pre + 1);
                if (s[i].find(sufc) != std::string::npos)
                    ans = std::max(ans, suf + 1);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}