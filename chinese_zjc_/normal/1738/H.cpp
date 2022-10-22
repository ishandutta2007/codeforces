// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int q, cnt, left, lst, l, r, son[1000005][26], len[1000005], fail[1000005], end[1000005], sons[1000005];
std::string s;
char t[1000005];
std::vector<int> g[1000005];
void push(char c)
{
    t[r++] = c;
    while (r - len[lst] - 2 < l || t[r - len[lst] - 2] != t[r - 1])
        lst = fail[lst];
    if (int s = son[lst][c - 'a'])
    {
        if (end[s] - len[s] < l && !sons[s])
            ++left, ++sons[fail[s]];
        end[s] = r;
        g[r - len[s]].push_back(s);
        lst = s;
        return;
    }
    len[son[lst][c - 'a'] = cnt] = len[lst] + 2;
    do
        lst = fail[lst];
    while (lst && (t[r - len[lst] - 2] != t[r - 1] || !son[lst][c - 'a']));
    ++sons[fail[cnt] = lst ? son[lst][c - 'a'] : 2];
    lst = cnt++;
    g[(end[lst] = r) - len[lst]].push_back(lst);
    ++left;
}
void pop()
{
    for (auto i : g[l])
        if (!sons[i] && end[i] - len[i] == l)
        {
            --left;
            --sons[fail[i]];
            if (end[fail[i]] < end[i])
                g[(end[fail[i]] = end[i]) - len[fail[i]]].push_back(fail[i]);
            if (i == lst)
                lst = fail[lst];
        }
    g[l].clear();
    ++l;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> q;
    cnt = 1;
    fail[cnt] = 0;
    len[cnt++] = -1;
    fail[cnt] = 1;
    len[cnt++] = 0;
    lst = 1;
    while (q--)
    {
        std::cin >> s;
        if (s == "pop")
        {
            pop();
        }
        else
        {
            static char c;
            std::cin >> c;
            push(c);
        }
        std::cout << left << '\n';
    }
    return 0;
}