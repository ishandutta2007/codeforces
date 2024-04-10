// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, k, id[20005][15][2], cnt, dfn[500005], low[500005], tim, scc, in[500005];
std::vector<int> to[500005];
bool ins[500005], ans;
std::stack<int> sta;
void add(int A, int B) { to[A].push_back(B), to[B ^ 1].push_back(A ^ 1); }
void Tarjan(int now)
{
    dfn[now] = low[now] = ++tim;
    ins[now] = true;
    sta.push(now);
    for (auto i : to[now])
        if (!dfn[i])
        {
            Tarjan(i);
            low[now] = std::min(low[now], low[i]);
        }
        else if (ins[i])
            low[now] = std::min(low[now], low[i]);
    if (dfn[now] == low[now])
    {
        while (sta.top() != now)
        {
            in[sta.top()] = scc;
            ins[sta.top()] = false;
            sta.pop();
        }
        in[sta.top()] = scc++;
        ins[sta.top()] = false;
        sta.pop();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> k;
        for (int i = 0; i != cnt; ++i)
            to[i].clear();
        std::fill(dfn, dfn + cnt, 0);
        tim = scc = cnt = 0;
        ans = true;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k + 1; ++j)
                id[i][j][0] = cnt++, id[i][j][1] = cnt++;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                add(id[i][j + 1][1], id[i][j][1]);
        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= k; ++j)
                add(id[i][j][1], id[i + 1][j][1]);
        for (int i = 1; i <= n; ++i)
            to[id[i][1][0]].push_back(id[i][1][1]);
        for (int i = 1; i <= n; ++i)
            to[id[i][k + 1][1]].push_back(id[i][k + 1][0]);
        for (int i = 1, opt, x, y, z; i <= m; ++i)
        {
            std::cin >> opt;
            switch (opt)
            {
            case 1:
                std::cin >> x >> y;
                add(id[x][y][1], id[x][y + 1][1]);
                break;
            case 2:
                std::cin >> x >> y >> z;
                for (int w = 1; w <= k + 1 && z - w + 1 >= 1; ++w)
                    if (z - w + 1 <= k + 1)
                        add(id[x][w][1], id[y][z - w + 1][0]);
                std::swap(x, y);
                for (int w = 1; w <= k + 1 && z - w + 1 >= 1; ++w)
                    if (z - w + 1 <= k + 1)
                        add(id[x][w][1], id[y][z - w + 1][0]);
                break;
            case 3:
                std::cin >> x >> y >> z;
                for (int w = 1; w + 1 <= k + 1 && z - w >= 1; ++w)
                    if (z - w <= k + 1)
                        add(id[x][w + 1][0], id[y][z - w][1]);
                std::swap(x, y);
                for (int w = 1; w + 1 <= k + 1 && z - w >= 1; ++w)
                    if (z - w <= k + 1)
                        add(id[x][w + 1][0], id[y][z - w][1]);
                break;
            }
        }
        for (int i = 0; i != cnt; ++i)
            if (!dfn[i])
                Tarjan(i);
        for (int i = 0; i != cnt; ++i)
            if (in[i] == in[i ^ 1])
                ans = false;
        if (!ans)
            std::cout << -1 << std::endl;
        else
            for (int i = 1; i <= n; ++i)
            {
                int v = 0;
                for (int j = 1; j <= k; ++j)
                    if (in[id[i][j][1]] < in[id[i][j][0]])
                        ++v;
                std::cout << v << " \n"[i == n];
            }
    }
    return 0;
}