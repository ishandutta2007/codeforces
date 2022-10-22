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
int hash(char A, char B, char C, char D, char E, char F, char G, char H, char I)
{
    return (A == 'O') << 0 | (B == 'O') << 1 | (C == 'O') << 2 |
           (D == 'O') << 3 | (E == 'O') << 4 | (F == 'O') << 5 |
           (G == 'O') << 6 | (H == 'O') << 7 | (I == 'O') << 8;
}
const int A[] = {
    hash('.', '.', '.', '.', '.', '.', '.', '.', '.'),
    hash('.', '.', '.', '.', 'O', '.', '.', '.', '.'),
    hash('.', '.', 'O', '.', '.', '.', 'O', '.', '.'),
    hash('O', '.', '.', '.', '.', '.', '.', '.', 'O'),
    hash('.', '.', 'O', '.', 'O', '.', 'O', '.', '.'),
    hash('O', '.', '.', '.', 'O', '.', '.', '.', 'O'),
    hash('O', '.', 'O', '.', '.', '.', 'O', '.', 'O'),
    hash('O', '.', 'O', '.', 'O', '.', 'O', '.', 'O'),
    hash('O', '.', 'O', 'O', '.', 'O', 'O', '.', 'O'),
    hash('O', 'O', 'O', '.', '.', '.', 'O', 'O', 'O')};
const int B[] = {0, 0, +1, -1, +1, -1, 0, 0, +1, -1};
int n, m, v[255][255], g[255];
char c[1005][1005];
bool all(int now)
{
    for (int i = 1; i <= n; ++i)
        if (v[i][now] < 0)
            return false;
    return true;
}
int work(int now)
{
    int p[255];
    memset(p, 0, sizeof(p));
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i >= 2 && v[i - 1][now - 1] >= 0 && v[i - 1][now] >= 0 && v[i][now - 1] >= 0 && v[i][now] >= 0)
            p[i] = (p[i] + p[i - 2]) % MOD;
        if (i && v[i][now - 1] <= 0 && v[i][now] <= 0)
            p[i] = (p[i] + p[i - 1]) % MOD;
    }
    return p[n];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= 4 * n + 1; ++i)
        for (int j = 1; j <= 4 * m + 1; ++j)
            std::cin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            v[i][j] = B[std::find(A, A + 10,
                                  hash(c[i * 4 - 2][j * 4 - 2], c[i * 4 - 2][j * 4 - 1], c[i * 4 - 2][j * 4 - 0],
                                       c[i * 4 - 1][j * 4 - 2], c[i * 4 - 1][j * 4 - 1], c[i * 4 - 1][j * 4 - 0],
                                       c[i * 4 - 0][j * 4 - 2], c[i * 4 - 0][j * 4 - 1], c[i * 4 - 0][j * 4 - 0])) -
                        A];
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= m; ++j)
    //         std::cout << v[i][j] << " \n"[j == m];
    g[0] = 1;
    for (int i = 1; i <= m; ++i)
    {
        if (i >= 2)
            g[i] = (g[i] + g[i - 2] * (work(i) - (n % 2 == 0 && all(i - 1) && all(i)))) % MOD;
        if (all(i) && n % 2 == 0)
            g[i] = (g[i] + g[i - 1]) % MOD;
        // std::cout << g[i] << std::endl;
    }
    std::cout << g[m] << std::endl;
    return 0;
}