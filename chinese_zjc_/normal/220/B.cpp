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
// #include<windows.h>
// #define debug
#define int long long
#define double long double
#define subtask_work(a) a::check() ? a::solve(), exit(0) : void(0)
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, m, a[200005], ton[200005], ans;
struct query
{
    int l, r, p, ans;
    bool operator<(const query &__Val) const
    {
        return l / 400 == __Val.l / 400 ? r < __Val.r : l < __Val.l;
    }
} b[200005];
void add(int now)
{
    if (ton[a[now]] == a[now])
    {
        --ans;
    }
    ++ton[a[now]];
    if (ton[a[now]] == a[now])
    {
        ++ans;
    }
}
void del(int now)
{
    if (ton[a[now]] == a[now])
    {
        --ans;
    }
    --ton[a[now]];
    if (ton[a[now]] == a[now])
    {
        ++ans;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > n)
        {
            a[i] = n + 1;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i].l >> b[i].r;
        b[i].p = i;
        ++b[i].r;
    }
    sort(b + 1, b + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = b[i - 1].l; j < b[i].l; ++j)
        {
            del(j);
        }
        for (int j = b[i].l; j < b[i - 1].l; ++j)
        {
            add(j);
        }
        for (int j = b[i].r; j < b[i - 1].r; ++j)
        {
            del(j);
        }
        for (int j = b[i - 1].r; j < b[i].r; ++j)
        {
            add(j);
        }
        b[i].ans = ans;
    }
    sort(b + 1, b + 1 + m, [&](const query &A, const query &B) { return A.p < B.p; });
    for (int i = 1; i <= m; ++i)
    {
        cout << b[i].ans << endl;
    }
    return 0;
}