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
int T, l, r;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res *= A;
        B >>= 1;
        A *= A;
    }
    return res;
}
int Log2(int x)
{
    static int tmp[] = {1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7,
                        1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15,
                        1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23,
                        1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30, 1 << 31};
    return std::lower_bound(tmp, tmp + 32, x) - tmp;
}
int popcount(int x)
{
    return x ? popcount(x & (x - 1)) + 1 : 0;
}
int doit(int A, int B)
{
    if ((A & -A) < (B & -B))
        std::swap(A, B);
    int LA = A & (A - 1), LB = B & (B - 1);
    if (LA & LB)
        return 0;
    // std::cout << std::bitset<32>(A) << " " << std::bitset<32>(B) << std::endl;
    // std::cout << Log2(B & -B) << std::endl;
    // std::cout << Log2((A & -A) / (B & -B)) << std::endl;
    // std::cout << std::bitset<32>(LB % (A & -A) / (B & -B)) << std::endl;
    // std::cout << popcount(LB % (A & -A) / (B & -B)) << std::endl;
    // std::cout << power(3, Log2(B & -B)) * power(2, Log2((A & -A) / (B & -B)) - popcount(LB % (A & -A) / (B & -B))) << std::endl;
    return power(3, Log2(B & -B)) * power(2, Log2((A & -A) / (B & -B)) - popcount(LB % (A & -A) / (B & -B)));
}
int work(int lim1, int lim2)
{
    int res = 0;
    for (int i = 0; 1 << i <= lim1; ++i)
        if (lim1 & 1 << i)
        {
            int tmp = lim2;
            for (int j = 0; 1 << j <= tmp; ++j)
                if (tmp & 1 << j)
                {
                    res += doit(lim1, tmp);
                    tmp ^= 1 << j;
                }
            lim1 ^= 1 << i;
        }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> l >> r;
        ++r;
        // std::cout << work(3, 4) << std::endl;
        std::cout << work(r, r) - work(l, r) * 2 + work(l, l) << std::endl;
    }
    return 0;
}