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
int n, m, down[2005][2005], right[2005][2005], left[2005][2005], up[2005][2005], ans, sum[2005];
char c[2005][2005];
std::priority_queue<std::pair<int, int>> que;
void add(int pos, int val)
{
    while (pos <= 2000)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
int query(int l, int r)
{
    if (l > r)
        return 0;
    return query(r) - query(l - 1);
}
void clear()
{
    memset(sum, 0, sizeof(sum));
    while (!que.empty())
        que.pop();
}
signed main()
{
    std::ios::sync_with_stdio(false);
    // ! input
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    // ! init
    // * down
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            down[i][j] = c[i + 1][j] == '.' && c[i][j] == '.' ? down[i + 1][j] : i;
    // * right
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= 1; --j)
            right[i][j] = c[i][j + 1] == '.' && c[i][j] == '.' ? right[i][j + 1] : j;
    // * left
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            left[i][j] = c[i][j - 1] == '.' && c[i][j] == '.' ? left[i][j - 1] : j;
    // * up
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            up[i][j] = c[i - 1][j] == '.' && c[i][j] == '.' ? up[i - 1][j] : i;
    // ! calc
    // * #1
    // * .....
    // * ..***
    // * ..*..
    // * ***..
    // * .....
    for (int i = 2; i < n; ++i)
    {
        for (int j = 2; j <= right[i][1] && j < m; ++j)
            que.push({-up[i][j], j});
        for (int j = 2; j < i; ++j)
        {
            while (!que.empty() && -que.top().first <= j)
                add(que.top().second, 1), que.pop();
            ans += query(left[j][m], m - 1);
        }
        clear();
        ans += right[i][1] == m;
        for (int j = 2; j <= right[i][1] && j < m; ++j)
            que.push({+down[i][j], j});
        for (int j = n - 1; j > i; --j)
        {
            while (!que.empty() && +que.top().first >= j)
                add(que.top().second, 1), que.pop();
            ans += query(left[j][m], m - 1);
        }
        clear();
    }
    // * #2
    // * ...*.
    // * ...*.
    // * .***.
    // * .*...
    // * .*...
    for (int i = 2; i < m; ++i)
    {
        for (int j = 2; j <= down[1][i] && j < n; ++j)
            que.push({-left[j][i], j});
        for (int j = 2; j < i; ++j)
        {
            while (!que.empty() && -que.top().first <= j)
                add(que.top().second, 1), que.pop();
            ans += query(up[n][j], n - 1);
        }
        clear();
        ans += down[1][i] == n;
        for (int j = 2; j <= down[1][i] && j < n; ++j)
            que.push({+right[j][i], j});
        for (int j = m - 1; j > i; --j)
        {
            while (!que.empty() && +que.top().first >= j)
                add(que.top().second, 1), que.pop();
            ans += query(up[n][j], n - 1);
        }
        clear();
    }
    // * #3
    // * ..*..
    // * ..*..
    // * ***..
    // * .....
    // * .....
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j)
            ans += left[i][j] == 1 && up[i][j] == 1;
    // * #4
    // * ..*..
    // * ..*..
    // * ..***
    // * .....
    // * .....
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j)
            ans += right[i][j] == m && up[i][j] == 1;
    // * #5
    // * .....
    // * .....
    // * ..***
    // * ..*..
    // * ..*..
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j)
            ans += right[i][j] == m && down[i][j] == n;
    // * #6
    // * .....
    // * .....
    // * ***..
    // * ..*..
    // * ..*..
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < m; ++j)
            ans += left[i][j] == 1 && down[i][j] == n;
    // * #7
    // * .....
    // * ***..
    // * ..*..
    // * ***..
    // * .....
    for (int i = 2; i < n; ++i)
    {
        for (int j = 2; j <= right[i][1] && j < m; ++j)
            que.push({down[i][j], j});
        for (int j = n - 1; j - i > 1; --j)
        {
            while (!que.empty() && que.top().first >= j)
                add(que.top().second, 1), que.pop();
            ans += query(2, right[j][1]);
        }
        clear();
    }
    // * #8
    // * .*.*.
    // * .*.*.
    // * .***.
    // * .....
    // * .....
    for (int i = 2; i < m; ++i)
    {
        for (int j = 2; j <= down[1][i] && j < n; ++j)
            que.push({right[j][i], j});
        for (int j = m - 1; j - i > 1; --j)
        {
            while (!que.empty() && que.top().first >= j)
                add(que.top().second, 1), que.pop();
            ans += query(2, down[1][j]);
        }
        clear();
    }
    // * #9
    // * .....
    // * ..***
    // * ..*..
    // * ..***
    // * .....
    for (int i = 2; i < n; ++i)
    {
        for (int j = m - 1; j >= left[i][m] && j > 1; --j)
            que.push({down[i][j], j});
        for (int j = n - 1; j - i > 1; --j)
        {
            while (!que.empty() && que.top().first >= j)
                add(que.top().second, 1), que.pop();
            ans += query(left[j][m], m - 1);
        }
        clear();
    }
    // std::cout << ans << std::endl;
    // * #10
    // * .....
    // * .....
    // * .***.
    // * .*.*.
    // * .*.*.
    for (int i = 2; i < m; ++i)
    {
        for (int j = n - 1; j >= up[n][i] && j > 1; --j)
            que.push({right[j][i], j});
        for (int j = m - 1; j - i > 1; --j)
        {
            while (!que.empty() && que.top().first >= j)
                add(que.top().second, 1), que.pop();
            ans += query(up[n][j], n - 1);
        }
        clear();
    }
    std::cout << ans << std::endl;
    return 0;
}