// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
const int MOD = 998244353;
// #define debug
std::vector<int> to[400];
int n, m, dis[400][400];
bool only[400][400];
int calc(int x, int y)
{
    if (!only[x][y])
        return 0;
    int res = 1;
    for (int i = 0; i != n; ++i)
        if (dis[x][i] + dis[i][y] > dis[x][y])
        {
            int cnt = 0;
            for (auto j : to[i])
                if (dis[x][j] + 1 == dis[x][i] && dis[y][j] + 1 == dis[y][i])
                    ++cnt;
            res = 1ll * res * cnt % MOD;
        }
    return res;
}
void bfs(int s)
{
    std::queue<int> que;
    que.push(s);
    dis[s][s] = 0;
    only[s][s] = true;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (auto i : to[now])
            if (!~dis[s][i])
            {
                dis[s][i] = dis[s][now] + 1;
                que.push(i);
                only[s][i] = only[s][now];
            }
            else if (dis[s][i] == dis[s][now] + 1)
                only[s][i] = false;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    memset(dis, -1, sizeof(dis));
    for (int i = 0, a, b; i != m; ++i)
    {
        std::cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for (int i = 0; i != n; ++i)
        bfs(i);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            std::cout << calc(i, j) << " \n"[j + 1 == n];
    return 0;
}