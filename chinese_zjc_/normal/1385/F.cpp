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
int T, n, k, son[200005], add[200005], ans;
bool died[200005];
bool in[200005];
std::vector<int> to[200005];
std::queue<int> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    // bool flag = T == 20000;
    while (T--)
    {
        std::cin >> n >> k;
        // if (T == 19999)
        //     flag &= (n == 10 && k == 3);
        // if (T == 19998)
        //     flag &= (n == 10 && k == 8);
        // if (flag && T == 18543)
        //     std::cout << n << " " << k << std::endl;
        std::fill(son + 1, son + 1 + n, 0);
        std::fill(add + 1, add + 1 + n, 0);
        std::fill(died + 1, died + 1 + n, false);
        for (int i = 1; i <= n; ++i)
            to[i].clear();
        for (int i = 1; i < n; ++i)
        {
            static int x, y;
            std::cin >> x >> y;
            // if (flag && T == 18543)
            //     std::cout << x << " " << y << std::endl;
            to[x].push_back(y);
            to[y].push_back(x);
        }
        if (k == 1)
        {
            // if (!flag)
            std::cout << n - 1 << std::endl;
            continue;
        }
        for (int i = 1; i <= n; ++i)
            if (to[i].size() == 1)
            {
                // std::cout << i << std::endl;
                ++son[to[i].front()];
                ++add[to[i].front()];
                died[i] = true;
            }
        for (int i = 1; i <= n; ++i)
            if (add[i] >= k)
            {
                in[i] = true;
                que.push(i);
            }
        ans = 0;
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            in[now] = false;
            // std::cout << "? " << now << std::endl;
            ans += add[now] / k;
            add[now] %= k;
            if (!add[now] && son[now] + 1u == (int)to[now].size())
            {
                died[now] = true;
                for (int i = 0; i != (int)to[now].size(); ++i)
                {
                    if (died[to[now][i]])
                    {
                        std::swap(to[now][i--], to[now].back());
                        --son[now];
                        to[now].pop_back();
                        continue;
                    }
                    ++son[to[now][i]];
                    ++add[to[now][i]];
                    if (add[to[now][i]] >= k && !in[to[now][i]])
                    {
                        in[to[now][i]] = true;
                        que.push(to[now][i]);
                    }
                }
            }
        }
        // for (int i = 1; i <= n; ++i)
        //     std::cout << died[i] << " \n"[i == n];
        // if (!flag)
        std::cout << ans << std::endl;
    }
    return 0;
}