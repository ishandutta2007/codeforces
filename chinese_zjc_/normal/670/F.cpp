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
std::string n, k;
int c[10];
void solve(int len)
{
    std::fill(c, c + 10, 0);
    for (auto i : n)
        ++c[i - '0'];
    for (auto i : k)
        if (--c[i - '0'] < 0)
            return;
    for (auto i : std::to_string(len))
        if (--c[i - '0'] < 0)
            return;
    std::string A, B;
    for (int i = 1; i <= 9; ++i)
        if (c[i])
        {
            A += '0' + i;
            --c[i];
            break;
        }
    if (A.empty())
        A = "z";
    for (int i = 0; i <= 9; ++i)
        while (c[i]--)
            A += '0' + i;
    B = A;
    A.insert(std::lower_bound(A.begin() + 1, A.end(), k.front()) - A.begin(), k);
    B.insert(std::upper_bound(B.begin() + 1, B.end(), k.front()) - B.begin(), k);
    if (k.front() != '0')
    {
        std::fill(c, c + 10, 0);
        for (auto i : n)
            ++c[i - '0'];
        for (auto i : k)
            if (--c[i - '0'] < 0)
                return;
        for (auto i : std::to_string(len))
            if (--c[i - '0'] < 0)
                return;
        std::string C = k;
        for (int i = 0; i <= 9; ++i)
            while (c[i]--)
                C += '0' + i;
        std::cout << std::min({A, B, C}) << std::endl;
        exit(0);
    }
    std::cout << std::min(A, B) << std::endl;
    exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    if ((n == "10" || n == "01") && k == "0")
        return std::cout << 0 << std::endl, 0;
    for (int i = 1; i <= (int)n.size(); ++i)
        if ((int)n.size() - (int)std::to_string(i).size() == i)
            solve(i);
    return 0;
}