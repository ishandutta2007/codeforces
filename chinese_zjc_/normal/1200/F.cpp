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
const int MOD = 2520;
int n, q, v[1005], ans[1005][MOD], m[1005], to[1005][10];
int dfs(int A, int B)
{
    static bool ins[1005][MOD];
    if (ans[A][B])
        return ans[A][B];
    if (ins[A][B])
    {
        bool vis[1005];
        memset(vis, false, sizeof(vis));
        for (int a = to[A][B % m[A]], b = (B + v[a]) % MOD; a != A || b != B; a = to[a][b % m[a]], b = (b + v[a]) % MOD)
        {
            if (!vis[a])
            {
                vis[a] = true;
                ++ans[A][B];
            }
        }
        if (!vis[A])
        {
            vis[A] = true;
            ++ans[A][B];
        }
        return ans[A][B];
    }
    ins[A][B] = true;
    int tmp = dfs(to[A][B % m[A]], (B + v[to[A][B % m[A]]]) % MOD);
    ans[A][B] = tmp;
    ins[A][B] = false;
    return ans[A][B];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i], v[i] = (v[i] % MOD + MOD) % MOD;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> m[i];
        for (int j = 0; j != m[i]; ++j)
            std::cin >> to[i][j];
    }
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        b = (b % MOD + MOD) % MOD;
        std::cout << dfs(a, (b + v[a]) % MOD) << std::endl;
    }
    return 0;
}