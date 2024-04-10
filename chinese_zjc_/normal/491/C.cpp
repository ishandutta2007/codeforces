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
int n, m, v[505][505], lm[505], rm[505], d[505], lst[505], matchl[505], matchr[505];
bool visl[505], visr[505];
char c1[2000005], c2[2000005];
std::string to = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
void Match(int now)
{
    static int tmp;
    while (now)
    {
        tmp = matchl[lst[now]];
        matchl[lst[now]] = now;
        matchr[now] = lst[now];
        now = tmp;
    }
}
void bfs(int s)
{
    std::fill(visl + 1, visl + 1 + n, false);
    std::fill(visr + 1, visr + 1 + n, false);
    std::fill(d + 1, d + 1 + n, INF);
    std::queue<int> que;
    que.push(s);
    while (true)
    {
        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            visl[now] = true;
            for (int i = 1; i <= n; ++i)
                if (!visr[i] && lm[now] + rm[i] - v[now][i] < d[i])
                {
                    d[i] = lm[now] + rm[i] - v[now][i];
                    lst[i] = now;
                    if (!d[i])
                    {
                        visr[i] = true;
                        if (!matchr[i])
                            return Match(i);
                        else
                            que.push(matchr[i]);
                    }
                }
        }
        int down = INF;
        for (int i = 1; i <= n; ++i)
            if (!visr[i])
                down = std::min(down, d[i]);
        for (int i = 1; i <= n; ++i)
        {
            if (visl[i])
                lm[i] -= down;
            if (visr[i])
                rm[i] += down;
            else
                d[i] -= down;
        }
        for (int i = 1; i <= n; ++i)
            if (!visr[i] && !d[i])
            {
                visr[i] = true;
                if (!matchr[i])
                    return Match(i);
                else
                    que.push(matchr[i]);
            }
    }
}
int KM()
{
    for (int i = 1; i <= n; ++i)
        lm[i] = *std::max_element(v[i] + 1, v[i] + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        bfs(i);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        res += lm[i] + rm[i];
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            v[i][j] = 0;
    for (int i = 1; i <= m; ++i)
        std::cin >> c1[i];
    for (int i = 1; i <= m; ++i)
        std::cin >> c2[i];
    for (int i = 1; i <= m; ++i)
        ++v[to.find(c1[i]) + 1][to.find(c2[i]) + 1];
    std::cout << KM() << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << to[matchl[i] - 1];
    std::cout << std::endl;
    return 0;
}