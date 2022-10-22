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
struct node
{
    int max[15], min[15], size;
    friend bool operator<(const node &A, const node &B)
    {
        for (int i = 1; i <= k; ++i)
            if (!(A.max[i] < B.min[i]))
                return false;
        return true;
    }
};
std::set<node> g;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        node t;
        t.size = 1;
        for (int j = 1; j <= k; ++j)
            std::cin >> t.max[j];
        std::copy(t.max + 1, t.max + 1 + k, t.min + 1);
        std::set<node>::iterator it = g.find(t);
        while (it != g.end())
        {
            t.size += it->size;
            for (int j = 1; j <= k; ++j)
                t.max[j] = std::max(t.max[j], it->max[j]);
            for (int j = 1; j <= k; ++j)
                t.min[j] = std::min(t.min[j], it->min[j]);
            g.erase(it);
            it = g.find(t);
        }
        g.insert(t);
        std::cout << g.rbegin()->size << std::endl;
    }
    return 0;
}