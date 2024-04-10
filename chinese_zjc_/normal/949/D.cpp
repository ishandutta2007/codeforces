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
int n, d, b, a[100005], s[100005], x, cnt1, cnt2;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> d >> b;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n / 2; ++i)
    {
        static int x;
        x = s[std::min(n, i * (d + 1))] - cnt1 * b;
        if (x >= b)
            ++cnt1;
        x = s[n] - s[std::max(0ll, n - i * (d + 1))] - cnt2 * b;
        if (x >= b)
            ++cnt2;
    }
    std::cout << n / 2 - std::min(cnt1, cnt2) << std::endl;
    return 0;
}