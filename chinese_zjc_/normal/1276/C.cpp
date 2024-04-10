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
int n, a[400005], A, B, tot;
std::vector<std::vector<int>> ans;
std::map<int, int> c;
std::vector<std::pair<int, int>> d;
void work(int i, int j, std::vector<std::pair<int, int>>::iterator now)
{
    if (tot == A * B)
        return;
    if (ans[i][j])
        return work((i + 1) % A, j, now);
    ans[i][j] = now->second;
    ++tot;
    --now->first;
    if (!now->first)
        ++now;
    return work((i + 1) % A, (j + 1) % B, now);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        ++c[a[i]];
    }
    for (auto i : c)
        d.push_back(std::make_pair(i.second, i.first));
    std::sort(d.begin(), d.end(), std::greater<std::pair<int, int>>());
    for (int i = 1, cnt = 0; i <= n; ++i)
    {
        for (std::map<int, int>::iterator j = c.begin(); j != c.end();)
        {
            --j->second;
            ++cnt;
            if (!j->second)
                c.erase(j++);
            else
                ++j;
        }
        if (i * i <= cnt && cnt / i * i > A * B)
        {
            A = i;
            B = cnt / i;
        }
    }
    for (std::vector<std::pair<int, int>>::iterator i = d.begin(); i != d.end(); ++i)
        i->first = std::min(A, i->first);
    std::cout << A * B << std::endl
              << A << ' ' << B << std::endl;
    ans.assign(A, std::vector<int>(B));
    work(0, 0, d.begin());
    for (auto i : ans)
    {
        for (auto j : i)
            std::cout << j << ' ';
        std::cout << std::endl;
    }
    return 0;
}