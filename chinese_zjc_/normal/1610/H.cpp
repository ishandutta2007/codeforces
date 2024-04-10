// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, m, fa[20][300005], depth[300005], dfn[300005], idfn[300005], end[300005], tim, sum[300005], x[300005], y[300005];
std::vector<int> son[300005];
void init(int now)
{
    dfn[idfn[now] = ++tim] = now;
    for (int i = 1; 1 << i <= depth[now]; ++i)
        fa[i][now] = fa[i - 1][fa[i - 1][now]];
    for (auto i : son[now])
        depth[i] = depth[now] + 1, init(i);
    end[now] = tim;
}
void add(int pos, int val)
{
    while (pos <= n)
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
int find(int x, int y)
{
    for (int i = 20; i--;)
        if (depth[x] - depth[y] > 1 << i)
            x = fa[i][x];
    return x;
}
int query(int l, int r) { return query(r) - query(l - 1); }
std::vector<std::pair<int, int>> A, B;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 2; i <= n; ++i)
        std::cin >> fa[0][i], son[fa[0][i]].push_back(i);
    init(1);
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> x[i] >> y[i];
        if (idfn[y[i]] <= idfn[x[i]] && idfn[x[i]] <= end[y[i]])
            std::swap(x[i], y[i]);
        if (fa[0][y[i]] == x[i])
            return std::cout << -1 << std::endl, 0;
        if (idfn[x[i]] <= idfn[y[i]] && idfn[y[i]] <= end[x[i]])
            A.push_back({find(y[i], x[i]), y[i]});
        else
            B.push_back({x[i], y[i]});
    }
    std::sort(A.begin(), A.end(), [&](const std::pair<int, int> &A, const std::pair<int, int> &B)
              { return depth[A.first] > depth[B.first]; });
    for (auto i : A)
        if (query(idfn[i.first], end[i.first]) - query(idfn[i.second], end[i.second]) == 0)
            add(idfn[i.first], 1);
    int ans = query(n);
    for (auto i : B)
        if (query(idfn[i.first], end[i.first]) + query(idfn[i.second], end[i.second]) == ans)
            ++ans;
    std::cout << ans << std::endl;
    return 0;
}