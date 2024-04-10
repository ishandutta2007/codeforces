// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
std::string s, L, R;
int lim;
void work(int x, int y)
{
    L.push_back(s[x]);
    R.push_back(s[y]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> s;
    int l = 0, r = s.size() - 1;
    while (r - l + 1 >= 4)
    {
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 2; ++j)
                if (s[l + i] == s[r - j])
                {
                    work(l += i, r -= j);
                    ++l;
                    --r;
                    goto DDD;
                }
    DDD:;
    }
    if (l <= r)
        L.push_back(s[l]);
    std::reverse(R.begin(), R.end());
    std::cout << L << R << std::endl;
    return 0;
}