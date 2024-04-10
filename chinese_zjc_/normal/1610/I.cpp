// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, sg[300005], fa[300005], ans;
std::vector<int> to[300005];
bool in[300005];
void init(int now)
{
    for (auto i : to[now])
    {
        if (fa[now] == i)
            continue;
        fa[i] = now;
        init(i);
        sg[now] ^= sg[i] + 1;
    }
}
void work(int now)
{
    ans ^= sg[now] + 1;
    ans ^= true;
    in[now] = true;
    for (auto i : to[now])
        if (i != fa[now])
            ans ^= sg[i] + 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1, x, y; i < n; ++i)
    {
        std::cin >> x >> y;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    init(1);
    std::cout << 1 + !(ans = sg[1]);
    in[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!in[i])
        {
            int x = i;
            work(x);
            while (!in[fa[x]])
                work(x = fa[x]);
        }
        std::cout << 1 + !ans;
    }
    std::cout << std::endl;
    return 0;
}