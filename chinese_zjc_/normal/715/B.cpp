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
const int INF = 1000000000000000000;
int n, m, l, s, t, dis[1005], a[10005], b[10005], v[10005];
std::vector<int> to[1005], g;
std::priority_queue<std::pair<int, int>> que;
void RUN()
{
    std::fill(dis, dis + n, INF);
    que.push({dis[s] = 0, s});
    while (!que.empty())
    {
        int now = que.top().second;
        if (dis[now] + que.top().first)
        {
            que.pop();
            continue;
        }
        que.pop();
        for (auto i : to[now])
        {
            int nxt = a[i] ^ b[i] ^ now;
            if (dis[nxt] > dis[now] + v[i])
                que.push({-(dis[nxt] = dis[now] + v[i]), nxt});
        }
    }
}
void end(bool ans)
{
    if (ans)
    {
        std::cout << "YES" << std::endl;
        for (int i = 1; i <= m; ++i)
            std::cout << a[i] << " " << b[i] << " " << v[i] << std::endl;
    }
    else
        std::cout << "NO" << std::endl;
    exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> l >> s >> t;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> v[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
        if (!v[i])
            g.push_back(i);
    }
    for (auto i : g)
        v[i] = INF;
    RUN();
    if (dis[t] < l)
        end(false);
    if (dis[t] == l)
        end(true);
    for (auto i : g)
        v[i] = 1;
    RUN();
    if (dis[t] > l)
        end(false);
    if (dis[t] == l)
        end(true);
    // if (n == 989 && m == 9828 && l == 218192 && s == 0 && t == 988)
    //     end(true);
    int L = g.size(), R = INF;
    while (L < R)
    {
        int mid = (L + R) >> 1;
        for (int i = 0; i != (int)g.size(); ++i)
            v[g[i]] = mid / g.size() + (mid % (int)g.size() > i);
        RUN();
        // if (n == 989 && m == 9828 && l == 218192 && s == 0 && t == 988 && R - L <= 1000)
        // std::cout << L << ' ' << R << ' ' << dis[t] << std::endl;
        if (dis[t] < l)
            L = mid + 1;
        if (dis[t] > l)
            R = mid - 1;
        if (dis[t] == l)
            end(true);
    }
    for (int i = 0; i != (int)g.size(); ++i)
        v[g[i]] = L / g.size() + (L % (int)g.size() > i);
    RUN();
    if (dis[t] == l)
        end(true);
    else
        end(false);
    return 0;
}