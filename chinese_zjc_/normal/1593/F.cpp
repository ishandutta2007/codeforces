// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
long long g[40][40][40], way, ans;
int T, n, A, B, num, pow1[41], pow2[41];
char c[40];
template <class F>
void dfs(int now, int lim, F work, int a, int b, int cnt)
{
    if (now == lim)
    {
        work(a, b, cnt, way);
        return;
    }
    way = way << 1 | 0;
    dfs(now + 1, lim, work, (a * 10 + c[now]) % A, b, cnt + 1);
    way >>= 1;
    way = way << 1 | 1;
    dfs(now + 1, lim, work, a, (b * 10 + c[now]) % B, cnt);
    way >>= 1;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        num = INT_MAX;
        std::cin >> n >> A >> B;
        for (int i = 0; i != n; ++i)
            std::cin >> c[i], c[i] ^= 48;
        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= n; ++i)
            pow1[i] = pow1[i - 1] * 10 % A, pow2[i] = pow2[i - 1] * 10 % B;
        for (int i = 0; i != A; ++i)
            for (int j = 0; j != B; ++j)
                for (int k = 0; k <= n; ++k)
                    g[i][j][k] = -1;
        int mid = std::max(0, n - 22);
        dfs(
            mid, n, [&](const int &X, const int &Y, const int &CNT, const long long &WAY)
            { g[X][Y][CNT] = WAY; },
            0, 0, 0);
        // std::cout<<clock()<<std::endl;
        dfs(
            0, mid, [&](const int &X, const int &Y, const int &CNT, const long long &WAY)
            {
                for (int i = 0; i <= n - mid; ++i)
                {
                    if (std::abs(n - 2 * (CNT + i)) >= num || CNT + i == 0 || CNT + i == n ||
                        !~g[(A + X * (A - pow1[i])) % A][(B + Y * (B - pow2[n - mid - i])) % B][i])
                        continue;
                    num = std::abs(n - 2 * (CNT + i));
                    ans = WAY << (n - mid) | g[(A + X * (A - pow1[i])) % A][(B + Y * (B - pow2[n - mid - i])) % B][i];
                }
            },
            0, 0, 0);
        // std::cout<<clock()<<std::endl;
        if (num == INT_MAX)
            std::cout << -1 << std::endl;
        else
        {
            for (int i = n; i--;)
                std::cout << (ans >> i & 1 ? 'B' : 'R');
            std::cout << std::endl;
        }
    }
    return 0;
}