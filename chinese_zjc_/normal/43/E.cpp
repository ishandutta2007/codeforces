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
int n, s, m[105], k[105][105], t[105][105], ans;
int sgn(int x) { return x < 0 ? -1 : x > 0; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> m[i];
        for (int j = 1; j <= m[i]; ++j)
            std::cin >> k[i][j] >> t[i][j], t[i][j] += t[i][j - 1];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
        {
            int a = 1, b = 1, lst = 0, dx = 0, st = 0;
            while (a <= m[i] && b <= m[j])
            {
                int nxt = std::min(t[i][a], t[j][b]);
                dx += (k[i][a] - k[j][b]) * (nxt - st);
                st = nxt;
                if (sgn(dx))
                    ans += lst == -sgn(dx), lst = sgn(dx);
                if (t[i][a] < t[j][b])
                    ++a;
                else
                    ++b;
            }
        }
    std::cout << ans << std::endl;
    return 0;
}