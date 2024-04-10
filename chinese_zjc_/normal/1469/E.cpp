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
int q, n, k, cnt, son[2][20 << 20 | 5];
// bool flag;
std::string s;
void insert(int now, int tim, const std::string &str)
{
    if (tim == (int)str.length())
        return;
    if (!~son[str[tim] ^ '1'][now])
        son[str[tim] ^ '1'][now] = cnt++;
    insert(son[str[tim] ^ '1'][now], tim + 1, str);
}
bool dfs(int now, const std::string &pre)
{
    if ((int)pre.size() == std::min(k, 20ll))
        return false;
    if (!~son[0][now])
        return std::cout << "YES" << std::endl
                         << (std::string(std::max(0ll, k - 20), '0') + pre + "0" + std::string(std::min(k, 20ll) - pre.size() - 1, '0')) << std::endl,
               true;
    if (dfs(son[0][now], pre + '0'))
        return true;
    if (!~son[1][now])
        return std::cout << "YES" << std::endl
                         << (std::string(std::max(0ll, k - 20), '0') + pre + "1" + std::string(std::min(k, 20ll) - pre.size() - 1, '0')) << std::endl,
               true;
    return dfs(son[1][now], pre + '1');
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> q;
    // flag = q == 1000;
    memset(son, -1, sizeof(son));
    while (q--)
    {
        std::cin >> n >> k >> s;
        // if (q == 999)
        //     flag &= n == 27 && k == 23 && s == "001011000101011111000101100";
        // if (flag && q == 1000 - 156)
        //     std::cout << n << ' ' << k << std::endl
        //               << s << std::endl;
        std::fill(son[0], son[0] + cnt, -1);
        std::fill(son[1], son[1] + cnt, -1);
        cnt = 1;
        std::vector<int> pre(n + 1);
        for (int i = 0; i != n; ++i)
            pre[i + 1] = pre[i] + (s[i] == '0');
        for (int i = 0; i <= n - k; ++i)
            if (pre[i + k - std::min(20ll, k)] - pre[i] == 0)
                insert(0, 0, s.substr(i + std::max(k - 20, 0ll), std::min(k, 20ll)));
        if (!dfs(0, ""))
            std::cout << "NO" << std::endl;
    }
    return 0;
}