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
int tot, ans, n;
const int SG[] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};
bool vis[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (!vis[i])
        {
            int len = 0;
            for (int j = i; j <= n; j *= i)
            {
                ++len;
                ++tot;
                if (j <= 100000)
                    vis[j] = true;
            }
            ans ^= SG[len];
        }
    }
    ans ^= (n - tot) & 1;
    std::cout << (ans ? "Vasya" : "Petya") << std::endl;
    return 0;
}