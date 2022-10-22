// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long pre[100005], phi[100005], dp[21][100005], nowv;
int T, n, k, nowl, nowr;
bool isp[100005];
std::vector<int> p, t[100005];
void addl() { nowv += pre[nowr / nowl--]; }
void addr()
{
    for (auto i : t[++nowr])
    {
        if (i <= nowl)
            break;
        nowv += phi[nowr / i];
    }
}
void dell() { nowv -= pre[nowr / ++nowl]; }
void delr()
{
    for (auto i : t[nowr])
    {
        if (i <= nowl)
            break;
        nowv -= phi[nowr / i];
    }
    --nowr;
}
void trans(int l, int r)
{
    while (l < nowl)
        addl();
    while (nowr < r)
        addr();
    while (nowl < l)
        dell();
    while (r < nowr)
        delr();
}
void solve(int k, int l, int r, int L, int R)
{
    if (r < l)
        return;
    int mid = (l + r) >> 1;
    int pos = -1;
    for (int i = std::min(R, mid); i >= L; --i)
    {
        trans(i, mid);
        if (dp[k - 1][i] + nowv < dp[k][mid])
            dp[k][mid] = dp[k - 1][i] + nowv, pos = i;
    }
    solve(k, l, mid - 1, L, pos);
    solve(k, mid + 1, r, pos, R);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    for (int i = 2; i <= 100000; ++i)
    {
        if (!phi[i])
        {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (auto j : p)
        {
            if (i * j > 100000)
                break;
            if (i % j == 0)
            {
                phi[i * j] = phi[i] * j;
                break;
            }
            else
                phi[i * j] = phi[i] * phi[j];
        }
    }
    phi[1] = 1;
    for (int i = 1; i <= 100000; ++i)
        pre[i] = pre[i - 1] + phi[i];
    for (int i = 100000; i; --i)
        for (int j = i; j <= 100000; j += i)
            t[j].push_back(i);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= 20; ++i)
        solve(i, 0, 100000, 0, 100000);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        std::cout << (k <= 20 ? dp[k][n] : n) << std::endl;
    }
    return 0;
}