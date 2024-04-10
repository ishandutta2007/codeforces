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
int n, T, l, r, c[200005][2], ans, sum[2], f;
struct sock
{
    int c;
    bool l;
} a[200005];
std::vector<int> b[2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans = 0;
        memset(c, 0, sizeof(c));
        b[0].clear();
        b[1].clear();
        sum[0] = sum[1] = 0;
        std::cin >> n >> l >> r;
        for (int i = 1; i <= l; ++i)
        {
            std::cin >> a[i].c;
            a[i].l = false;
        }
        for (int i = 1; i <= r; ++i)
        {
            std::cin >> a[i + l].c;
            a[i + l].l = true;
        }
        for (int i = 1; i <= n; ++i)
            ++c[a[i].c][a[i].l];
        for (int i = 1; i <= n; ++i)
            while (c[i][0] && c[i][1])
                --c[i][0], --c[i][1];
        for (int i = 1; i <= n; ++i)
        {
            if (c[i][0])
                b[0].push_back(c[i][0]);
            if (c[i][1])
                b[1].push_back(c[i][1]);
            sum[0] += c[i][0];
            sum[1] += c[i][1];
        }
        if (sum[0] > sum[1])
            for (int i = 0; i != b[0].size(); ++i)
            {
                int tmp = std::min(sum[0] - sum[1], b[0][i]) / 2 * 2;
                sum[0] -= tmp;
                b[0][i] -= tmp;
                ans += tmp / 2;
            }
        else
            for (int i = 0; i != b[1].size(); ++i)
            {
                int tmp = std::min(sum[1] - sum[0], b[1][i]) / 2 * 2;
                sum[1] -= tmp;
                b[1][i] -= tmp;
                ans += tmp / 2;
            }
        ans += llabs(sum[0] - sum[1]) / 2;
        f = 0;
        for (auto i : b[0])
            f += i;
        for (auto i : b[1])
            f += i;
        ans += f / 2;
        std::cout << ans << std::endl;
    }
    return 0;
}