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
int T, n, m, x, h[100005], ans[100005], rk[100005], l[100005];
struct L
{
    int h, p;
    friend bool operator<(const L &A, const L &B) { return A.h > B.h; }
};
std::priority_queue<L> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> x;
        for (int i = 1; i <= n; ++i)
            std::cin >> h[i];
        for (int i = 1; i <= n; ++i)
            rk[i] = i;
        std::sort(rk + 1, rk + 1 + n, [&](const int &A, const int &B) { return h[A] > h[B]; });
        while (!que.empty())
            que.pop();
        for (int i = 1; i <= m; ++i)
            que.push(L{l[i] = 0, i});
        for (int i = 1; i <= n; ++i)
        {
            int now = que.top().p;
            que.pop();
            l[now] += h[rk[i]];
            ans[rk[i]] = now;
            que.push(L{l[now], now});
        }
        if (*std::max_element(l + 1, l + 1 + m) - *std::min_element(l + 1, l + 1 + m) > x)
        {
            std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << "YES" << std::endl;
            for (int i = 1; i <= n; ++i)
                std::cout << ans[i] << " \n"[i == n];
        }
    }
    return 0;
}