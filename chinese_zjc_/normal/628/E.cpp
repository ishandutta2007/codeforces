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
int n, m, ans, tr[3005][3005], tl[3005][3005], td[3005][3005], sum[3005], x;
char c[3005][3005];
void add(int pos, int val)
{
    while (pos <= n)
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
struct cmp
{
    bool operator()(const int &A, const int &B) { return tr[A][x - A] > tr[B][x - B]; }
};
std::priority_queue<int, std::vector<int>, cmp> que;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            std::cin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1, lst = 0; j <= m; ++j)
            if (c[i][j] == '.')
                lst = j;
            else
                tl[i][j] = lst + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = m, lst = m + 1; j; --j)
            if (c[i][j] == '.')
                lst = j;
            else
                tr[i][j] = lst - 1;
    for (int i = 2; i <= n + m; ++i)
        for (int j = std::min(i - 1, n), lst = j + 1; j >= 1 && i - j <= m; --j)
            if (c[j][i - j] == '.')
                lst = j;
            else
                td[j][i - j] = lst - 1;
    for (int i = 2; i <= n + m && (x = i); ++i)
    {
        while (!que.empty())
            add(que.top(), -1), que.pop();
        x = i;
        for (int j = std::min(i - 1, n); j >= 1 && i - j <= m; --j)
        {
            que.push(j);
            add(j, 1);
            while (!que.empty() && tr[que.top()][i - que.top()] < i - j)
                add(que.top(), -1), que.pop();
            ans += query(std::min(j + (i - j - tl[j][i - j]), td[j][i - j]));
            // for (int k = 1; k <= n; ++k)
            //     std::cout << query(k) - query(k - 1) << " \n"[k == n];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}