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
int n, m, sum[100005], rk[100005], sa[100005], top[100005], but[100005], height[100005], ans;
char c[100005];
bool bad[100005];
int calc(int x) { return x * (x + 1) / 2; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (c + 1);
    n = strlen(c + 1);
    m = 128;
    for (int i = 1; i <= n; ++i)
        ++sum[rk[i] = c[i]];
    for (int i = 1; i <= m; ++i)
        sum[i] += sum[i - 1];
    for (int i = n; i; --i)
        sa[sum[rk[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1)
    {
        static int cnt, tmp[100005];
        cnt = 0;
        for (int i = n - k + 1; i <= n; ++i)
            tmp[++cnt] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > k)
                tmp[++cnt] = sa[i] - k;
        std::fill(sum + 1, sum + 1 + m, 0);
        for (int i = 1; i <= n; ++i)
            ++sum[rk[i]];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[tmp[i]]]--] = tmp[i];
        std::swap(rk, tmp);
        rk[sa[1]] = m = 1;
        for (int i = 2; i <= n; ++i)
            rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
        if (n == m)
            break;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (rk[i] == 1)
            continue;
        static int h;
        if (h)
            --h;
        int j = sa[rk[i] - 1];
        while (std::max(i, j) + h <= n && c[j + h] == c[i + h])
            ++h;
        height[rk[i]] = h;
    }
    std::stack<int> sta;
    for (int i = 1; i <= n; ++i)
    {
        while (!sta.empty() && height[i] <= height[sta.top()])
        {
            if (height[i] == height[sta.top()])
                bad[sta.top()] = true;
            but[sta.top()] = i - 1;
            sta.pop();
        }
        sta.push(i);
    }
    while (!sta.empty())
    {
        but[sta.top()] = n;
        sta.pop();
    }
    for (int i = n; i; --i)
    {
        while (!sta.empty() && height[i] < height[sta.top()])
        {
            top[sta.top()] = i;
            sta.pop();
        }
        sta.push(i);
    }
    while (!sta.empty())
    {
        top[sta.top()] = 1;
        sta.pop();
    }
    // for (int i = 1; i <= n; ++i)
    //     std::cout << (c + sa[i]) << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        // std::cout << but[i] - top[i] + 1 << ' ' << height[i] - std::max(height[top[i]], height[but[i] + 1]) << std::endl;
        // std::cout << top[i] << ' ' << but[i] << std::endl;
        if (!bad[i])
            ans += calc(but[i] - top[i] + 1) * (height[i] - std::max(height[top[i]], height[but[i] + 1]));
        ans += (n - sa[i] + 1) - std::max(height[i], height[i + 1]);
    }
    std::cout << ans << std::endl;
    return 0;
}