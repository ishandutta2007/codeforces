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
int n, m, sum;
std::set<std::pair<int, int>> s[200005];
/*
void add(int pos, int val)
{
    while (pos <= m)
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
*/
void insert(std::set<std::pair<int, int>> &A, std::pair<int, int> B)
{
    std::set<std::pair<int, int>>::iterator i = A.lower_bound(B);
    if (i != A.end() && B.second == i->first)
    {
        B.second = i->second;
        A.erase(i++);
    }
    if (i != A.begin())
    {
        if ((--i)->second == B.first)
        {
            B.first = i->first;
            A.erase(i++);
        }
        else
            ++i;
    }
    A.insert(i, B);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        static int x;
        std::cin >> x;
        insert(s[x], std::make_pair(i, i + 1));
    }
    for (int i = 1; i <= m; ++i)
        sum += s[i].size();
    std::cout << sum - 1 << std::endl;
    for (int i = 1; i < m; ++i)
    {
        static int x, y;
        std::cin >> x >> y;
        sum -= s[x].size() + s[y].size();
        if (s[x].size() < s[y].size())
            s[x].swap(s[y]);
        while (!s[y].empty())
        {
            insert(s[x], *s[y].begin());
            s[y].erase(s[y].begin());
        }
        sum += s[x].size();
        std::cout << sum - 1 << std::endl;
    }
    return 0;
}