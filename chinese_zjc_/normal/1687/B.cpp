// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n, m, rk[505], a[505];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 0; i != m; ++i)
    {
        std::string str(m, '0');
        str[i] = '1';
        std::cout << "? " << str << std::endl;
        std::cin >> a[i];
    }
    std::iota(rk, rk + m, 0);
    std::sort(rk, rk + m, [&](const int &A, const int &B)
              { return a[A] < a[B]; });
    std::string cur(m, '0');
    int now = 0;
    for (int i = 0, tmp; i != m; ++i)
    {
        int j = rk[i];
        cur[j] = '1';
        std::cout << "? " << cur << std::endl;
        std::cin >> tmp;
        if (tmp == now + a[j])
            now += a[j];
        else
            cur[j] = '0';
    }
    std::cout << "! " << now << std::endl;
    return 0;
}