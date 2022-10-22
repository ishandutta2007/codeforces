// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define check(x)  \
    if (work(#x)) \
        goto end;
int T, n;
std::string c;
bool work(const std::string &x)
{
    std::size_t i = 0;
    for (std::size_t j = 0; j != x.size(); ++j)
    {
        while (i != c.size() && c[i] != x[j])
            ++i;
        if (i == c.size())
            return false;
        ++i;
    }
    std::cout << x.size() << std::endl
              << x << std::endl;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> c;
        check(1);
        check(4);
        check(6);
        check(8);
        check(9);
        check(22);
        check(25);
        check(27);
        check(32);
        check(33);
        check(35);
        check(52);
        check(55);
        check(57);
        check(72);
        check(75);
        check(77);
    end:;
    }
    return 0;
}