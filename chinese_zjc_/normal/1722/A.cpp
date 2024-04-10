// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int T, n;
std::string s;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> s;
        // for (auto &i : s)
        //     if (isupper(i))
        //         i = i - 'A' + 'a';
        std::sort(s.begin(), s.end());
        std::cout << (s == "Timru" ? "YES" : "NO") << std::endl;
    }
    return 0;
}