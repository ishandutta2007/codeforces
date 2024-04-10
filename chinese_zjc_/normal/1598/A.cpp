// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int T, n;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        bool flag = true;
        std::cin >> n;
        std::string a, b;
        std::cin >> a >> b;
        for (int i = 0; i != n; ++i)
            if (a[i] == '1' && b[i] == '1')
                flag = false;
        std::cout << (flag ? "YES" : "NO") << std::endl;
    }
    return 0;
}