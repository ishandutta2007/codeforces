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
int n, m, k, in[100005];
std::string s[100005];
std::map<std::string, int> map;
std::vector<int> to[100005];
std::queue<int> que;
std::vector<int> ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> s[i];
        map[s[i]] = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        static std::string st;
        static int p;
        std::cin >> st >> p;
        for (int j = 0; j != k; ++j)
            if (s[p][j] != '_' && s[p][j] != st[j])
                return std::cout << "NO" << std::endl, 0;
        for (int j = 0; j != 1 << k; ++j)
        {
            std::string t;
            for (int l = 0; l != k; ++l)
                if (j & 1 << l)
                    t.push_back(st[l]);
                else
                    t.push_back('_');
            std::map<std::string, int>::iterator iter = map.find(t);
            if (iter != map.end() && iter->second != p)
            {
                to[p].push_back(iter->second);
                ++in[iter->second];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        if (!in[i])
            que.push(i);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        ans.push_back(now);
        for (int i = 0; i != (int)to[now].size(); ++i)
            if (!--in[to[now][i]])
                que.push(to[now][i]);
    }
    if ((int)ans.size() != n)
        return std::cout << "NO" << std::endl, 0;
    std::cout << "YES" << std::endl;
    for (int i = 0; i != n; ++i)
        std::cout << ans[i] << " \n"[i + 1 == n];
    return 0;
}