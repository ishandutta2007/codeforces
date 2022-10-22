// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, q, ans;
char a[100005];
bool check(int x) { return 1 <= x && x + 2 <= n && a[x] == 'a' && a[x + 1] == 'b' && a[x + 2] == 'c'; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    a[n + 1] = 0;
    ans = 0;
    for (int i = 1; i <= n - 2; ++i)
        ans += check(i);
    for (int i = 1; i <= q; ++i)
    {
        static int x;
        static char y;
        std::cin >> x >> y;
        ans -= check(x);
        ans -= check(x - 1);
        ans -= check(x - 2);
        a[x] = y;
        ans += check(x);
        ans += check(x - 1);
        ans += check(x - 2);
        std::cout << ans << std::endl;
    }
    return 0;
}