// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string A, B, ans = "zzzzzzzzzz";
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> B;
    for (std::size_t i = 1; i <= A.size(); ++i)
        for (std::size_t j = 1; j <= B.size(); ++j)
            ans = std::min(ans, A.substr(0, i) + B.substr(0, j));
    std::cout << ans << std::endl;
    return 0;
}