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
const int MOD = 998244353;
int n, m, a[1005][1005], dp[1005][1005], lin[3], col[3], dpsum;
std::map<int, std::vector<std::pair<int, int>>> map;
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
int inv(int x) { return power(x, MOD - 2); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> a[i][j], map[a[i][j]].push_back(std::make_pair(i, j));
    std::pair<int, int> ans;
    std::cin >> ans.first >> ans.second;
    for (auto i : map)
    {
        for (auto j : i.second)
        {
            dp[j.first][j.second] = (dpsum +
                                     lin[2] +
                                     (MOD - 2) * j.first % MOD * lin[1] % MOD +
                                     j.first * j.first % MOD * lin[0] % MOD +
                                     col[2] +
                                     (MOD - 2) * j.second % MOD * col[1] % MOD +
                                     j.second * j.second % MOD * col[0] % MOD) *
                                    inv(lin[0]) %
                                    MOD;
        }
        for (auto j : i.second)
        {
            lin[0] = (lin[0] + 1) % MOD;
            lin[1] = (lin[1] + j.first) % MOD;
            lin[2] = (lin[2] + j.first * j.first) % MOD;
            col[0] = (col[0] + 1) % MOD;
            col[1] = (col[1] + j.second) % MOD;
            col[2] = (col[2] + j.second * j.second) % MOD;
            dpsum = (dpsum + dp[j.first][j.second]) % MOD;
            if (ans.first == j.first && ans.second == j.second)
            {
                std::cout << dp[j.first][j.second] << std::endl;
                return 0;
            }
        }
    }
    return 0;
}