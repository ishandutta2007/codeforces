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
int n, k, a[105], ans;
std::vector<int> s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        k += a[i];
        for (int j = 1; j * j <= a[i]; ++j)
            s.push_back(j), s.push_back((a[i] + j - 1) / j);
    }
    s.push_back(INF);
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    for (int i = 1; i != (int)s.size(); ++i)
    {
        int L = s[i - 1], R = s[i], sum = 0;
        for (int j = 1; j <= n; ++j)
            sum += (a[j] + L - 1) / L;
        int d = k / sum;
        if (L <= d && d < R && ans < d)
            ans = d;
    }
    std::cout << ans << std::endl;
    return 0;
}