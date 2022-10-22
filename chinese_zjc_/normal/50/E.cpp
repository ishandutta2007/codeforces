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
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
int n, m, r = -INF;
long long ans;
int R[20000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    memset(R, 0xf0, sizeof(R));
    for (long long b = 1; b <= n; ++b)
    {
        int cnt = b * b <= m ? b * b * 2 : m * 2;
        int l = ceil(-b - sqrt(b * b - 1)), r = floor(-b - sqrt(std::max(0ll, b * b - m))) + 1;
        R[l + 10000000] = std::max(R[l + 10000000], r);
        cnt -= r - l;
        l = ceil(-b + sqrt(std::max(0ll, b * b - m))), r = floor(-b + sqrt(b * b - 1)) + 1;
        R[l + 10000000] = std::max(R[l + 10000000], r);
        cnt -= r - l;
        // std::cout << cnt << std::endl;
        ans += cnt;
    }
    for (int i = 0; i <= 20000000; ++i)
    {
        int x = i - 10000000;
        ans += std::max(0, R[i] - std::max(r, x));
        r = std::max(R[i], r);
    }
    std::cout << ans << std::endl;
    return 0;
}