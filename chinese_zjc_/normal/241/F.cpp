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
const int xx[] = {0, +1, 0, -1},
          yy[] = {+1, 0, -1, 0};
int n, m, k, sx, sy, ex, ey, nxt, tim;
std::string s;
std::pair<int, int> pos[26];
char c[105][105];
int find_side(int dx, int dy)
{
    if (dx)
        return dx < 0 ? 3 : 1;
    if (dy)
        return dy < 0 ? 2 : 0;
    return -1;
}
void move(int side, int time)
{
    tim += time;
    if (tim > k)
        std::cout << sx << ' ' << sy << std::endl, exit(0);
    if (~side)
    {
        sx += xx[side];
        sy += yy[side];
    }
}
void go(int side)
{
    while (!('a' <= c[sx][sy] && c[sx][sy] <= 'z'))
        move(side, c[sx][sy] - '0');
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if ('a' <= c[i][j] && c[i][j] <= 'z')
                pos[c[i][j] - 'a'] = {i, j};
    std::cin >> sx >> sy >> s >> ex >> ey;
    {
        int to = find_side(pos[s[nxt] - 'a'].first - sx, pos[s[nxt] - 'a'].second - sy);
        go(to);
        ++nxt;
    }
    while (nxt != (int)s.size())
    {
        int to = find_side(pos[s[nxt] - 'a'].first - sx, pos[s[nxt] - 'a'].second - sy);
        // std::cout << nxt << ' ' << sx << ' ' << sy << ' ' << c[sx][sy] << std::endl;
        move(to, 1);
        go(to);
        ++nxt;
    }
    {
        int to = find_side(ex - sx, ey - sy);
        move(to, 1);
        c[ex][ey] = 'a';
        go(to);
    }
    move(0, 114514);
    return 0;
}