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
const int MOD = 1000000007;
std::map<int, int> x, y;
int fa[200005], siz[200005], ans, cnt, n;
bool huan[200005];
int find(int now)
{
    return now == fa[now] ? now : fa[now] = find(fa[now]);
}
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n + n; ++i)
        fa[i] = i, siz[i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        static int X, Y;
        std::cin >> X >> Y;
        if (!x[X])
            x[X] = ++cnt;
        if (!y[Y])
            y[Y] = ++cnt;
        if (find(x[X]) == find(y[Y]))
            huan[find(x[X])] = true;
        else
        {
            siz[find(x[X])] += siz[find(y[Y])];
            huan[find(x[X])] |= huan[find(y[Y])];
            fa[find(y[Y])] = find(x[X]);
        }
    }
    ans = 1;
    // for (int i = 1; i <= cnt; ++i)
    //     std::cout << siz[i] << " " << huan[i] << " " << fa[i] << std::endl;
    for (int i = 1; i <= cnt; ++i)
        if (find(i) == i)
            ans = ans * (power(2, siz[i]) - !huan[i]) % MOD;
    std::cout << ans << std::endl;
    return 0;
}