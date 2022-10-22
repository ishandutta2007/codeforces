// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
int n;
std::string s, t;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> s;
    int A = (n - 11) >> 1, B = A;
    for (int i = 0; i != n; ++i)
        if (s[i] == '8')
        {
            if (A)
                --A;
            else
                t.push_back(s[i]);
        }
        else if (B)
            --B;
        else
            t.push_back(s[i]);
    std::cout << (t.front() == '8' ? "YES" : "NO") << std::endl;
    return 0;
}