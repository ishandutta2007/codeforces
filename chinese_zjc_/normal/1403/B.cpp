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
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, n, dp[6005][6005];
struct node
{
    int l, r;
} a[6005];
std::vector<int> s, L[6005], R[6005];
int dfs(int l, int r)
{
    if (l > r)
        return 0;
    if (~dp[l][r])
        return dp[l][r];
    dp[l][r] = 0;
    int count = 0;
    for (int i = 0; i != (int)L[l].size(); ++i)
        if (L[l][i] < r)
            dp[l][r] = std::max(dp[l][r], dfs(l, L[l][i]) + dfs(L[l][i] + 1, r));
        else if (L[l][i] == r)
            ++count;
    for (int i = 0; i != (int)R[r].size(); ++i)
        if (l < R[r][i])
            dp[l][r] = std::max(dp[l][r], dfs(l, R[r][i] - 1) + dfs(R[r][i], r));
        else if (R[r][i] == l)
            ++count;
    count >>= 1;
    return dp[l][r] = std::max(dp[l][r], std::max(dfs(l, r - 1), dfs(l + 1, r))) + count;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        int ans = 0;
        for (int i = 0; i != (int)s.size(); ++i)
            L[i].clear(), R[i].clear();
        s.clear();
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i].l >> a[i].r;
            s.push_back(a[i].l);
            s.push_back(a[i].r);
        }
        std::sort(s.begin(), s.end());
        s.erase(std::unique(s.begin(), s.end()), s.end());
        for (int i = 1; i <= n; ++i)
        {
            a[i].l = std::lower_bound(s.begin(), s.end(), a[i].l) - s.begin();
            a[i].r = std::lower_bound(s.begin(), s.end(), a[i].r) - s.begin();
            L[a[i].l].push_back(a[i].r);
            R[a[i].r].push_back(a[i].l);
        }
        for (int i = 0; i != s.size(); ++i)
            std::fill(dp[i], dp[i] + s.size(), -1);
        std::cout << dfs(0, s.size() - 1) + ans << std::endl;
        // for (int i = 0; i != s.size(); ++i)
        //     for (int j = 0; j <= i; ++j)
        //         std::cout << dfs(j, i) << " \n"[j == i];
    }
    return 0;
}