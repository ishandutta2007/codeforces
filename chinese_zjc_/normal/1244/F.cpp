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
int n, k;
std::string s;
bool check()
{
    for (int i = 0; i != n; ++i)
        if (s[i] == s[(i + 1) % n])
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> s;
    if (k & 1 && check())
    {
        std::cout << s.substr(1) + s[0] << std::endl;
        return 0;
    }
    if (n <= 5)
    {
        for (int l = 1; l <= std::min(k, 16 + k % 16); ++l)
        {
            std::string tmp;
            for (int j = 0; j != n; ++j)
            {
                tmp.push_back((s[(j - 1 + n) % n] == 'B') + (s[j] == 'B') + (s[(j + 1 + n) % n] == 'B') > 1 ? 'B' : 'W');
            }
            s = tmp;
        }
        std::cout << s << std::endl;
        return 0;
    }
    for (int i = 0; i != n; ++i)
    {
        if (s[i] == s[(i + n - 1) % n] && s[(i + 1) % n] != s[i])
        {
            int j = i + 1;
            while (s[j % n] != s[(j + 1) % n])
                ++j;
            int tmp = std::min(n - 1, j);
            j %= n;
            // std::cout << s << std::endl;
            // std::cout << i << " " << j << std::endl;
            if (llabs(j - i) > 1 && llabs(j - i + n) > 1)
                for (int l = 1; l <= k; ++l)
                {
                    s[(i + 1 + n) % n] = s[i];
                    s[(j - 1 + n) % n] = s[j];
                    i = (i + 1 + n) % n;
                    j = (j - 1 + n) % n;
                    if (llabs(j - i) <= 1 || llabs(j - i + n) <= 1)
                        break;
                }
            if (i != j)
                for (int l = i + 1; l != j; l = (l + 1) % n)
                    s[l] = (s[l] == 'B') ^ (k & 1) ? 'B' : 'W';
            i = tmp;
        }
    }
    std::cout << s << std::endl;
    return 0;
}