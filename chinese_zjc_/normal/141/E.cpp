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
int n, m, faS[100005], faM[100005], fa[100005], a[100005], b[100005], lim;
std::vector<int> S, M;
std::set<int> choS, choM;
int find(int now, int *F) { return now == F[now] ? now : F[now] = find(F[now], F); }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    if (n % 2 == 0)
        return std::cout << -1 << std::endl, 0;
    lim = (n - 1) / 2;
    for (int i = 1; i <= m; ++i)
    {
        char c;
        std::cin >> a[i] >> b[i] >> c;
        if (c == 'S')
            S.push_back(i);
        else
            M.push_back(i);
    }
    for (int i = 1; i <= n; ++i)
        fa[i] = faS[i] = faM[i] = i;
    for (auto i : S)
        if (find(a[i], fa) != find(b[i], fa))
        {
            fa[find(a[i], fa)] = find(b[i], fa);
            faS[find(a[i], faS)] = find(b[i], faS);
            choS.insert(i);
        }
    if ((int)choS.size() < lim)
        return std::cout << -1 << std::endl, 0;
    for (auto i : M)
        if (find(a[i], fa) != find(b[i], fa))
        {
            fa[find(a[i], fa)] = find(b[i], fa);
            faM[find(a[i], faM)] = find(b[i], faM);
            choM.insert(i);
        }
    for (auto i : M)
        if ((int)choM.size() < lim && find(a[i], faM) != find(b[i], faM))
        {
            faM[find(a[i], faM)] = find(b[i], faM);
            choM.insert(i);
        }
    if ((int)choM.size() < lim)
        return std::cout << -1 << std::endl, 0;
    for (int i = 1; i <= n; ++i)
        fa[i] = faS[i] = i;
    choS.clear();
    for (auto i : choM)
        fa[find(a[i], fa)] = find(b[i], fa);
    for (auto i : S)
        if (find(a[i], fa) != find(b[i], fa))
        {
            fa[find(a[i], fa)] = find(b[i], fa);
            faS[find(a[i], faS)] = find(b[i], faS);
            choS.insert(i);
        }
    std::cout << choS.size() + choM.size() << std::endl;
    for (auto i : choS)
        std::cout << i << ' ';
    for (auto i : choM)
        std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}