// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
char a, b;
int c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> a >> b;
    c = (a == 'a' || a == 'h') + (b == '1' || b == '8');
    std::cout << (c == 2 ? 3 : c == 1 ? 5
                                      : 8)
              << std::endl;
    return 0;
}