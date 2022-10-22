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
int n, k, p, fa[100005], depth[100005], sum[100005], ans = 1;
std::vector<int> son[100005];
void init(int now)
{
    for (auto i : son[now])
    {
        if (fa[now] == i)
            continue;
        depth[i] = depth[now] + 1;
        fa[i] = now;
        init(i);
    }
}
int work(int l, int r)
{
    return depth[r] * (r - l) - (sum[r - 1] - sum[l - 1]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k >> p;
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(1);
    std::sort(depth + 1, depth + 1 + n);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + depth[i];
    for (int i = 2; i <= n; ++i)
    {
        int l = i, r = n;
        while (l < r)
        {
            // std::cout << i << std::endl;
            int mid = (l + r + 1) >> 1;
            if (mid - i + 1 <= k && work(i, mid) <= p)
                l = mid;
            else
                r = mid - 1;
        }
        ans = std::max(ans, l - i + 1);
    }
    std::cout << ans << std::endl;
    return 0;
}