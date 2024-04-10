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
int n, m, p, lto[1005][1005], rto[1005][1005], ld[1005], rd[1005], f[100005], t[100005];
void connect(int L, int R, int v)
{
    lto[L][v] = R;
    rto[R][v] = L;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> p;
    for (int i = 1; i <= p; ++i)
    {
        std::cin >> f[i] >> t[i];
        ++ld[f[i]];
        ++rd[t[i]];
        int a = std::find(lto[f[i]], lto[f[i]] + m, 0) - lto[f[i]];
        int b = std::find(rto[t[i]], rto[t[i]] + n, 0) - rto[t[i]];
        std::vector<int> way;
        way.push_back(t[i]);
        while (true)
            if (way.size() & 1)
            {
                if (!rto[way.back()][a])
                    break;
                way.push_back(rto[way.back()][a]);
            }
            else
            {
                if (!lto[way.back()][b])
                    break;
                way.push_back(lto[way.back()][b]);
            }
        // for (auto j : way)
        //     std::cout << ' ' << j;
        // std::cout << std::endl;
        // std::cout << a << ' ' << b << std::endl;
        for (int j = 1; j < way.size(); ++j)
            if (j & 1)
                connect(way[j], way[j - 1], b);
            else
                connect(way[j - 1], way[j], a);
        if (way.size() & 1)
            rto[way.back()][b] = 0;
        else
            lto[way.back()][a] = 0;
        connect(f[i], t[i], a);
        // for (int j = 1; j <= n; ++j)
        // {
        //     for (int k = 0; k <= p; ++k)
        //     {
        //         std::cout << lto[j][k] << " \n"[k == p];
        //     }
        // }
    }
    int ans = std::max(*std::max_element(ld + 1, ld + 1 + n), *std::max_element(rd + 1, rd + 1 + m));
    std::cout << ans << std::endl;
    for (int i = 1; i <= p; ++i)
    {
        // if (std::find(lto[f[i]], lto[f[i]] + ans, t[i]) - lto[f[i]] + 1 > ans)
        // {
        //     for (int j = 51; j <= p; ++j)
        //         std::cout << f[j] << ' ' << t[j] << std::endl;
        //     break;
        // }
        std::cout << std::find(lto[f[i]], lto[f[i]] + ans, t[i]) - lto[f[i]] + 1 << " \n"[i == p];
    }
    return 0;
}