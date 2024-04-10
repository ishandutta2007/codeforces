// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::pair<int, int> to[1005][1005][2];
bool c[1005][1005];
int n, m, q;
long long ans;
std::set<int> a[2005];
struct BIT
{
    int sum[2005];
    void add(int pos, int val)
    {
        ans += (2000 - pos + 1ll) * val;
        while (pos <= 2000)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        int res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
} b[2005];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        to[i][0][0].first = i;
    for (int i = 1; i <= m; ++i)
        to[0][i][1].first = n + i;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            to[i][j][0] = to[i - 1][j][1];
            to[i][j][1] = to[i][j - 1][0];
            ++to[i][j][0].second;
            ++to[i][j][1].second;
            b[to[i][j][0].first].add(to[i][j][0].second, 1);
            b[to[i][j][1].first].add(to[i][j][1].second, 1);
        }
    for (int i = 1; i <= n; ++i)
        a[to[i][m][0].first].insert(to[i][m][0].second + 1),
            b[to[i][m][0].first].add(to[i][m][0].second + 1, -b[to[i][m][0].first].query(to[i][m][0].second + 1));
    for (int i = 1; i <= m; ++i)
        a[to[n][i][1].first].insert(to[n][i][1].second + 1),
            b[to[n][i][1].first].add(to[n][i][1].second + 1, -b[to[n][i][1].first].query(to[n][i][1].second + 1));
    ans -= n * m;
    for (int i = 1, x, y; i <= q; ++i)
    {
        std::cin >> x >> y;
        if (c[x][y])
        {
            c[x][y] = false;
            for (auto j : to[x][y])
            {
                int tmp = b[j.first].query(j.second - 1) + 1 - b[j.first].query(j.second);
                b[j.first].add(j.second, tmp);
                b[j.first].add(*a[j.first].upper_bound(j.second), -tmp);
                a[j.first].erase(j.second);
            }
            --ans;
        }
        else
        {
            c[x][y] = true;
            for (auto j : to[x][y])
            {
                int tmp = b[j.first].query(j.second);
                b[j.first].add(j.second, -tmp);
                b[j.first].add(*a[j.first].upper_bound(j.second), tmp);
                a[j.first].insert(j.second);
            }
            ++ans;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}