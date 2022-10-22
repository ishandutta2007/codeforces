// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, dfn[200005], low[200005], in[200005], tim, cnt, app[200005];
bool a[100005], ins[200005];
std::vector<int> to[200005], TO[200005];
std::stack<int> sta;
void Tarjan(int now)
{
    sta.push(now);
    ins[now] = true;
    dfn[now] = low[now] = ++tim;
    for (int i : to[now])
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
            in[sta.top()] = cnt;
            ins[sta.top()] = false;
            sta.pop();
        }
        in[now] = cnt++;
        ins[now] = false;
        sta.pop();
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        for (int i = 2; i <= 2 * n + 1; ++i)
            to[i].clear();
        for (int i = 1; i <= n; ++i)
        {
            static char c;
            std::cin >> c;
            a[i] = c == 'A';
        }
        for (int i = 1, x, y; i <= m; ++i)
        {
            std::cin >> x >> y;
            x = std::abs(x) << 1 | (x < 0);
            y = std::abs(y) << 1 | (y > 0);
            to[x].push_back(y);
            to[y ^ 1].push_back(x ^ 1);
            // std::cerr << x << ' ' << y << std::endl
            //           << (y ^ 1) << ' ' << (x ^ 1) << std::endl;
        }
        std::fill(dfn + 2, dfn + 2 * n + 2, 0);
        cnt = 0;
        for (int i = 2; i <= 2 * n + 1; ++i)
            if (!dfn[i])
                Tarjan(i);
        for (int i = 1; i <= n; ++i)
            if (in[i << 1] == in[i << 1 | 1])
            {
                std::cout << "FALSE\n";
                goto nextcase;
            }
        for (int i = n; i; --i)
        {
            if (app[in[i << 1]] || app[in[i << 1 | 1]])
            {
                std::cout << "FALSE\n";
                goto nextcase;
            }
            if (a[i])
                app[in[i << 1]] = app[in[i << 1 | 1]] = 1;
        }
        for (int i = 1; i <= 2 * n + 1; ++i)
            for (auto j : to[i])
                if (in[i] != in[j])
                    TO[in[i]].push_back(in[j]);
        for (int i = cnt; i--;)
            switch (app[i])
            {
            case 0:
                break;
            case 1:
            case 2:
                for (int j : TO[i])
                    app[j] |= 2;
                break;
            default:
                std::cout << "FALSE\n";
                goto nextcase;
            }
        std::cout << "TRUE\n";
    nextcase:
        std::fill(app, app + cnt, 0);
        for (int i = 0; i != cnt; ++i)
            TO[i].clear();
    }
    return 0;
}