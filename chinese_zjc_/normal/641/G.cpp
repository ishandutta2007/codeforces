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
const int MOD = 1000000007;
int n, k, ans = 1;
std::map<int, int> v[10005];
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != k; ++i)
        for (int j = i + 1; j != k; ++j)
        {
            ++v[i][i];
            ++v[j][j];
            --v[i][j];
            --v[j][i];
        }
    for (int i = k; i != n; ++i)
    {
        for (int j = 0; j != k; ++j)
        {
            static int x;
            std::cin >> x;
            --x;
            ++v[i][i];
            ++v[x][x];
            --v[i][x];
            --v[x][i];
        }
    }
    for (int i = 1; i != n; ++i)
        v[i].erase(0);
    v[0].clear();
    for (int i = 1; i != n; ++i)
        for (auto &j : v[i])
            j.second = (j.second % MOD + MOD) % MOD;
    // for (int i = 1; i != n; ++i, std::cout << std::endl)
    //     for (int j = 1; j != n; ++j)
    //         std::cout << v[i][j] << " ";
    for (int i = n; --i;)
    {
        for (int j = i; --j;)
            if (v[j].find(i) != v[j].end())
            {
                int tmp = (MOD - v[j][i]) * power(v[i][i], MOD - 2) % MOD;
                for (auto k : v[i])
                    v[j][k.first] = (v[j][k.first] + k.second * tmp) % MOD;
                v[j].erase(i);
            }
    }
    for (int i = 1; i != n; ++i)
        ans = ans * v[i][i] % MOD;
    std::cout << ans << std::endl;
    return 0;
}