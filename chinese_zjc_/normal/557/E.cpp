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
int n;
char c[5005];
unsigned son[5005 * 5005 / 2][2], siz[5005 * 5005 / 2], root, cnt;
bool OK[5005][5005];
void insert(int l, int r, int now)
{
    if (!son[now][c[r] - 'a'])
        son[now][c[r] - 'a'] = ++cnt;
    if (OK[l][r])
        ++siz[son[now][c[r] - 'a']];
    if (r != n)
        insert(l, r + 1, son[now][c[r] - 'a']);
}
void init(int now)
{
    for (int i = 0; i != 2; ++i)
        if (son[now][i])
            init(son[now][i]), siz[now] += siz[son[now][i]];
}
void print(int now, int left)
{
    if (left <= siz[now] - siz[son[now][0]] - siz[son[now][1]])
        return;
    left -= siz[now] - siz[son[now][0]] - siz[son[now][1]];
    if (left <= siz[son[now][0]])
        std::cout << 'a', print(son[now][0], left);
    else
        std::cout << 'b', print(son[now][1], left - siz[son[now][0]]);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> (c + 1);
    n = strlen(c + 1);
    for (int i = 1; i <= n; ++i)
    {
        bool good[2];
        good[0] = good[1] = true;
        for (int len = 0; i - len >= 1 && i + len <= n; ++len)
            if (good[len & 1] &= c[i - len] == c[i + len])
                OK[i - len][i + len] = true;
        good[0] = good[1] = true;
        for (int len = 0; i - len >= 1 && i + len + 1 <= n; ++len)
            if (good[len & 1] &= c[i - len] == c[i + len + 1])
                OK[i - len][i + len + 1] = true;
    }
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= i; ++j)
    //         std::cout << OK[j][i] << " \n"[j == i];
    root = ++cnt;
    for (int i = 1; i <= n; ++i)
        insert(i, i, root);
    init(root);
    std::cin >> n;
    print(root, n);
    return 0;
}