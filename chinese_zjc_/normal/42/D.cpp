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
int ans[25][25], n, cnt;
bool used[1005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    used[ans[1][2] = ans[2][1] = 1] = true;
    used[ans[1][3] = ans[3][1] = 2] = true;
    used[ans[2][3] = ans[3][2] = 3] = true;
    for (int i = 4; i <= n; ++i)
    {
        for (int c = -1000; c <= 1000; ++c)
        {
            for (int j = 1; j < i - 1; ++j)
                ans[i][j] = ans[j][i] = ans[i - 1][j] + c;
            ans[i][i - 1] = ans[i - 1][i] = ans[i - 2][i - 1] + (ans[i][1] - ans[i - 2][1]);
            bool flag = true;
            for (int j = 1; j < i; ++j)
                if (ans[i][j] < 1 || ans[i][j] > 1000 || used[ans[i][j]])
                    flag = false;
            if (flag)
                break;
        }
        for (int j = 1; j < i; ++j)
            used[ans[i][j]] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            std::cout << ans[i][j] << " \n"[j == n];
    return 0;
}