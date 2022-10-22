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
const double JIAO = PI / 5;
const double LENGTH = 20 * cos(JIAO);
int n, cnt;
std::pair<double, double> pos[505];
std::stringstream point, in, way;
std::pair<double, double> operator+(const std::pair<double, double> &A, const std::pair<double, double> &B)
{
    return {A.first + B.first, A.second + B.second};
}
std::pair<double, double> get(double len, double rou)
{
    return {len * cos(rou), len * sin(rou)};
}
std::ostream &operator<<(std::ostream &A, const std::pair<double, double> &B)
{
    return A << B.first << ' ' << B.second;
}
void work(int left, int now)
{
    if (left == 0)
        return;
    int second, third, fourth, fifth;
    point << (pos[second = ++cnt] = pos[now] + get(LENGTH, 0)) << std::endl;
    point << (pos[third = ++cnt] = pos[second] + get(LENGTH, PI + JIAO)) << std::endl;
    point << (pos[fourth = ++cnt] = pos[third] + get(LENGTH, JIAO * 2)) << std::endl;
    point << (pos[fifth = ++cnt] = pos[fourth] + get(LENGTH, 2 * PI - 2 * JIAO)) << std::endl;
    way << ' ' << second;
    work(left - 1, second);
    way << ' ' << third << ' ' << fourth << ' ' << fifth << ' ' << now;
    in << now << ' ' << third << ' ' << fifth << ' ' << second << ' ' << fourth << std::endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    point << std::fixed << std::setprecision(10);
    std::cin >> n;
    way << 1;
    point << pos[++cnt] << std::endl;
    work(n, 1);
    std::cout << cnt << std::endl
              << point.str();
    std::cout << in.str() << way.str() << std::endl;
    return 0;
}