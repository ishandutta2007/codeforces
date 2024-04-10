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
int n, m, k, ans, L, U, D, R, x = 1, y = 1;
std::set<int> X[100005], Y[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        X[x].insert(y);
        Y[y].insert(x);
    }
    L = 1;
    U = 1;
    D = n;
    R = m;
    ans = 1;
    {
        std::set<int>::iterator nxt = X[x].upper_bound(y);
        int ty = R;
        if (nxt != X[x].end())
            ty = std::min(ty, *nxt - 1);
        if (ty == 1)
        {
            std::set<int>::iterator nxt = Y[y].upper_bound(x);
            int tx = D;
            if (nxt != Y[y].end())
                tx = std::min(tx, *nxt - 1);
            if (tx == x)
                return std::cout << (ans == n * m - k ? "Yes" : "No") << std::endl, 0;
            ans += tx - x;
            x = tx;
            R = y - 1;
            return std::cout << (ans == n * m - k ? "Yes" : "No") << std::endl, 0;
        }
    }
    while (true)
    {
        {
            std::set<int>::iterator nxt = X[x].upper_bound(y);
            int ty = R;
            if (nxt != X[x].end())
                ty = std::min(ty, *nxt - 1);
            if (ty == y)
                break;
            ans += ty - y;
            y = ty;
            U = x + 1;
        }
        {
            std::set<int>::iterator nxt = Y[y].upper_bound(x);
            int tx = D;
            if (nxt != Y[y].end())
                tx = std::min(tx, *nxt - 1);
            if (tx == x)
                break;
            ans += tx - x;
            x = tx;
            R = y - 1;
        }
        {
            std::set<int>::iterator nxt = X[x].upper_bound(y);
            int ty = L;
            if (nxt != X[x].begin())
                ty = std::max(ty, *--nxt + 1);
            if (ty == y)
                break;
            ans += y - ty;
            y = ty;
            D = x - 1;
        }
        {
            std::set<int>::iterator nxt = Y[y].upper_bound(x);
            int tx = U;
            if (nxt != Y[y].begin())
                tx = std::max(tx, *--nxt + 1);
            if (tx == x)
                break;
            ans += x - tx;
            x = tx;
            L = y + 1;
        }
    }
    std::cout << (ans == n * m - k ? "Yes" : "No") << std::endl;
    return 0;
}