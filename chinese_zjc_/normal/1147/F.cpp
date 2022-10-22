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
int T, n, m, a[2005][2005], st, nxt[4005], rk[2005][2005];
char c;
std::vector<int> pos[2005];
std::queue<int> que;
void init(bool t)
{
    memset(nxt, 0, sizeof(nxt));
    for (int i = 1; i <= n; ++i)
    {
        que.push(i);
        pos[i].clear();
        for (int j = 1; j <= n; ++j)
            pos[i].push_back(j);
        std::sort(pos[i].begin(), pos[i].end(), [&](const int &A, const int &B) { return (a[i][A] > a[i][B]) ^ t; });
    }
    for (int i = 1; i <= n; ++i)
    {
        static std::vector<int> sa;
        sa.clear();
        for (int j = 1; j <= n; ++j)
            sa.push_back(j);
        std::sort(sa.begin(), sa.end(), [&](const int &A, const int &B) { return (a[A][i] > a[B][i]) ^ t; });
        for (int j = 1; j <= n; ++j)
            rk[i][sa[j - 1]] = j;
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         std::cout << rk[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        while (!nxt[now])
        {
            int to = pos[now].back();
            pos[now].pop_back();
            if (!nxt[to + n] || rk[to][now] < rk[to][nxt[to + n]])
            {
                if (nxt[to + n])
                {
                    nxt[nxt[to + n]] = 0;
                    que.push(nxt[to + n]);
                }
                nxt[to + n] = now;
                nxt[now] = to + n;
            }
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                std::cin >> a[i][j];
            }
        }
        std::cout << "B" << std::endl;
        std::cin >> c >> st;
        if (c == 'D')
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    a[i][j] = -a[i][j];
                }
            }
        init(st > n);
        // for (int i = 1; i <= n + n; ++i)
        // {
        //     std::cout << nxt[i] << " \n"[i == n + n];
        // }
        while (~st)
        {
            std::cout << nxt[st] << std::endl;
            std::cin >> st;
        }
    }
    return 0;
}