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
int sum[10000005], n, ans = 1;
bool vis[10000005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        ++sum[x];
    }
    for (int i = 10000000; i; --i)
        sum[i] += sum[i + 1];
    for (int i = 2; i <= 10000000; ++i)
        if (!vis[i])
        {
            int tmp = 0;
            for (int j = i; j <= 10000000; j *= i)
                for (int k = j; k <= 10000000; k += j)
                    tmp += sum[k];
            for (int j = i + i; j <= 10000000; j += i)
                vis[j] = true;
            int &l = ans, r = INF;
            while (l < r)
            {
                int mid = (l + r) >> 1, s = 0;
                for (int j = i; j <= mid; j *= i)
                    s += mid / j;
                if (s < tmp)
                    l = mid + 1;
                else
                    r = mid;
            }
        }
    std::cout << ans << std::endl;
    return 0;
}