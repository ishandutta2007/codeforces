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
std::vector<int> son[200005];
int n, v[200005], siz[3][200005], depth[200005], fa[200005], ans;
void init(int now)
{
    siz[depth[now] & 1][now] = siz[2][now] = 1;
    for (int i = 0; i != (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            std::swap(son[now][i--], son[now].back());
            son[now].pop_back();
            continue;
        }
        fa[son[now][i]] = now;
        depth[son[now][i]] = depth[now] + 1;
        init(son[now][i]);
        siz[0][now] += siz[0][son[now][i]];
        siz[1][now] += siz[1][son[now][i]];
        siz[2][now] += siz[2][son[now][i]];
    }
}
void dfs(int now, int num0, int num1)
{
    // std::cout << now << ' ' << num0 << ' ' << num1 << std::endl;
    ans += (num0 - num1 + MOD) * v[now] % MOD * siz[2][now] % MOD;
    ans += n * v[now] % MOD;
    bool d = depth[now] & 1;
    for (auto i : son[now])
    {
        ans += (siz[d][i] - siz[!d][i] + MOD) * v[now] % MOD * (n - siz[2][i]) % MOD;
        // std::cout << siz[!d][now] << ' ' << siz[!d][i] << std::endl;
        dfs(i, num1 + siz[!d][now] - siz[!d][i], num0 + siz[d][now] - siz[d][i]);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> v[i], v[i] = (v[i] + MOD) % MOD;
    for (int i = 1; i < n; ++i)
    {
        static int a, b;
        std::cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(1);
    dfs(1, 0, 0);
    std::cout << ans % MOD << std::endl;
    return 0;
}