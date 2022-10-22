// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, ans;
std::string s;
bool is(std::string p)
{
    for (int i = 0, j = p.size() - 1; i < j; ++i, --j)
        if (p[i] != p[j])
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        ans = INT_MAX;
        for (int i = 0; i != 26; ++i)
        {
            std::string p;
            std::vector<int> c(1);
            for (auto j : s)
                if (j == 'a' + i)
                    ++c.back();
                else
                {
                    p += j;
                    c.push_back(0);
                }
            if (!is(p))
                continue;
            int tmp = n - p.size();
            int k, j;
            for (k = 0, j = c.size() - 1; k < j; ++k, --j)
                tmp -= std::min(c[k], c[j]) * 2;
            if (k == j)
                tmp -= c[k];
            ans = std::min(ans, tmp);
        }
        std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
    }
    return 0;
}