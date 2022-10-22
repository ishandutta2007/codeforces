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
int n, a[200005], ans;
std::priority_queue<int, std::vector<int>, std::greater<int>> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], que.push(a[i]);
    if (que.size() % 2 == 0)
    {
        int sum = 0;
        for (int i = 1; i <= 2; ++i)
        {
            sum += que.top();
            que.pop();
        }
        ans += sum;
        que.push(sum);
    }
    while (que.size() > 2)
    {
        int sum = 0;
        for (int i = 1; i <= 3; ++i)
        {
            sum += que.top();
            que.pop();
        }
        que.push(sum);
        ans += sum;
    }
    std::cout << ans << std::endl;
    return 0;
}