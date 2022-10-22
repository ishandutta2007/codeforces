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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
unsigned int val[1000005];
int n, m, hash[1000005], ans;
std::set<int> frd[1000005];
std::map<int, int> map;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        val[i] = Rand();
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        hash[x] += val[y];
        hash[y] += val[x];
        frd[x].insert(y);
        frd[y].insert(x);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (auto j : frd[i])
        {
            if (j >= i)
                break;
            if (hash[j] - val[i] == hash[i] - val[j])
                ++ans;
        }
        ans += map[hash[i]];
        ++map[hash[i]];
    }
    std::cout << ans << std::endl;
    return 0;
}