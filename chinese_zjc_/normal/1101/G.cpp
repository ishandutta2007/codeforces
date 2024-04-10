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
int n, s[200005], a[60], ans;
void insert(int x)
{
    for (int i = 32; i--;)
    {
        if (x & 1 << i)
        {
            if (!a[i])
            {
                ++ans;
                a[i] = x;
                for (int j = 0; j != i; ++j)
                    if (a[i] & 1 << j)
                        a[i] ^= a[j];
                for (int j = i + 1; j != 32; ++j)
                    if (a[j] & 1 << i)
                        a[j] ^= a[i];
                return;
            }
            else
                x ^= a[i];
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> s[i], s[i] ^= s[i - 1], insert(s[i]);
    std::cout << (s[n] ? ans : -1) << std::endl;
    return 0;
}