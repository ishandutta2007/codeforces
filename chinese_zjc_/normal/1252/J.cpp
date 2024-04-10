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
int T, n, cnt, ans, sum;
std::vector<int> p[200005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        cnt = 0;
        ans = 0;
        sum = n;
        for (int i = 1; i <= n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            p[x].push_back(y);
        }
        std::priority_queue<int, std::vector<int>, std::greater<int>> que;
        for (int i = n; i; --i)
        {
            sum -= p[i].size();
            for (auto j : p[i])
                que.push(j);
            p[i].clear();
            while (sum + cnt < i)
            {
                ans += que.top();
                que.pop();
                ++cnt;
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}