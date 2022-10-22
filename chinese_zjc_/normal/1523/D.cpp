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
#include <random>
#include <chrono>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int n, m, p, v[200005], pre[1 << 15], pop[1 << 15], ans1;
bool ans2[60];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> p;
    for (int i = 0; i != n; ++i)
    {
        static std::bitset<60> b;
        std::cin >> b;
        v[i] = b.to_ullong();
    }
    for (int i = 1; i != 1 << p; ++i)
        pop[i] = pop[i & (i - 1)] + 1;
    for (int TIM = 0; TIM != 100; ++TIM)
    {
        std::vector<int> h;
        for (int p = Rand() % n, i = 0; i != m; ++i)
            if (v[p] >> i & 1)
                h.push_back(i);
        std::fill(pre, pre + (1 << h.size()), 0);
        for (int i = 0; i != n; ++i)
        {
            int x = 0;
            for (int j = 0; j != (int)h.size(); ++j)
                x |= (v[i] >> h[j] & 1) << j;
            ++pre[x];
        }
        for (int i = 0; i != (int)h.size(); ++i)
            for (int j = 1 << h.size(); j--;)
            {
                j &= ~(1 << i);
                pre[j] += pre[j | 1 << i];
            }
        for (int i = (1 << h.size()); i--;)
            if (pre[i] >= (n + 1) / 2 && ans1 < pop[i])
            {
                ans1 = pop[i];
                std::fill(ans2, ans2 + m, false);
                for (int j = 0; j != (int)h.size(); ++j)
                    if (i >> j & 1)
                        ans2[h[j]] = true;
            }
    }
    for (int i = m; i--;)
        std::cout << ans2[i];
    std::cout << std::endl;
    return 0;
}