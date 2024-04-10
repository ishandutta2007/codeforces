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
std::set<int> s[2];
int n, k;
void end(const char *x) { std::cout << x << std::endl, exit(0); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        static char c;
        std::cin >> c;
        s[c == '1'].insert(i);
    }
    for (int i = 0; i != 2; ++i)
        if (s[i].empty() || *s[i].rbegin() - *s[i].begin() < k)
            end("tokitsukaze");
    for (int i = 0; i != 2; ++i)
        if (*s[i].begin() > k || n - *s[i].rbegin() >= k || *s[i].rbegin() - *s[i].begin() > k)
            end("once again");
    end("quailty");
    return 0;
}