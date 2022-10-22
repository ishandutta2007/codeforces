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
int n;
struct node
{
    int x, y;
} a[1005];
std::vector<int> S[2][2];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i].x >> a[i].y;
        S[a[i].x & 1][a[i].y & 1].push_back(i);
    }
    while (S[0][0].empty() + S[0][1].empty() + S[1][0].empty() + S[1][1].empty() == 3)
    {
        for (int i = 1; i <= n; ++i)
            a[i].x >>= 1, a[i].y >>= 1;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                S[i][j].clear();
        for (int i = 1; i <= n; ++i)
            S[a[i].x & 1][a[i].y & 1].push_back(i);
    }
    if ((S[0][0].size() + S[1][1].size()) && (S[0][1].size() + S[1][0].size()))
    {
        std::cout << S[0][0].size() + S[1][1].size() << std::endl;
        for (auto i : S[0][0])
            std::cout << i << ' ';
        for (auto i : S[1][1])
            std::cout << i << ' ';
        return 0;
    }
    if (S[0][0].size() && S[1][1].size())
    {
        std::cout << S[0][0].size() << std::endl;
        for (auto i : S[0][0])
            std::cout << i << ' ';
        return 0;
    }
    if (S[0][1].size() && S[1][0].size())
    {
        std::cout << S[0][1].size() << std::endl;
        for (auto i : S[0][1])
            std::cout << i << ' ';
        return 0;
    }
    return 0;
}