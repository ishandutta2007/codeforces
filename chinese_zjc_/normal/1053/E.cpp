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
int n, a[1000005], lst[1000005], nxt[1000005];
std::vector<int> app[1000005];
bool used[1000005], deleted[1000005];
int mex()
{
    static int cnt = 1;
    while (used[cnt])
        ++cnt;
    used[cnt] = true;
    return cnt;
}
void Fail()
{
    std::cout << "no" << std::endl;
    exit(0);
}
void del(int L, int R)
{
    nxt[L] = R;
    lst[R] = L;
}
void work(int L, int R)
{
    if (a[L] && a[R] && a[L] != a[R])
        Fail();
    if (a[L] && !a[R])
    {
        a[R] = a[L];
        app[a[R]].push_back(R);
    }
    if (a[R] && !a[L])
    {
        a[L] = a[R];
    }
    if (a[L])
        for (std::vector<int>::iterator i = std::upper_bound(app[a[L]].begin(), app[a[L]].end(), L); *i != R; ++i)
        {
            work(L, *i);
            del(lst[L], *i);
            L = *i;
        }
    for (int i = nxt[L]; i <= lst[R]; i = nxt[i])
    {
        if (a[i])
        {
            if (*app[a[i]].begin() < L || *app[a[i]].rbegin() > R)
                Fail();
            for (std::vector<int>::iterator j = ++app[a[i]].begin(); j != app[a[i]].end(); ++j)
            {
                work(i, *j);
                del(lst[i], *j);
                i = *j;
            }
        }
    }
    int nums = 0, vals = 0;
    for (int i = L; i <= R; i = nxt[i])
    {
        ++nums;
        if (a[i])
            ++vals;
    }
    if (a[L] && a[R])
        --vals;
#ifdef debug
    std::cout << L << " " << R << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << " \n"[i == n];
    std::cout << nums << ' ' << vals << std::endl;
#endif
    if (nums % 2 != 1)
        Fail();
    int adds = (nums + 1) / 2 - vals;
    if (adds < 0)
        Fail();
    for (int i = L; i <= R; i = nxt[i])
    {
        if (!a[i] && adds)
        {
            a[i] = mex();
            --adds;
        }
    }
    for (int i = L; i <= R; i = nxt[i])
    {
        while (!a[i] && lst[lst[i]] >= L && a[lst[lst[i]]] && a[lst[i]])
        {
            a[i] = a[lst[lst[i]]];
            del(lst[lst[i]], nxt[i]);
        }
        while (!a[i] && nxt[nxt[i]] <= R && a[nxt[nxt[i]]] && a[nxt[i]])
        {
            a[i] = a[nxt[nxt[i]]];
            del(lst[i], nxt[nxt[i]]);
            i = std::max(L, lst[lst[i]]);
        }
    }
    if (!a[L] && !a[R])
        a[L] = a[R] = mex();
    for (int i = L; i <= R; i = nxt[i])
        if (!a[i])
            a[i] = a[L];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    if (n == 1)
        return std::cout << "yes" << std::endl
                         << 1 << std::endl,
               0;
    n = n + n - 1;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
        used[a[i]] = true;
    for (int i = 1; i <= n + 1; ++i)
        lst[i] = i - 1;
    for (int i = 0; i <= n; ++i)
        nxt[i] = i + 1;
    for (int i = 1; i <= n; ++i)
        app[a[i]].push_back(i);
    work(1, n);
    std::cout << "yes" << std::endl;
    for (int i = 1; i <= n; ++i)
        std::cout << a[i] << " \n"[i == n];
    return 0;
}