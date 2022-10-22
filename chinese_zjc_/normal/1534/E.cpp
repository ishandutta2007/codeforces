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
int n, k, ans[505], res;
bool cho[505];
void ask(std::vector<int> x)
{
    std::cout << '?';
    for (auto i : x)
        cho[i] ^= true, std::cout << ' ' << i;
    std::cout << std::endl;
    static int y;
    std::cin >> y;
    res ^= y;
}
void work(int now)
{
    if (now == 0)
        return;
    work(now + ans[now] - (k - ans[now]));
    std::vector<int> q;
    for (int i = 1; i <= n && (int)q.size() != ans[now]; ++i)
        if (cho[i])
            q.push_back(i);
    for (int i = 1; i <= n && (int)q.size() != k; ++i)
        if (!cho[i])
            q.push_back(i);
    ask(q);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    memset(ans, -1, sizeof(ans));
    ans[0] = 0;
    std::queue<int> que;
    que.push(0);
    std::cin >> n >> k;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (int i = std::max(0ll, k - (n - now)); i <= std::min(now, k); ++i)
        {
            if (!~ans[now - i + (k - i)])
            {
                ans[now - i + (k - i)] = i;
                que.push(now - i + (k - i));
            }
        }
    }
    if (!~ans[n])
        return std::cout << -1 << std::endl, 0;
    work(n);
    std::cout << '!' << ' ' << res << std::endl;
    return 0;
}