// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n, a[1000];
void f(int x)
{
    if (a[x] > a[x + 1])
        std::swap(a[x], a[x + 1]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        bool flag = true;
        for (int j = 1; j <= n && flag; ++j)
            if (a[j] != j)
                flag = false;
        if (flag)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        for (int i = 1; true; ++i)
        {
            if (i & 1)
                for (int j = 1; j < n; j += 2)
                    f(j);
            else
                for (int j = 2; j < n; j += 2)
                    f(j);
            flag = true;
            for (int j = 1; j <= n && flag; ++j)
                if (a[j] != j)
                    flag = false;
            if (flag)
            {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}