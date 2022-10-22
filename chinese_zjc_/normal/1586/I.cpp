// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n;
char c[2005][2005], d[2005][2005], e[2005];
void myassert(bool condition) { condition ? std::cout << "NONE" << std::endl, exit(0) : void(); }
void update(char &x, char y) { myassert(x && x != y), x = y; }
void work(int x, int y, char z)
{
    if (y == 0)
        return update(e[x / 2], z);
    if (x + y >= n)
        return work(n - y - 1, n - x - 1, z);
    if (y > x)
        return work(y, x, z);
    if ((x + y) & 1)
        return work(x - y, y - y, z ^ (y & 1 ? 'S' ^ 'G' : 0));
    else
        return work(x + y, y - y, z ^ (y & 1 ? 'S' ^ 'G' : 0));
}
char get(int x, int y)
{
    if (y == 0)
        return e[x / 2];
    if (x + y >= n)
        return get(n - y - 1, n - x - 1);
    if (y > x)
        return get(y, x);
    if ((x + y) & 1)
        return get(x - y, y - y) ^ (y & 1 ? 'S' ^ 'G' : 0);
    else
        return get(x + y, y - y) ^ (y & 1 ? 'S' ^ 'G' : 0);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    if (n & 1)
        return std::cout << "NONE" << std::endl, 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            std::cin >> c[i][j];
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (c[i][j] != '.')
                work(i, j, c[i][j]);
    for (int i = 0; i != n / 2; ++i)
        if (!e[i])
            return std::cout << "MULTIPLE" << std::endl, 0;
    std::cout << "UNIQUE" << std::endl;
    for (int i = 0; i != n; ++i, std::cout << std::endl)
        for (int j = 0; j != n; ++j)
            std::cout << get(i, j);
    return 0;
}