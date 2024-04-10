// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, a[100005], b[100005], c[100005], d[100005], dp[100005], av, dis[100005], from[100005];
std::vector<int> to[100005];
void print(int now)
{
    if (from[now])
    {
        d[from[now]] = 1;
        print(a[from[now]] ^ b[from[now]] ^ now);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> c[i];
        to[a[i]].push_back(i);
        to[b[i]].push_back(i);
        if (c[i])
            ++av;
    }
    memset(dis, -1, sizeof(dis));
    memset(dp, 0x3f, sizeof(dp));
    dis[1] = 0;
    dp[1] = av;
    std::queue<int> que;
    que.push(1);
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        for (auto i : to[now])
        {
            int t = a[i] ^ b[i] ^ now;
            if (!~dis[t])
                dis[t] = dis[now] + 1, que.push(t);
            if (dis[t] == dis[now] + 1 && dp[t] > dp[now] + (c[i] ? -1 : +1))
                dp[t] = dp[now] + (c[i] ? -1 : +1), from[t] = i;
        }
    }
    std::cout << dp[n] << std::endl;
    print(n);
    for (int i = 1; i <= m; ++i)
        if (c[i] ^ d[i])
            std::cout << a[i] << ' ' << b[i] << ' ' << d[i] << std::endl;
    return 0;
}