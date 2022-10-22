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
int n1, n2, n, dp[55][55];
std::vector<std::pair<int, int>> to[26];
bool can1[55][55][26], can2[55][55][26];
char s1[55], s2[55];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (s1 + 1) >> (s2 + 1);
    n1 = strlen(s1 + 1);
    n2 = strlen(s2 + 1);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        static std::string tmp;
        std::cin >> tmp;
        to[tmp[0] - 'a'].push_back(std::make_pair(tmp[3] - 'a', tmp[4] - 'a'));
    }
    for (int i = 1; i <= n1; ++i)
    {
        can1[i][i][s1[i] - 'a'] = true;
        for (int j = i - 1; j; --j)
            for (int k = 0; k != 26; ++k)
                for (auto l : to[k])
                    for (int o = j; o != i; ++o)
                        can1[j][i][k] |= can1[j][o][l.first] && can1[o + 1][i][l.second];
    }
    for (int i = 1; i <= n2; ++i)
    {
        can2[i][i][s2[i] - 'a'] = true;
        for (int j = i - 1; j; --j)
            for (int k = 0; k != 26; ++k)
                for (auto l : to[k])
                    for (int o = j; o != i; ++o)
                        can2[j][i][k] |= can2[j][o][l.first] && can2[o + 1][i][l.second];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n1; ++i)
        for (int j = 1; j <= n2; ++j)
            for (int k = i; k; --k)
                for (int l = j; l; --l)
                    for (int o = 0; o != 26; ++o)
                        if (can1[k][i][o] && can2[l][j][o])
                            dp[i][j] = std::min(dp[i][j], dp[k - 1][l - 1] + 1);
    std::cout << (dp[n1][n2] >= INF / 4 ? -1 : dp[n1][n2]) << std::endl;
    return 0;
}