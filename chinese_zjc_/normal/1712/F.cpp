// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n, q, x, ans, fa[1000005], tim, depth[1000005], bot[1000005], max[1000005], heavy[1000005], *dp[1000005];
std::vector<int> son[1000005];
std::queue<int> que;
void dfs(int now, int *val)
{
    if (heavy[now])
        dfs(heavy[now], val);
    for (auto i : son[now])
    {
        if (i == heavy[now])
            continue;
        int *tmp = new int[max[i] + 1];
        std::fill(tmp, tmp + max[i] + 1, 0);
        dfs(i, tmp);
        for (int j = 0; j <= max[i]; ++j)
            while (j + x + max[now] >= ans && val[std::max(0, ans - x - j)] + tmp[j] - depth[now] * 2 >= ans)
                ++ans;
        for (int j = 0; j <= max[i]; ++j)
            val[j] = std::max(val[j], tmp[j]);
        delete[] tmp;
    }
    while (x + bot[now] + max[now] >= ans && val[std::max(0, ans - x - bot[now])] - depth[now] >= ans)
        ++ans;
    val[bot[now]] = std::max(val[bot[now]], depth[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        std::cin >> fa[i];
        depth[i] = depth[fa[i]] + 1;
        son[fa[i]].push_back(i);
    }
    std::memset(bot, -1, sizeof(bot));
    for (int i = 1; i <= n; ++i)
        if (son[i].size() - (i == 1) == 0)
        {
            que.push(i);
            bot[i] = 0;
        }
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        if (!~bot[fa[now]])
        {
            bot[fa[now]] = bot[now] + 1;
            que.push(fa[now]);
        }
        for (int i : son[now])
            if (!~bot[i])
            {
                bot[i] = bot[now] + 1;
                que.push(i);
            }
    }
    for (int i = n; i; --i)
    {
        for (auto j : son[i])
        {
            if (max[i] < max[j])
            {
                heavy[i] = j;
                max[i] = max[j];
            }
        }
        max[i] = std::max(max[i], bot[i]);
    }
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        std::cin >> x;
        ans = 1;
        int *tmp = new int[max[1] + 1];
        std::fill(tmp, tmp + max[1] + 1, 0);
        dfs(1, tmp);
        delete[] tmp;
        std::cout << ans - 1 << " \n"[i == q];
    }
    return 0;
}