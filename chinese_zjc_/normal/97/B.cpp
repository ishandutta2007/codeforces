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
std::set<std::pair<int, int>> ans;
std::pair<int, int> a[10005];
int n;
void work(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    work(l, mid - 1);
    work(mid + 1, r);
    for (int i = l; i <= r; ++i)
        ans.insert({a[mid].first, a[i].second});
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; ++i)
        ans.insert(a[i]);
    std::sort(a + 1, a + 1 + n);
    work(1, n);
    std::cout << ans.size() << std::endl;
    for (std::set<std::pair<int, int>>::iterator i = ans.begin(); i != ans.end(); ++i)
        std::cout << i->first << ' ' << i->second << std::endl;
    return 0;
}