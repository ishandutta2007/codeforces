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
struct BIT
{
    int sum[300005];
    void add(int pos, int val)
    {
        while (pos <= 300000)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        pos = std::max(0ll, std::min(300000ll, pos));
        int res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
} A, B, C;
int n, x, ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> x;
        ans += x * (i - 1) - C.query(x);
        for (int j = 0; x * j <= 300000; ++j)
            ans += B.query(x * j, x * j + x - 1) - A.query(x * j, x * j + x - 1) * x * j;
        A.add(x, 1);
        B.add(x, x);
        for (int j = 1; x * j <= 300000; ++j)
            C.add(x * j, x);
        std::cout << ans << " \n"[i == n];
    }
    return 0;
}