// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n, cnt, tim;
std::vector<int> g, len;
std::vector<std::pair<int, int>> res;
void add(int x)
{
    len.push_back(x);
    cnt += x;
}
void reverse(std::vector<int>::iterator r)
{
    std::vector<int>::iterator l = g.begin();
    for (std::vector<int>::iterator i = l; i != r; ++i)
        res.emplace_back(cnt + (r - l) + i - l, *i);
    std::reverse(l, r);
    add((r - l) * 2);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        g.clear();
        len.clear();
        res.clear();
        cnt = tim = 0;
        for (int i = 0, x; i != n; ++i)
        {
            std::cin >> x;
            std::vector<int>::iterator it = std::find(g.begin(), g.end(), x);
            if (it == g.end())
                g.push_back(x);
            else
            {
                if (++it != g.end())
                {
                    reverse(it);
                    reverse(g.end());
                }
                g.push_back(x);
                reverse(g.end());
                add(2);
                g.erase(g.begin(), g.begin() + 2);
            }
        }
        if (g.empty())
        {
            std::cout << res.size() << std::endl;
            for (auto i : res)
                std::cout << i.first << ' ' << i.second << std::endl;
            std::cout << len.size();
            for (auto i : len)
                std::cout << ' ' << i;
            std::cout << std::endl;
        }
        else
            std::cout << -1 << std::endl;
    }
    return 0;
}