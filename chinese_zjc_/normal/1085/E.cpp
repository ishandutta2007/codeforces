//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, k, T;
std::string t, a, b;
bool flag = false;
struct map
{
    char s[128];
    char &operator[](const int &x) { return s[x]; }
} to, from;
bool dfs(int now, bool A, bool B)
{
    if (now == (int)t.size())
        return true;
    if (to[t[now]])
    {
        if ((!A && to[t[now]] < a[now]) || (!B && to[t[now]] > b[now]))
            return false;
        else
            return dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]);
    }
    if (A)
    {
        if (B)
        {
            for (char i = 'a'; i < 'a' + k; ++i)
                if (!from[i])
                {
                    from[i] = t[now];
                    to[t[now]] = i;
                    if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                        return true;
                    to[t[now]] = 0;
                    from[i] = 0;
                }
        }
        else
        {
            for (char i = 'a'; i < b[now]; ++i)
                if (!from[i])
                {
                    from[i] = t[now];
                    to[t[now]] = i;
                    if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                        return true;
                    to[t[now]] = 0;
                    from[i] = 0;
                }
            if (!from[b[now]])
            {
                from[b[now]] = t[now];
                to[t[now]] = b[now];
                if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                    return true;
                to[t[now]] = 0;
                from[b[now]] = 0;
            }
        }
    }
    else
    {
        if (B)
        {
            for (char i = a[now]; i < 'a' + k; ++i)
                if (!from[i])
                {
                    from[i] = t[now];
                    to[t[now]] = i;
                    if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                        return true;
                    to[t[now]] = 0;
                    from[i] = 0;
                }
            if (!from[a[now]])
            {
                from[a[now]] = t[now];
                to[t[now]] = a[now];
                if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                    return true;
                to[t[now]] = 0;
                from[a[now]] = 0;
            }
        }
        else
        {
            for (char i = a[now] + 1; i < b[now]; ++i)
                if (!from[i])
                {
                    from[i] = t[now];
                    to[t[now]] = i;
                    if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                        return true;
                    to[t[now]] = 0;
                    from[i] = 0;
                }
            if (!from[a[now]])
            {
                from[a[now]] = t[now];
                to[t[now]] = a[now];
                if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                    return true;
                to[t[now]] = 0;
                from[a[now]] = 0;
            }
            if (!from[b[now]])
            {
                from[b[now]] = t[now];
                to[t[now]] = b[now];
                if (dfs(now + 1, A || a[now] < to[t[now]], B || to[t[now]] < b[now]))
                    return true;
                to[t[now]] = 0;
                from[b[now]] = 0;
            }
        }
    }
    return false;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> T;
    while (T--)
    {
        std::cin >> k >> t >> a >> b;
        memset(to.s, 0, sizeof(to.s));
        memset(from.s, 0, sizeof(from.s));
        if (dfs(0, false, false))
        {
            std::cout << "YES\n";
            for (char i = 'a', j = 'a'; i < 'a' + k; ++i)
                if (!from[i])
                {
                    while (to[j])
                        ++j;
                    from[i] = j;
                    to[j] = i;
                }
            for (int i = 'a'; i < 'a' + k; ++i)
                std::cout << to[i];
            std::cout << '\n';
        }
        else
            std::cout << "NO\n";
    }
    return 0;
}