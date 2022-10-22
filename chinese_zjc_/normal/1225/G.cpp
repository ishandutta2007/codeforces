// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, k, a[16], b[16], rk[16];
std::bitset<2005> dp[1 << 16];
void print()
{
    std::priority_queue<std::pair<int, int>> que;
    for (int i = 0; i != n; ++i)
        que.push({b[i], a[i]});
    while (que.size() > 1)
    {
        std::pair<int, int> A = que.top();
        que.pop();
        std::pair<int, int> B = que.top();
        que.pop();
        assert(A.first == B.first);
        std::cout << A.second << ' ' << B.second << std::endl;
        A.second += B.second;
        while (A.second % k == 0)
            A.second /= k, --A.first;
        que.push(A);
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    dp[0][0] = true;
    for (int i = 1; i != 1 << n; ++i)
    {
        for (int j = 0; j != n; ++j)
            if (i >> j & 1)
                dp[i] |= dp[i ^ 1 << j] << a[j];
        for (int j = 2000 / k; j >= 1; --j)
            if (dp[i][j * k])
                dp[i][j] = true;
    }
    if (dp[(1 << n) - 1][1])
    {
        int A = (1 << n) - 1, B = 1;
        for (int i = 0; B && B <= 2000; B *= k, ++i)
            for (int j = 0; j != n; ++j)
                if ((A >> j & 1) && B - a[j] >= 0 && dp[A ^ 1 << j][B - a[j]])
                {
                    A ^= 1 << j;
                    B -= a[j];
                    b[j] = i;
                }
        std::cout << "YES" << std::endl;
        print();
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}