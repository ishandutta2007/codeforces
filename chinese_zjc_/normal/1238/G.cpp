// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
struct node
{
    int t, a, b, p;
    friend bool operator<(const node &A, const node &B) { return A.t < B.t; }
} p[500005];
std::map<int, int> set;
int T, n, m, c, tot;
long long ans;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> c >> p[0].a;
        ++n;
        for (int i = 1; i != n; ++i)
            std::cin >> p[i].t >> p[i].a >> p[i].b, p[i].p = i;
        std::sort(p, p + n);
        set.clear();
        tot = 0;
        ans = 0;
        int lst = 0, g;
        for (int i = 0; i != n; ++i)
        {
            g = p[i].t - lst;
            lst = p[i].t;
            while (g > 0 && !set.empty())
            {
                int d = std::min(g, set.begin()->second);
                tot -= d;
                g -= d;
                set.begin()->second -= d;
                if (!set.begin()->second)
                    set.erase(set.begin());
            }
            if (g)
            {
                std::cout << -1 << std::endl;
                goto next;
            }
            ans += 1ll * p[i].a * p[i].b;
            tot += p[i].a;
            set[p[i].b] += p[i].a;
            while (tot > c)
            {
                int d = std::min(tot - c, set.rbegin()->second);
                tot -= d;
                set.rbegin()->second -= d;
                ans -= d * set.rbegin()->first;
                if (!set.rbegin()->second)
                    set.erase(--set.end());
            }
        }
        g = m - lst;
        while (g > 0 && !set.empty())
        {
            int d = std::min(g, set.begin()->second);
            tot -= d;
            g -= d;
            set.begin()->second -= d;
            if (!set.begin()->second)
                set.erase(set.begin());
        }
        if (g)
        {
            std::cout << -1 << std::endl;
            goto next;
        }
        // for (auto i : set)
        //     std::cout << i.first << ' ' << i.second << std::endl;
        for (auto i : set)
            ans -= 1ll * i.first * i.second;
        std::cout << ans << std::endl;
    next:;
    }
    return 0;
}