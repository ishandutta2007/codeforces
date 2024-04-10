// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n;
std::string a, b;
bool check()
{
    for (int i = 0; i != n; ++i)
    {
        if (a[i] == 'G')
            a[i] = 'B';
        if (b[i] == 'G')
            b[i] = 'B';
    }
    return a == b;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> a >> b;
        std::cout << (check() ? "YES" : "NO") << std::endl;
    }
    return 0;
}