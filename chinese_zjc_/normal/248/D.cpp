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
int n, t, pre[500005];
std::vector<int> lst;
char c[500005];
int check(int now)
{
    int L = 1, res = lst[std::max(0ll, -(now + pre[lst.front()]))] * 2 - 1, tim = 0;
    for (int i = 1; i <= lst.front(); ++i)
    {
        switch (c[i])
        {
        case 'H':
            if (now >= 0)
                L = i;
            --now;
            break;
        case 'S':
            ++now;
            if (now == 0)
                tim += (i - L) * 2, L = i;
            break;
        }
        ++tim;
        res = std::min(res, tim + 2 * lst[std::max(0ll, -(now + pre[lst.front()] - pre[i]))] - i - L);
        // std::cout << "? " << now << ' ' << res << ' ' << L << std::endl;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        std::cin >> c[i];
    for (int i = 1; i <= n; ++i)
        switch (c[i])
        {
        case 'S':
            pre[i] = pre[i - 1] + 1;
            break;
        case 'H':
            pre[i] = pre[i - 1] - 1;
            break;
        case '.':
            pre[i] = pre[i - 1];
            break;
        }
    for (int i = n; i; --i)
        if (c[i] == 'S')
            lst.push_back(i);
        else if (c[i] == 'H')
        {
            lst.push_back(i);
            break;
        }
    std::reverse(lst.begin(), lst.end());
    if (lst.front() > t)
        return std::cout << -1 << std::endl, 0;
    int l = std::max(0ll, std::count(c + 1, c + 1 + n, 'H') - std::count(c + 1, c + 1 + n, 'S')),
        r = std::count(c + 1, c + 1 + n, 'H');
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) <= t)
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << std::endl;
    return 0;
}