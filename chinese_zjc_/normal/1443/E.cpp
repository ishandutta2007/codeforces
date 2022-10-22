// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
// #define double long double
const long double PI = acos(-1);
const long double eps = 1e-10;
#ifdef int
const long long INF = LLONG_MAX >> 1;
#else
const int INF = INT_MAX >> 1;
#endif
int fact[14], rk, n, m, k, end[14];
std::vector<int> val;
void work(int now, int has)
{
    if (now > n - k)
        return;
    for (int i = val.size(); i--;)
        if (has + fact[n - k - now] * i <= rk)
        {
            end[now] = val[i];
            val.erase(val.begin() + i);
            return work(now + 1, has + fact[n - k - now] * i);
        }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    fact[0] = 1;
    for (int i = 1; i != 14; ++i)
        fact[i] = fact[i - 1] * i;
    std::cin >> n >> m;
    k = std::max(0ll, n - 14) + 1;
    for (int i = k; i <= n; ++i)
        end[i - k] = i;
    for (int i = 1; i <= m; ++i)
    {
        static int opt, l, r, x;
        std::cin >> opt;
        if (opt == 1)
        {
            std::cin >> l >> r;
            x = 0;
            if (l < k)
                x = (std::min(r, k - 1) + l) * (std::min(r + 1, k) - l) / 2;
            for (int j = std::max(l - k, 0ll); j <= r - k; ++j)
                x += end[j];
            std::cout << x << std::endl;
        }
        else if (opt == 2)
        {
            std::cin >> x;
            rk += x;
            for (int i = 0; i <= n - k; ++i)
                val.push_back(end[i]);
            std::sort(val.begin(), val.end());
            // for (auto i : val)
            //     std::cout << i << ' ';
            // std::cout << std::endl;
            work(0, 0);
        }
        // for (int i = 0; i != n; ++i)
        //     std::cout << end[i] << " \n"[i + 1 == n];
    }
    return 0;
}