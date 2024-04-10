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
#include <random>
#include <chrono>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
std::pair<double, double> operator+(const std::pair<double, double> &A, const std::pair<double, double> &B)
{
    return std::make_pair(A.first + B.first, A.second + B.second);
}
int n;
double out;
std::vector<std::pair<double, double>> ans;
std::pair<double, double> get(double len, double rou)
{
    return std::make_pair(len * cos(rou), len * sin(rou));
}
// std::set<double> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(3);
    if (n <= 4)
        return std::cout << "No solution" << std::endl, 0;
    ans.push_back({0, 0});
    out = PI * 2 / n;
    while (true)
    {
        for (int i = 1; i < n - 1; ++i)
        {
            double len = Rand() * 1.0 / ULLONG_MAX * 999.0 + 1;
            ans.push_back(ans.back() + get(len, i * out));
        }
        if (ans.back().second > 0 && -ans.back().second / sin(2 * PI - out) <= 1000)
        {
            ans.push_back(ans.back() + get(-ans.back().second / sin(2 * PI - out), 2 * PI - out));
            if (ans.back().first <= -1 && ans.back().first >= -1000)
            {
                for (auto i : ans)
                    std::cout << i.first << ' ' << i.second << std::endl;
                break;
            }
        }
        ans.clear(), ans.push_back({0, 0});
    }
    return 0;
}