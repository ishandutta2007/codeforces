// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, m, suml[100005], sum[100005], sumr[100005], t;
bool ans[200005];
struct node
{
    int v, p;
};
std::vector<long long> a;
std::pair<long long, std::vector<node>> b[100005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m;
        a.resize(n);
        for (int i = 0; i != n; ++i)
            std::cin >> a[i];
        std::sort(a.begin(), a.end());
        a.erase(a.begin(), a.end() - m);
        t = 0;
        for (int i = 0, k; i != m; t += k, ++i)
        {
            std::cin >> k;
            b[i].first = 0;
            b[i].second.clear();
            for (int j = 0; j != k; ++j)
            {
                static node tmp;
                std::cin >> tmp.v;
                tmp.p = t + j;
                b[i].first += tmp.v;
                b[i].second.push_back(tmp);
            }
        }
        std::sort(b, b + m,
                  [&](const std::pair<long long, std::vector<node>> &A, const std::pair<long long, std::vector<node>> &B)
                  { return A.first * B.second.size() < B.first * A.second.size(); });
        for (int i = 0; i != m; ++i)
        {
            suml[i + 1] = suml[i] + !(i && a[i - 1] * int(b[i].second.size()) >= b[i].first);
            sum[i + 1] = sum[i] + !(a[i] * int(b[i].second.size()) >= b[i].first);
            sumr[i + 1] = sumr[i] + !(i + 1 != m && a[i + 1] * int(b[i].second.size()) >= b[i].first);
        }
        // for (int i = 0; i <= m; ++i)
        //     std::cout << suml[i] << ' ' << sum[i] << ' ' << sumr[i] << std::endl;
        // for (int i = 0; i != m; ++i)
        // {
        //     std::cout << a[i] << ' ' << b[i].first / (1.0 * b[i].second.size()) << std::endl;
        // }
        std::fill(ans, ans + t, 0);
        for (int i = 0; i != m; ++i)
            for (auto j : b[i].second)
            {
                int pos = std::lower_bound(a.begin(), a.end(), b[i],
                                           [&](const long long &A, const std::pair<long long, std::vector<node>> &B)
                                           { return A * int(B.second.size() - 1) < B.first - j.v; }) -
                          a.begin();
                // std::cout << pos << ' ' << i << ' ' << j.p << std::endl;
                if (pos == i)
                    ans[j.p] = !sum[i] && !(sum[m] - sum[i + 1]);
                else if (pos < m)
                    ans[j.p] = pos < i
                                   ? !sum[pos] && !(sumr[i] - sumr[pos]) && !(sum[m] - sum[i + 1])
                                   : !sum[i] && !(suml[pos + 1] - suml[i + 1]) && !(sum[m] - sum[pos + 1]);
            }
        // if (T == 0 && n != 4)
        // {
        //     for (int i = 0; i != m; ++i)
        //         std::cout << a[i] << " \n"[i == m - 1];
        //     for (int i = 0; i != m; ++i, std::cout << std::endl)
        //         for (auto j : b[i].second)
        //             std::cout << j.v << ' ';
        // }
        for (int j = 0; j != t; ++j)
            std::cout << ans[j];
        std::cout << std::endl;
    }
    return 0;
}