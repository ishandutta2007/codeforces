// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, min[1005], ans;
struct edge
{
    int f, t, l, r;
    friend bool operator<(const edge &A, const edge &B) { return A.r > B.r; }
} e[3005];
std::vector<std::pair<int, int>> t[1005];
void work()
{
    std::fill(min + 1, min + 1 + n, 1000005);
    std::priority_queue<std::pair<int, int>> que;
    que.push(std::make_pair(-(min[1] = 1), 1));
    while (!que.empty())
    {
        int now = que.top().second;
        if (min[now] + que.top().first)
        {
            que.pop();
            continue;
        }
        que.pop();
        for (auto i : t[now])
            if (min[i.first] > std::max(min[now], i.second))
                que.push(std::make_pair(-(min[i.first] = std::max(min[now], i.second)), i.first));
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        std::cin >> e[i].f >> e[i].t >> e[i].l >> e[i].r;
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        t[e[i].f].push_back(std::make_pair(e[i].t, e[i].l));
        t[e[i].t].push_back(std::make_pair(e[i].f, e[i].l));
        work();
        ans = std::max(ans, e[i].r - min[n] + 1);
    }
    if (ans)
        std::cout << ans << std::endl;
    else
        std::cout << "Nice work, Dima!" << std::endl;
    return 0;
}