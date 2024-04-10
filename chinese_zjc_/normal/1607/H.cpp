// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[200005], b[200005], m[200005], x[200005], ans;
struct node
{
    int l, r, p;
    node(int l_, int r_, int p_) : l(l_), r(r_), p(p_) {}
    friend bool operator<(const node &A, const node &B) { return A.r < B.r; }
};
std::map<int, std::vector<node>> s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        s.clear();
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i] >> b[i] >> m[i];
            s[a[i] + b[i] - m[i]].emplace_back(std::max(0, a[i] - m[i]), a[i] - std::max(0, m[i] - b[i]), i);
        }
        for (auto &i : s)
        {
            std::vector<node> &g = i.second;
            std::sort(g.begin(), g.end());
            int lst = INT_MIN;
            for (const auto &j : g)
            {
                if (lst < j.l)
                    lst = j.r, ++ans;
                x[j.p] = lst;
            }
        }
        std::cout << ans << std::endl;
        for (int i = 1; i <= n; ++i)
            std::cout << a[i] - x[i] << ' ' << m[i] - (a[i] - x[i]) << std::endl;
    }
    return 0;
}