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
int n, d[100005], T, lst;
std::priority_queue<std::pair<int, int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        std::cin >> d[1];
        int ans = 0;
        for (int i = 2; i <= n; ++i)
        {
            std::cin >> d[i];
            ans = std::max(ans, d[i]);
        }
        std::sort(d + 1, d + 1 + n);
        std::reverse(d + 1, d + 1 + n);
        int suf = 0;
        for (int i = 1; i <= n; ++i)
            suf += d[i];
        for (int i = 1; i <= n; ++i)
        {
            suf -= d[i];
            ans += suf - d[i] * (n - i);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}