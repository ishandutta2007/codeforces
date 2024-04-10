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
std::vector<int> app;
int T, n, m, sum[800005], ans, cnt;
struct seg
{
    int l, r;
} s[200005];
std::vector<int> L, R;
bool checkall()
{
    for (int i = 2; i <= n; ++i)
        if (s[i - 1].r >= s[i].l)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        app.clear();
        L.clear();
        R.clear();
        ans = 0;
        cnt = 0;
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> s[i].l >> s[i].r;
        std::sort(s + 1, s + 1 + n, [&](const seg &A, const seg &B)
                  { return A.l == B.l ? A.r < B.r : A.l < B.l; });
        if (checkall())
        {
            std::cout << n - 1 << std::endl;
            continue;
        }
        for (int i = 1; i <= n; ++i)
            app.push_back(s[i].l), app.push_back(s[i].r);
        std::sort(app.begin(), app.end());
        app.erase(std::unique(app.begin(), app.end()), app.end());
        m = app.size() * 2 + 2;
        std::fill(sum, sum + m + 1, 0);
        for (int i = 1; i <= n; ++i)
            s[i].l = (std::lower_bound(app.begin(), app.end(), s[i].l) - app.begin() + 1) * 2,
            s[i].r = (std::lower_bound(app.begin(), app.end(), s[i].r) - app.begin() + 1) * 2;
        for (int i = 1; i <= n; ++i)
            ++sum[s[i].l], --sum[s[i].r + 1];
        for (int i = 1; i <= m; ++i)
            sum[i] += sum[i - 1];
        for (int i = 0; i <= m; ++i)
            if (sum[i] == 1)
            {
                int j = i;
                while (sum[j] == 1)
                    ++j;
                --j;
                if (sum[i - 1] != 0 && sum[j + 1] != 0)
                    L.push_back(i), R.push_back(j);
                i = j;
            }
            else if (sum[i] == 0)
            {
                int j = i;
                while (sum[j] == 0)
                    ++j;
                --j;
                ++cnt;
                i = j;
            }
        for (int i = 1; i <= n; ++i)
            ans = std::max(ans, (int)((std::lower_bound(L.begin(), L.end(), s[i].r) - L.begin()) -
                                      (std::upper_bound(R.begin(), R.end(), s[i].l) - R.begin())));
        std::cout << cnt - 1 + ans << std::endl;
    }
    return 0;
}