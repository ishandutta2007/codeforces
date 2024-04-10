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
int n, x[1 << 16];
std::vector<int> c[1 << 16];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i != n; ++i)
    {
        std::cout << "XOR " << 1 << ' ' << i + 1 << std::endl;
        std::cin >> x[i];
        c[x[i]].push_back(i);
    }
    c[0].push_back(0);
    for (int i = 0; i != n; ++i)
    {
        if (c[i].size() >= 2)
        {
            static int z;
            std::cout << "OR " << c[i][0] + 1 << ' ' << c[i][1] + 1 << std::endl;
            std::cin >> z;
            z ^= x[c[i][0]];
            std::cout << '!';
            for (int j = 0; j != n; ++j)
                std::cout << ' ' << (z ^ x[j]);
            std::cout << std::endl;
            return 0;
        }
    }
    int p[2] = {c[1][0], c[2][0]}, r[2];
    std::cout << "AND " << 1 << ' ' << p[0] + 1 << std::endl;
    std::cin >> r[0];
    std::cout << "AND " << 1 << ' ' << p[1] + 1 << std::endl;
    std::cin >> r[1];
    for (int i = 0; i != n; ++i)
    {
        if ((i & (i ^ 1)) == r[0] && (i & (i ^ 2)) == r[1])
        {
            std::cout << '!';
            for (int j = 0; j != n; ++j)
                std::cout << ' ' << (x[j] ^ i);
            std::cout << std::endl;
            return 0;
        }
    }
    return 0;
}