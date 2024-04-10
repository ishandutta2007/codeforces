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
int T, n, m, rk[100005], sum[100005], sa[100005], height[100005], lst[100005], nxt[100005], ans;
bool has[100005];
char s[100005];
int sqr(int x) { return x * x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        memset(sum, 0, sizeof(sum));
        memset(rk, 0, sizeof(rk));
        memset(sa, 0, sizeof(sa));
        memset(has, false, sizeof(has));
        std::cin >> (s + 1);
        n = strlen(s + 1);
        m = 128;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            ++sum[rk[i] = s[i]];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = n; i; --i)
            sa[sum[rk[i]]--] = i;
        for (int k = 1; k <= n; k <<= 1)
        {
            static int tmp[100005], tim;
            tim = 0;
            for (int i = n - k + 1; i <= n; ++i)
                tmp[++tim] = i;
            for (int i = 1; i <= n; ++i)
                if (sa[i] > k)
                    tmp[++tim] = sa[i] - k;
            std::fill(sum + 1, sum + 1 + m, 0);
            for (int i = 1; i <= n; ++i)
                ++sum[rk[i]];
            for (int i = 1; i <= m; ++i)
                sum[i] += sum[i - 1];
            for (int i = n; i; --i)
                sa[sum[rk[tmp[i]]]--] = tmp[i];
            std::swap(rk, tmp);
            m = 1;
            rk[sa[1]] = 1;
            for (int i = 2; i <= n; ++i)
                rk[sa[i]] = tmp[sa[i]] == tmp[sa[i - 1]] && tmp[sa[i] + k] == tmp[sa[i - 1] + k] ? m : ++m;
            if (n == m)
                break;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (rk[i] == 1)
                continue;
            static int h = 0;
            if (h)
                --h;
            while (i + h <= n && sa[rk[i] - 1] + h <= n && s[i + h] == s[sa[rk[i] - 1] + h])
                ++h;
            height[rk[i]] = h;
        }
        height[n + 1] = 0;
        // for (int i = 1; i <= n; ++i)
        //     std::cout << std::string(height[i], '-') << std::endl
        //               << (s + sa[i]) << std::endl;
        ans = 0;
        std::stack<int> sta;
        for (int i = 2; i <= n; ++i)
        {
            while (!sta.empty() && height[sta.top()] > height[i])
            {
                nxt[sta.top()] = i;
                sta.pop();
            }
            if (!sta.empty() && height[sta.top()] == height[i])
                has[i] = true;
            sta.push(i);
        }
        while (!sta.empty())
        {
            nxt[sta.top()] = n + 1;
            sta.pop();
        }
        for (int i = n; i >= 2; --i)
        {
            while (!sta.empty() && height[sta.top()] > height[i])
            {
                lst[sta.top()] = i;
                sta.pop();
            }
            sta.push(i);
        }
        while (!sta.empty())
        {
            lst[sta.top()] = 1;
            sta.pop();
        }
        for (int i = 1; i <= n; ++i)
            ans += n - sa[i] + 1 - std::max(height[i], height[i + 1]);
        for (int i = 2; i <= n; ++i)
            if (!has[i])
                ans += (height[i] - std::max(height[lst[i]], height[nxt[i]])) * sqr(nxt[i] - lst[i]);
        std::cout << ans << std::endl;
    }
    return 0;
}