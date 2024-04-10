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
int f, t, t0, a1, m1, t1, a2, m2, t2, ans = INF;
int getbyte(int A, int B)
{
    int left = t, res = 0;
    if (left <= B * t2 * a2)
        return res + left / t2;
    left -= B * t2 * a2;
    res += B * a2;
    if (left <= A * t1 * a1)
        return res + left / t1;
    left -= A * t1 * a1;
    res += A * a1;
    res += left / t0;
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> f >> t >> t0 >> a1 >> t1 >> m1 >> a2 >> t2 >> m2;
    if (t1 < t2)
    {
        std::swap(a1, a2);
        std::swap(t1, t2);
        std::swap(m1, m2);
    }
    t1 = std::min(t1, t0);
    t2 = std::min(t2, t0);
    if (t / t2 < f)
    {
        std::cout << -1 << std::endl;
        return 0;
    }
    for (int i = 0, j = t; i <= t; ++i)
    {
        while (j >= 0 && getbyte(i, j) >= f)
        {
            ans = std::min(ans, i * m1 + j * m2);
            --j;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}