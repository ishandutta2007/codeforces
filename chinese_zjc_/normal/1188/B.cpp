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
std::map<int, int> map;
int n, p, k, a[300005], ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> p >> k;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        ans += map[(a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p + p) % p];
        ++map[(a[i] * a[i] % p * a[i] % p * a[i] % p - k * a[i] % p + p) % p];
    }
    std::cout << ans << std::endl;
    return 0;
}