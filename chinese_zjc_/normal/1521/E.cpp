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
int T, k, m, a[100005], rk[100005];
std::map<std::pair<int, int>, int> ans;
bool check(int n)
{
    int red = (n / 2) * ((n + 1) / 2), blue = ((n + 1) / 2) * ((n + 1) / 2), yellow = ((n + 1) / 2) * (n / 2);
    if (a[rk[1]] > red + blue || m > red + blue + yellow)
        return false;
    return true;
}
void work(int n)
{
    std::vector<std::pair<int, int>> red, blue, yellow;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            bool A = i & 1, B = j & 1;
            if (!A && B)
                red.push_back(std::make_pair(i, j));
            if (A && B)
                blue.push_back(std::make_pair(i, j));
            if (A && !B)
                yellow.push_back(std::make_pair(i, j));
        }
    for (int i = 1; i <= k; ++i)
    {
        while (red.size() && a[rk[i]])
            ans[red.back()] = rk[i], red.pop_back(), --a[rk[i]];
        while (blue.size() && a[rk[i]])
            ans[blue.back()] = rk[i], blue.pop_back(), --a[rk[i]];
        while (yellow.size() && a[rk[i]])
            ans[yellow.back()] = rk[i], yellow.pop_back(), --a[rk[i]];
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        ans.clear();
        std::cin >> m >> k;
        for (int i = 1; i <= k; ++i)
        {
            std::cin >> a[i];
            rk[i] = i;
        }
        std::sort(rk + 1, rk + 1 + k, [&](const int &A, const int &B) { return a[A] > a[B]; });
        int l = 1, r = m;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
                r = mid;
            else
                l = mid + 1;
        }
        std::cout << l << std::endl;
        work(l);
        for (int i = 1; i <= l; ++i)
            for (int j = 1; j <= l; ++j)
                std::cout << ans[std::make_pair(i, j)] << " \n"[j == l];
    }
    return 0;
}