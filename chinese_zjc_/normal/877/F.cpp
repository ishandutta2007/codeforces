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
const int BLOCK = 300;
int n, k, q, x[200005], y[200005], s[200005], res, ans[200005], sum1[400005], sum2[400005];
struct query
{
    int l, r, p;
    friend bool operator<(const query &A, const query &B)
    {
        return A.l / BLOCK == B.l / BLOCK ? A.r < B.r : A.l < B.l;
    }
} a[200005];
std::vector<int> app;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i];
    for (int i = 1; i <= n; ++i)
        std::cin >> y[i];
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + (x[i] == 2 ? -y[i] : y[i]);
    for (int i = 0; i <= n; ++i)
        app.push_back(s[i] + k), app.push_back(s[i]);
    std::sort(app.begin(), app.end());
    for (int i = 0; i <= n; ++i)
        x[i] = std::lower_bound(app.begin(), app.end(), s[i] + k) - app.begin(),
        y[i] = std::lower_bound(app.begin(), app.end(), s[i]) - app.begin();
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
        std::cin >> a[i].l >> a[i].r, --a[i].l, ++a[i].r, a[i].p = i;
    std::sort(a + 1, a + 1 + q);
    for (int i = 1, l = 1, r = 1; i <= q; ++i)
    {
        while (r < a[i].r)
        {
            res += sum1[y[r]];
            ++sum1[x[r]];
            ++sum2[y[r]];
            ++r;
        }
        while (r > a[i].r)
        {
            --r;
            --sum1[x[r]];
            --sum2[y[r]];
            res -= sum1[y[r]];
        }
        while (l < a[i].l)
        {
            --sum1[x[l]];
            --sum2[y[l]];
            res -= sum2[x[l++]];
        }
        while (l > a[i].l)
        {
            res += sum2[x[--l]];
            ++sum1[x[l]];
            ++sum2[y[l]];
        }
        ans[a[i].p] = res;
        // std::cout << a[i].l << ' ' << a[i].r << std::endl;
        // std::cout << l << ' ' << r << std::endl;
        // std::cout << sum1[s[0]] << std::endl;
    }
    for (int i = 1; i <= q; ++i)
        std::cout << ans[i] << std::endl;
    return 0;
}