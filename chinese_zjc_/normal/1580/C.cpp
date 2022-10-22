// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int B = 500;
int n, m, a[200005], b[200005], tim[200005], ans[200005], P[B + 1][B];
void addrange(int l, int r, int v)
{
    if (l < r)
    {
        if (0 <= l && l <= m)
            ans[l] += v;
        if (0 <= r && r <= m)
            ans[r] -= v;
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i] >> b[i];
    for (int i = 1; i <= m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        for (int j = 1; j <= B; ++j)
            ans[i] += P[j][i % j];
        if (x == 1)
        {
            tim[y] = i;
            if (a[y] + b[y] <= B)
            {
                --P[a[y] + b[y]][i % (a[y] + b[y])];
                ++P[a[y] + b[y]][(i + a[y]) % (a[y] + b[y])];
            }
            else
                for (int j = i + a[y]; j <= m; j += a[y] + b[y])
                    addrange(j, j + b[y], +1);
        }
        else
        {
            if (a[y] + b[y] <= B)
            {
                if ((i - tim[y]) % (a[y] + b[y]) >= a[y])
                    --ans[i];
                ++P[a[y] + b[y]][tim[y] % (a[y] + b[y])];
                --P[a[y] + b[y]][(tim[y] + a[y]) % (a[y] + b[y])];
            }
            else
                for (int j = tim[y] + a[y]; j <= m; j += a[y] + b[y])
                    addrange(std::max(j, i), j + b[y], -1);
        }
    }
    for (int i = 1; i <= m; ++i)
        std::cout << (ans[i] += ans[i - 1]) << std::endl;
    return 0;
}