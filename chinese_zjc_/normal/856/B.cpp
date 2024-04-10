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
#include <random>
#include <chrono>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int T, n, ans, dp[1000005][2], fa[1000005], to1[128], to2[128], ts[1000005][26], cnt, root;
std::map<std::pair<int, int>, int> map;
std::vector<int> son[1000005];
std::string s[1000005];
std::vector<std::pair<int, int>> hash[1000005];
void add(int now, int pos, std::string &str)
{
    if (pos == (int)str.size())
        return;
    if (!~ts[now][str[pos] - 'a'])
        ts[now][str[pos] - 'a'] = cnt++;
    add(ts[now][str[pos] - 'a'], pos + 1, str);
}
void dfs(int now)
{
    // std::cout << now << std::endl;
    dp[now][0] = 0;
    dp[now][1] = 1;
    for (auto i : son[now])
    {
        // std::cout << now << ' ' << i << std::endl;
        dfs(i);
        dp[now][0] += dp[i][1];
        dp[now][1] += dp[i][0];
    }
    dp[now][1] = std::max(dp[now][0], dp[now][1]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::stringstream res;
    std::cin >> T;
    memset(ts, -1, sizeof(ts));
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != cnt; ++i)
            memset(ts[i], -1, sizeof(ts[i]));
        cnt = 0;
        ans = 0;
        root = cnt++;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> s[i];
            add(root, 0, s[i]);
        }
        for (int i = 0; i != cnt; ++i)
            son[i].clear(), fa[i] = -1;
        for (int i = 1; i <= n; ++i)
            for (int j = 2, b1 = ts[root][s[i][0] - 'a'], b2 = root; j <= (int)s[i].size(); ++j)
            {
                b1 = ts[b1][s[i][j - 1] - 'a'];
                b2 = ts[b2][s[i][j - 1] - 'a'];
                if (~b2)
                {
                    if (!~fa[b1])
                    {
                        fa[b1] = b2;
                        son[b2].push_back(b1);
                        // std::cout << b1 << ' ' << b2 << std::endl;
                    }
                }
                else
                    break;
            }
        // if (T == 0 && n == 1)
        //     std::cout << 1000.0 * clock() / CLOCKS_PER_SEC << std::endl;
        // for (int i = 1; i <= n; ++i)
        //     for (int j = 1; j <= s[i].size(); ++j)
        //         std::cout << s[i].substr(0, j) << std::endl;
        // std::cout << map.size() << std::endl;
        for (int i = 1; i != cnt; ++i)
            if (!~fa[i])
            {
                dfs(i);
                ans += dp[i][1];
                // std::cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << std::endl;
            }
        res << ans << std::endl;
        // if (ans == 59 && T == 33069 - 785)
        // {
        //     for (int i = 1; i <= n; ++i)
        //         std::cout << s[i] << std::endl;
        // }
    }
    std::cout << res.str();
    return 0;
}