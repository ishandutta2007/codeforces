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
const char l[8] = {'1', '2', '3', '4', '5', '6', '7', '8'},
           c[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
const int xx[] = {+1, +2, +2, +1, -1, -2, -2, -1},
          yy[] = {+2, +1, -1, -2, -2, -1, +1, +2};
int h[8][8];
int n, from[8][8];
int cnt;
std::stringstream res;
void print(int sx, int sy, int tx, int ty)
{
    ++cnt;
    res << c[sx] << l[sy] << '-' << c[tx] << l[ty] << std::endl;
    std::swap(h[sx][sy], h[tx][ty]);
}
void make(bool mode, int x, int y)
{
    // std::cout << "make " << x << ' ' << y << std::endl;
    if (from[x][y] == 8)
        return;
    if (mode)
        print(x, y, x - xx[from[x][y]], y - yy[from[x][y]]);
    if (!mode)
        print(x - xx[from[x][y]], y - yy[from[x][y]], x, y);
    make(mode, x - xx[from[x][y]], y - yy[from[x][y]]);
}
void work(bool d, int x, int y)
{
    // std::cout << x << ' ' << y << std::endl;
    std::queue<std::pair<int, int>> que;
    que.push({x, y});
    memset(from, -1, sizeof(from));
    from[x][y] = 8;
    while (!que.empty())
    {
        std::pair<int, int> now = que.front();
        que.pop();
        // std::cout << "NOW " << now.first << ' ' << now.second << std::endl;
        if (!~h[now.first][now.second])
            continue;
        if (h[now.first][now.second] == d)
            return make(d, now.first, now.second);
        for (int i = 0; i != 8; ++i)
            if (now.first + xx[i] >= 0 && now.first + xx[i] < 8 &&
                now.second + yy[i] >= 0 && now.second + yy[i] < 8 &&
                !~from[now.first + xx[i]][now.second + yy[i]])
            {
                from[now.first + xx[i]][now.second + yy[i]] = i;
                que.push({now.first + xx[i], now.second + yy[i]});
            }
    }
    // for (int i = 0; i != 8; ++i)
    //     for (int j = 0; j != 8; ++j)
    //         std::cout << from[i][j] << " \n"[j + 1 == 8];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 0; i != n; ++i)
    {
        char s[2];
        std::cin >> s[0] >> s[1];
        h[s[0] - 'a'][s[1] - '1'] = 1;
    }
    if (n <= 32)
        for (int i = 0; i != n; ++i)
            work(true, i & 7, i >> 3), h[i & 7][i >> 3] = -1;
    else
        for (int i = 0; i != 64 - n; ++i)
            work(false, 7 - (i & 7), 7 - (i >> 3)), h[7 - (i & 7)][7 - (i >> 3)] = -1;
    std::cout << cnt << std::endl
              << res.str();
    return 0;
}