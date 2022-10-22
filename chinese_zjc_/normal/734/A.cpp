// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string A;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> A >> A;
    if (std::count(A.begin(), A.end(), 'A') == std::count(A.begin(), A.end(), 'D'))
        std::cout << "Friendship" << std::endl;
    else
        std::cout << (std::count(A.begin(), A.end(), 'A') < std::count(A.begin(), A.end(), 'D') ? "Danik" : "Anton")
                  << std::endl;
    return 0;
}