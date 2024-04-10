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
int n, m, a[10], b[10], c[10][10], dp[5][5][5][5][5][5][5], f[10];
void update(int &A, const int &B) { A = std::min(A, B); }
int d(int x) { return x >= INF / 2 ? -1 : x; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= m; ++i)
        std::cin >> b[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]][0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        for (f[1] = 0; f[1] <= a[1]; ++f[1])
            for (f[2] = 0; f[2] <= a[2]; ++f[2])
                for (f[3] = 0; f[3] <= a[3]; ++f[3])
                    for (f[4] = 0; f[4] <= a[4]; ++f[4])
                        for (f[5] = 0; f[5] <= a[5]; ++f[5])
                            for (f[6] = 0; f[6] <= a[6]; ++f[6])
                            {
                                dp[f[1]][f[2]][f[3]][f[4]][f[5]][f[6]][b[i]] =
                                    *std::min_element(dp[f[1]][f[2]][f[3]][f[4]][f[5]][f[6]],
                                                      dp[f[1]][f[2]][f[3]][f[4]][f[5]][f[6]] + b[i - 1] + 1);
                                std::fill(dp[f[1]][f[2]][f[3]][f[4]][f[5]][f[6]],
                                          dp[f[1]][f[2]][f[3]][f[4]][f[5]][f[6]] + b[i], INF);
                            }
        // for (f[1] = 0; f[1] <= a[1]; ++f[1], std::cout << std::endl)
        //     for (f[2] = 0; f[2] <= a[2]; ++f[2], std::cout << ',')
        //         std::cout << d(dp[f[1]][f[2]][0][0][0][0][b[i]]);
        // std::cout << std::endl;
        for (int j = 1; j <= n; ++j)
        {
            for (f[1] = 0; f[1] <= a[1]; ++f[1])
                for (f[2] = 0; f[2] <= a[2]; ++f[2])
                    for (f[3] = 0; f[3] <= a[3]; ++f[3])
                        for (f[4] = 0; f[4] <= a[4]; ++f[4])
                            for (f[5] = 0; f[5] <= a[5]; ++f[5])
                                for (f[6] = 0; f[6] <= a[6]; ++f[6])
                                    for (int k = 0; k <= b[i]; ++k)
                                        for (int l = 1; l <= std::min(f[j], k); ++l)
                                            update(dp[f[1] - (1 == j) * l][f[2] - (2 == j) * l]
                                                     [f[3] - (3 == j) * l][f[4] - (4 == j) * l]
                                                     [f[5] - (5 == j) * l][f[6] - (6 == j) * l][k - l],
                                                   dp[f[1]][f[2]][f[3]][f[4]][f[5]][f[6]][k] + c[j][i]);
        }
    }
    // for (f[1] = 0; f[1] <= a[1]; ++f[1], std::cout << std::endl)
    //     for (f[2] = 0; f[2] <= a[2]; ++f[2], std::cout << std::endl)
    //         for (int k = 0; k <= b[m]; ++k, std::cout << ',')
    //             std::cout << d(dp[f[1]][f[2]][0][0][0][0][k]);
    std::cout << d(*std::min_element(dp[0][0][0][0][0][0], dp[0][0][0][0][0][0] + b[m] + 1)) << std::endl;
    return 0;
}