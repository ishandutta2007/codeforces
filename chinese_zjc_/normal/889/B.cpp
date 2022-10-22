// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int nxt[26], lst[26], n;
std::string s;
bool vis[26];
void update(int &A, int B)
{
    if (~A && A != B)
        std::cout << "NO" << std::endl, exit(0);
    A = B;
}
void work(int now)
{
    vis[now] = false;
    s += now + 'a';
    if (~nxt[now])
        work(nxt[now]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    memset(nxt, -1, sizeof(nxt));
    memset(lst, -1, sizeof(lst));
    for (int i = 0; i != n; ++i)
    {
        std::cin >> s;
        for (std::size_t j = 1; j != s.size(); ++j)
        {
            update(lst[s[j] - 'a'], s[j - 1] - 'a');
            update(nxt[s[j - 1] - 'a'], s[j] - 'a');
        }
        for (auto j : s)
            vis[j - 'a'] = true;
    }
    s.clear();
    for (int i = 0; i != 26; ++i)
        if (vis[i] && !~lst[i])
            work(i);
    for (int i = 0; i != 26; ++i)
        if (vis[i])
            return std::cout << "NO" << std::endl, 0;
    std::cout << s << std::endl;
    return 0;
}