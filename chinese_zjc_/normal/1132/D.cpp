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
const int INF = 0x3ffffffffff;
int n, k, a[200005], b[200005];
bool check(int val)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
    static int tmp[200005];
    for (int i = 1; i <= n; ++i)
        que.push(std::make_pair((tmp[i] = a[i]) / b[i], i));
    for (int i = 0; i < k; ++i)
    {
        std::pair<int, int> now = que.top();
        que.pop();
        if (now.first < i)
            return false;
        // std::cout << now.first << ' ' << now.second << std::endl;
        que.push(std::make_pair((tmp[now.second] += val) / b[now.second], now.second));
    }
    // std::cout << que.top().first << std::endl;
    if (que.top().first < k)
        return false;
    else
        return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    --k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    int l = 0, r = INF;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << (l == INF ? -1 : l) << std::endl;
    return 0;
}