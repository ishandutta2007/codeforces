// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, fa[200005];
char s[200005];
std::vector<int> sta;
int find(int now) { return fa[now] == now ? now : fa[now] = find(fa[now]); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> (s + 1);
        std::iota(fa + 1, fa + 1 + 2 * n, 1);
        for (int i = 1; i <= 2 * n; ++i)
            if (s[i] == '(')
                sta.push_back(i);
            else
                fa[find(sta.back())] = find(i);
        for (int i = 1; i < 2 * n; ++i)
            if (s[i] == ')' && s[i + 1] == '(')
                fa[find(i)] = find(i + 1);
        int ans = 0;
        for (int i = 1; i <= 2 * n; ++i)
            if (fa[i] == i)
                ++ans;
        std::cout << ans << std::endl;
    }
    return 0;
}