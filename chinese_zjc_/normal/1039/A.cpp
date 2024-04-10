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
const int INF = 3000000000000000000;
int n, t, a[200005], x[200005], L[200005], R[200005], maxx;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::fill(L + 1, L + 1 + n, -INF);
    std::fill(R + 1, R + 1 + n, +INF);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> x[i];
        maxx = std::max(maxx, x[i]);
        if (i < maxx)
            L[i] = std::max(L[i], a[i + 1] + t);
        if (x[i] < i)
            return std::cout << "No" << std::endl, 0;
    }
    a[n + 1] = INF;
    for (int i = 1; i <= n; ++i)
        L[i] = std::max(L[i], a[i] + t);
    for (int i = 1; i <= n; ++i)
        L[x[i]] = std::max(L[x[i]], a[i] + t);
    for (int i = 1; i <= n; ++i)
        R[x[i]] = std::min(R[x[i]], a[x[i] + 1] + t);
    for (int i = n; i; --i)
        R[i - 1] = std::min(R[i - 1], R[i] - 1);
    for (int i = 1; i <= n; ++i)
        if (L[i] >= R[i])
            return std::cout << "No" << std::endl, 0;
    std::cout << "Yes" << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << R[i] - 1 << " \n"[i == n];
    return 0;
}