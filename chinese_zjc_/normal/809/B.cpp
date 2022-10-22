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
int n, k;
bool tmp;
bool query(int x, int y)
{
    static std::string back;
    if (x < 1 || y < 1 || x > n || y > n)
        return true;
    std::cout << 1 << ' ' << x << ' ' << y << std::endl;
    std::cin >> back;
    return back == "TAK";
}
void submit(int x, int y)
{
    std::cout << 2 << ' ' << x << ' ' << y << std::endl;
    exit(0);
}
int find(int l, int r)
{
    if (l > r)
        return -INF;
    while (l != r)
    {
        int mid = (l + r) >> 1;
        if (query(mid, mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    if (query(l, l - 1) && query(l, l + 1))
        return l;
    else
        return -INF;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    if (n == k)
        submit(1, n);
    int ans1 = find(1, n),
        ans2 = std::max(find(1, ans1 - 1), find(ans1 + 1, n));
    submit(ans1, ans2);
    return 0;
}