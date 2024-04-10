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
int n, dis[1005];
int query(int t, int i, int j, int k)
{
    static int res;
    std::cout << t << ' ' << i << ' ' << j << ' ' << k << std::endl;
    std::cin >> res;
    return res;
}
std::vector<int> operator+(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res = A;
    res.insert(res.end(), B.begin(), B.end());
    return res;
}
std::vector<int> work(const std::vector<int> &x)
{
    if (x.empty())
        return x;
    std::vector<int> S[2];
    int max = *std::max_element(x.begin(), x.end(), [&](const int &A, const int &B)
                                { return dis[A] < dis[B]; });
    for (auto i : x)
        if (i != max)
            S[query(2, 1, max, i) == 1].push_back(i);
    std::sort(S[0].begin(), S[0].end(), [&](const int &A, const int &B)
              { return dis[A] < dis[B]; });
    std::sort(S[1].begin(), S[1].end(), [&](const int &A, const int &B)
              { return dis[A] > dis[B]; });
    return S[0] + std::vector<int>(1, max) + S[1];
}
void print(const std::vector<int> &x)
{
    std::cout << 0;
    for (auto i : x)
        std::cout << ' ' << i;
    std::cout << std::endl;
    exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 3; i <= n; ++i)
        dis[i] = query(1, 1, 2, i);
    std::vector<int> S[2];
    for (int i = 3; i <= n; ++i)
        S[query(2, 1, 2, i) == 1].push_back(i);
    print(std::vector<int>(1, 1) + work(S[0]) + std::vector<int>(1, 2) + work(S[1]));
    return 0;
}