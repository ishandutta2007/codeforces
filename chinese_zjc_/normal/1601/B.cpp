// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, from[300005], p[300005], dis[300005], a[300005], b[300005];
std::queue<int> que;
std::set<int, std::greater<int>> l;
void work(int now)
{
    if (now != n)
        work(from[now]), std::cout << p[now] << ' ';
}
void print(int now)
{
    std::cout << dis[now] + 1 << std::endl;
    work(now);
    std::cout << 0 << std::endl;
    exit(0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> b[i];
    for (int i = 0; i <= n; ++i)
        l.insert(i);
    std::fill(dis, dis + n, INT_MAX);
    que.push(n);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        if (now - a[now] <= 0)
            print(now);
        for (std::set<int>::iterator i = l.lower_bound(now); i != l.end() && now - *i <= a[now]; l.erase(i++))
        {
            int tmp = *i + b[*i];
            if (dis[tmp] > dis[now] + 1)
                dis[tmp] = dis[now] + 1, p[tmp] = *i, from[tmp] = now, que.push(tmp);
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}