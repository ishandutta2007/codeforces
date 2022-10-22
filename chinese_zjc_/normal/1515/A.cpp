//This Code was made by Chinese_zjc_.
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, T, x, sum, a[105], count[10005];
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        bool flag = true;
        sum = 0;
        memset(count, 0, sizeof(count));
        std::cin >> n >> x;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            ++count[a[i]];
            sum += a[i];
        }
        if (count[x] == n || sum == x)
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        ans.clear();
        sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            int Max = 0;
            for (int j = 1; j <= 100; ++j)
                if (count[j] > count[Max] && sum + j != x)
                    Max = j;
            if (!Max)
                flag = false;
            ans.push_back(Max);
            sum += Max;
            --count[Max];
        }
        if (!flag)
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "YES" << std::endl;
        for (auto i : ans)
            std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}