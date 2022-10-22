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
int l, r, k;
int print(const std::vector<int> &X)
{
    int res = 0;
    for (auto i : X)
        res ^= i;
    std::cout << res << std::endl
              << X.size() << std::endl;
    for (auto i : X)
        std::cout << i << ' ';
    std::cout << std::endl;
    exit(0);
}
const int xx = 720858922694 ^ 720858922695 ^ 720858922696 ^ 720858922697;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> l >> r >> k;
    switch (k)
    {
    default:
        for (int i = l; i + 3 <= r; ++i)
            if (i % 2 == 0)
                print({i, i + 1, i + 2, i + 3});
    case 3:
        for (int i = l; i <= r; i += i & -i)
            if ((i ^ (i + (1ll << (int)log2(i)))) <= r && (i ^ (i + (1ll << (int)log2(i)))) >= l)
                print({i, i + (1ll << (int)log2(i)), i ^ (i + (1ll << (int)log2(i)))});
    case 2:
        for (int i = l; i + 1 <= r; ++i)
            if (i % 2 == 0)
                print({i, i + 1});
        if (l < (l ^ (l + 1)))
            print({l});
        else
            print({l, l + 1});
    case 1:
        print({l});
    }
    return 0;
}